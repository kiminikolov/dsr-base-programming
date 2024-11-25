#include <iostream>
#define pass (void)0
using namespace std;


const unsigned short MAX_ESTATE_COUNT = 100;
unsigned short estate_count = 0;


struct Estate {
    int reference_number;
    string broker_name;
    string estate_type;
    string estate_location;
    string exposure;
    double price;
    double total_area;
    int room_count;
    int floor;
    string status;
};


// Прототипи на функциите
void print_starting_menu();

void add_one_new_estate();
void add_list_of_estate();

void print_all_estate();

void print_highest_area_estate();
void print_sold_estate();

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
    int reference_number, room_count, floor;
    string broker_name, estate_type, estate_location, exposure, status;
    double price, total_area;

    cout << "Референтен номер: " << endl;
    cin >> reference_number;
    cout << "Брокер: " << endl;
    cin >> broker_name;
    cout << "Тип: " << endl;
    cin >> estate_type;
    cout << "Локация: " << endl;
    cin >> estate_location;
    cout << "Изложение: " << endl;
    cin >> exposure;
    cout << "Цена: " << endl;
    cin >> price;
    cout << "Площ: " << endl;
    cin >> total_area;
    cout << "Брой стаи: " << endl;
    cin >> room_count;
    cout << "Етаж: " << endl;
    cin >> floor;
    cout << "Статус: " << endl;
    cin >> status;

    return Estate(reference_number, broker_name,estate_type, estate_location, exposure, price, total_area, room_count, floor, status);
}


void add_one_new_estate() {
    const Estate new_estate = create_estate();

    estates_array[estate_count] = new_estate;
    estate_count++;
}

void add_list_of_estate() {
    pass;
}

void print_all_estate() {
    pass;
}

void print_highest_area_estate() {
    pass;
}

void print_sold_estate() {
    pass;
}

void sort_estate_array() {
    pass;
}

void export_estate_array_to_file() {
    pass;
}

void import_estate_array_from_file() {
    pass;
}
