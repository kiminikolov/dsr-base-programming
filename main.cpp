#include <iostream>
#define pass (void)0
using namespace std;


const unsigned short MAX_ESTATE_COUNT = 100;
unsigned short estate_count = 0;


struct Estate {
    char reference_number[50];
    char broker_name[50];
    char estate_type[50];
    char estate_location[50];
    char exposure[50];
    double price;
    double total_area;
    int room_count;
    int floor;
    char status[50];
};

void print_estate_info(Estate estate) {
    cout << "№" << estate.reference_number
         << " Брокер: " << estate.broker_name
         << " Тип: " << estate.estate_type
         << " Локация: " << estate.estate_location
         << " Изложение: " << estate.exposure
         << " Цена: " << estate.price
         << " Площ: " << estate.total_area
         << " Стаи: " << estate.room_count
         << " Етаж: " << estate.floor
         << " Статус: " << estate.status
         << endl;
}


// Прототипи на функциите
void print_starting_menu();

void add_one_new_estate();
void add_list_of_estate();

void print_all_estate();

int print_highest_area_estate();
int print_sold_estate();

void sort_estate_array();

void export_estate_array_to_file();
void import_estate_array_from_file();


Estate estates_array[MAX_ESTATE_COUNT];


int main() {
    print_starting_menu();

    int user_input;
    cin >> user_input;

    while (user_input != 0) {
        switch (user_input) {
            case 1:
                cout << "Изберете опция." << endl;
                cout << "[0] Затваряне на програмата" << endl;
                cout << "[1] Добавяне на един нов имот" << endl;
                cout << "[2] Добавяне на списък с имоти" << endl;
                cin >> user_input;

                switch (user_input) {
                    case 1:
                        add_one_new_estate();
                        break;
                    case 2:
                        add_list_of_estate();
                        break;
                    default:
                        cout << "Въведете валидна команда." << endl;
                }
                break;
            case 2:
                print_all_estate();
                break;
            case 3:
                cout << "Изберете опция." << endl;
                cout << "[0] Затваряне на програмата" << endl;
                cout << "[1] Извеждане на имоти с най-голяма площ" << endl;
                cout << "[2] Извеждане на продадени имоти" << endl;

                cin >> user_input;

                switch (user_input) {
                    case 1:
                        print_highest_area_estate();
                        break;
                    case 2:
                        print_sold_estate();
                        break;
                    default:
                        cout << "Въведете валидна команда." << endl;
                }
                break;
            case 4:
                sort_estate_array();
                break;
            case 5:
                cout << "Изберете опция." << endl;
                cout << "[0] Затваряне на програмата" << endl;
                cout << "[1] Извеждане на масива с имоти във файл (двоичен)" << endl;
                cout << "[2] Въвеждане на масива с имоти от файл (двоичен)" << endl;

                cin >> user_input;

                switch (user_input) {
                    case 0:
                        return 0;
                    case 1:
                        export_estate_array_to_file();
                        break;
                    case 2:
                        import_estate_array_from_file();
                        break;
                    default:
                        cout << "Въведете валидна команда." << endl;
                }

            default:
                cout << "Въведете валидна команда." << endl;
        }
        print_starting_menu();
        cin >> user_input;
    }

    return 0;
}


// Декларация на функциите
void print_starting_menu() {
    cout << "\t\t\tАгенция за недвижими имоти\t\t\t" << endl;
    cout << "[0] Затваряне на програмата" << endl;
    cout << "[1] Добавяне на нов имот" << endl;
    cout << "[2] Извеждане на екрана" << endl;
    cout << "[3] Търсене и извеждане на екрана" << endl;
    cout << "[4] Подреждане на основния масив с имоти, без да се извежда на екрана" << endl;
    cout << "[5] Управление на файл" << endl;
}


Estate create_estate() {
    Estate new_estate = {};

    cin.ignore();
    cout << "Референтен номер: " << endl;
    cin.getline(new_estate.reference_number, sizeof(new_estate.reference_number));
    cout << "Брокер: " << endl;
    cin.getline(new_estate.broker_name, sizeof(new_estate.broker_name));
    cout << "Тип: " << endl;
    cin.getline(new_estate.estate_type, sizeof(new_estate.estate_type));
    cout << "Локация: " << endl;
    cin.getline(new_estate.estate_location, sizeof(new_estate.estate_location));
    cout << "Изложение: " << endl;
    cin.getline(new_estate.exposure, sizeof(new_estate.exposure));
    cout << "Цена: " << endl;
    cin >> new_estate.price;
    cout << "Площ: " << endl;
    cin >> new_estate.total_area;
    cout << "Брой стаи: " << endl;
    cin >> new_estate.room_count;
    cout << "Етаж: " << endl;
    cin >> new_estate.floor;
    cin.ignore();
    cout << "Статус: " << endl;
    cin.getline(new_estate.status, sizeof(new_estate.status));

    return new_estate;
}


void add_one_new_estate() {
    const Estate new_estate = create_estate();

    estates_array[estate_count] = new_estate;
    estate_count++;
}


void add_list_of_estate() {
    int n;

    do {
        cout << "Въведете броя на имоти, които искате да добавите: " << endl;
        cin >> n;

        if (estate_count == MAX_ESTATE_COUNT || estate_count + n > MAX_ESTATE_COUNT) {
            cout << "Броят на имотите не трябва да надвишава 100!" << endl;
        }
    } while (estate_count == MAX_ESTATE_COUNT || estate_count + n > MAX_ESTATE_COUNT);

    for (int i = 1; i <= n; i++) {
        add_one_new_estate();
    }
}


void print_all_estate() {
    cout << "\t\t\tСписък с имоти:\t\t\t" << endl;

    for (int i = 0; i < estate_count; i++) {
        Estate current_estate = estates_array[i];
        cout << "№" << current_estate.reference_number << " Брокер:" << current_estate.broker_name << " Тип:" << current_estate.estate_type << " Локация:" << current_estate.estate_location << " Изложение:" << current_estate.exposure << " Цена:" << current_estate.price << " Площ:" << current_estate.total_area << " Стаи:" << current_estate.room_count << " Етаж:" << current_estate.floor << " Статус:" << current_estate.status << endl;
    }
    cout << endl;
}


int print_highest_area_estate() {
    if (estate_count == 0) {
        cout << "Няма въведени имоти." << endl;
        return 0;
    }

    int max_index = 0;

    for (int i = 1; i < estate_count; i++) {
        if (estates_array[i].total_area > estates_array[max_index].total_area) {
            max_index = i;
        }
    }

    Estate highest_area_estate = estates_array[max_index];

    cout << "Имотът с най-голяма площ:" << endl;
    print_estate_info(highest_area_estate);
    return 0;
}


int print_sold_estate() {
    if (estate_count == 0) {
        cout << "Няма въведени имоти." << endl;
        return 0;
    }

    bool sold_estate = false;

    for (int i = 0; i < estate_count; i++) {
        if (strcmp(estates_array[i].status, "Продаден") == 0) {
            sold_estate = true;
            print_estate_info(estates_array[i]);
        }
    }

    if (!sold_estate) {
        cout << "Няма продадени имоти" << endl;
    }

    return 0;
}


void sort_estate_array() {
    if (estate_count == 0) {
        cout << "Няма въведени имоти." << endl;
        return;
    }

    for (int i = 0; i < estate_count - 1; i++) {1

        bool swapped = false;
        for (int j = 0; j < estate_count - i - 1; j++) {
            if (estates_array[j].price > estates_array[j + 1].price) {
                Estate temp = estates_array[j];
                estates_array[j] = estates_array[j + 1];
                estates_array[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}


void export_estate_array_to_file() {
    pass;
}

void import_estate_array_from_file() {
    pass;
}
