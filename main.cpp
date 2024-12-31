#include <iostream>
#include <fstream>

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

void print_estates_by_broker(char broker_name[50]);
void print_estates_by_rooms(int room_count);

void edit_estate_by_reference_number(char reference_number[50]);
void print_most_expensive_in_region(char area[50]);
void print_average_price_in_region(char region[50]);
void sold_estate_percent_by_broker();

Estate estates_array[MAX_ESTATE_COUNT];


int main() {
    setlocale(LC_ALL, "");
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
            break;
        case 6:
            cout << "Изберете опция." << endl;
            cout << "[0] Затваряне на програмата" << endl;
            cout << "[1] Извличане от базовия масив на всички имоти на даден брокер и сортиране по цена" << endl;
            cout << "[2] Извличане от базовия масив на всички имоти, които са с определен брой стаи и сортиране от най-скъп към най-евтин" << endl;
            cout << "[3] Корекция на данни за имот" << endl;
            cout << "[4] Справка за най-скъп имот в даден район" << endl;
            cout << "[5] Справка за средна цена на имот в даден район" << endl;
            cout << "[6] Справка за процента на продадените имоти на всеки брокер" << endl;

            cin >> user_input;

            switch (user_input) {
            case 0:
                return 0;
            case 1:
                cout << "Въведето името на брокера: " << endl;
                char broker_name[50];
                cin.ignore();
                cin.getline(broker_name, sizeof(broker_name));

                print_estates_by_broker(broker_name);
                break;
            case 2:
                cout << "Въведете брой стаи: " << endl;
                int room_count;
                cin >> room_count;

                print_estates_by_rooms(room_count);
                break;
            case 3:
                cout << "Въведете референтен номер на имота" << endl;
                char reference_number[50];
                cin.ignore();
                cin.getline(reference_number, sizeof(reference_number));

                edit_estate_by_reference_number(reference_number);
                break;
            case 4:
                cout << "Въведете район: " << endl;
                char region[50];
                cin.ignore();
                cin.getline(region, sizeof(region));

                print_most_expensive_in_region(region);
                break;
            case 5:
                cout << "Въведете район: " << endl;
                char area[50];
                cin.ignore();
                cin.getline(area, sizeof(area));

                print_average_price_in_region(area);
                break;
            case 6:
                sold_estate_percent_by_broker();
                break;
            default:
                cout << "Въведете валидна команда." << endl;
            }

            break;
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
    cout << "[6] Допълнения" << endl;
}


Estate create_estate() {
    Estate new_estate = {};

    cout << "Референтен номер: " << endl;
    cin.ignore();
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
    cout << "\t\t\t\tСписък с имоти:\t\t\t\t" << endl;

    if (estate_count == 0) {
        cout << "Няма добавени имоти." << endl;
    }
    else {
        for (int i = 0; i < estate_count; i++) {
            Estate current_estate = estates_array[i];
            print_estate_info(current_estate);
        }
    }
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

    for (int i = 0; i < estate_count - 1; i++) {
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
    ofstream outputFile("imoti.bin", ios::binary);

    for (int i = 0; i < estate_count; i++) {
        outputFile.write((char*)&estates_array[i], sizeof(Estate));
    }

    outputFile.close();
}


void import_estate_array_from_file() {
    ifstream inputFile("imoti.bin", ios::binary);

    while (true) {
        Estate estate;
        inputFile.read((char*)&estate, sizeof(Estate));

        if (inputFile.eof()) {
            break;
        }

        if (estate_count < MAX_ESTATE_COUNT) {
            estates_array[estate_count] = estate;
            estate_count++;
        }
        else {
            cout << "Масивът е пълен." << endl;
            break;
        }
    }

    inputFile.close();
}


void print_estates_by_broker(char broker_name[50]) {
    Estate broker_estates[MAX_ESTATE_COUNT];
    int broker_estates_count = 0;

    for (int i = 0; i < estate_count; i++) {
        if (strcmp(estates_array[i].broker_name, broker_name) == 0) {
            broker_estates[broker_estates_count] = estates_array[i];
            broker_estates_count++;
        }
    }

    for (int i = 0; i < broker_estates_count - 1; i++) {
        for (int j = 0; j < broker_estates_count - i - 1; j++) {
            if (broker_estates[j].price > broker_estates[j + 1].price) {
                Estate temp = broker_estates[j];
                broker_estates[j] = broker_estates[j + 1];
                broker_estates[j + 1] = temp;
            }
        }
    }

    if (broker_estates_count == 0) {
        cout << "Няма имоти за въведения брокер." << endl;
    }
    else {
        for (int i = 0; i < broker_estates_count; i++) {
            print_estate_info(broker_estates[i]);
        }
    }
}


void print_estates_by_rooms(int room_count) {
    Estate temporary_array[MAX_ESTATE_COUNT];
    int count = 0;

    for (int i = 0; i < estate_count; i++) {
        if (estates_array[i].room_count == room_count) {
            temporary_array[count] = estates_array[i];
            count++;
        }
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (temporary_array[j].price < temporary_array[j + 1].price) {
                Estate temp = temporary_array[j];
                temporary_array[j] = temporary_array[j + 1];
                temporary_array[j + 1] = temp;
            }
        }
    }

    if (count == 0) {
        cout << "Няма имоти с въведения брой стаи." << endl;
    }
    else {
        for (int i = 0; i < count; i++) {
            print_estate_info(temporary_array[i]);
        }
    }
}


void edit_estate_by_reference_number(char reference_number[50]) {
    int index = -1;

    for (int i = 0; i < estate_count; i++) {
        if (strcmp(estates_array[i].reference_number, reference_number) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Няма имот с въведения референтен номер." << endl;
        return;
    }

    if (strcmp(estates_array[index].status, "Продаден") == 0) {
        cout << "Продаден имот не може да се коригира!" << endl;
        return;
    }

    if (strcmp(estates_array[index].status, "Капариран") == 0) {
        estates_array[index].price *= 0.8;
    }

    cout << "Въведете новите данни за имота:" << endl;


    Estate updated_estate = create_estate();
    strcpy_s(estates_array[index].broker_name, updated_estate.broker_name);
    strcpy_s(estates_array[index].estate_type, updated_estate.estate_type);
    strcpy_s(estates_array[index].estate_location, updated_estate.estate_location);
    strcpy_s(estates_array[index].exposure, updated_estate.exposure);
    estates_array[index].price = updated_estate.price;
    estates_array[index].total_area = updated_estate.total_area;
    estates_array[index].room_count = updated_estate.room_count;
    estates_array[index].floor = updated_estate.floor;
    strcpy_s(estates_array[index].status, updated_estate.status);
    

    cout << "Успешно коригиране!" << endl;
}


void print_most_expensive_in_region(char area[50]) {
    int max_index = -1;
    double max_price = 0;

    for (int i = 0; i < estate_count; i++) {
        if (strcmp(estates_array[i].estate_location, area) == 0 && estates_array[i].price > max_price) {
            max_price = estates_array[i].price;
            max_index = i;
        }
    }

    if (max_index != -1) {
        cout << "Най-скъпият имот в района е: " << endl;
        print_estate_info(estates_array[max_index]);
    }
    else {
        cout << "Няма имоти в този район." << endl;
    }
}


void print_average_price_in_region(char region[50]) {
    double total_price = 0;
    int count = 0;

    for (int i = 0; i < estate_count; i++) {
        if (strcmp(estates_array[i].estate_location, region) == 0) {
            total_price += estates_array[i].price;
            count++;
        }
    }

    if (count > 0) {
        cout << "Средната цена на имот в района " << region << " е: " << (total_price / count) << "лв." << endl;
    }
    else {
        cout << "Няма имоти в този район." << endl;
    }
}


void sold_estate_percent_by_broker() {
    char brokers[MAX_ESTATE_COUNT][50];
    int broker_count = 0;

    for (int i = 0; i < estate_count; i++) {
        bool found = false;
        for (int j = 0; j < broker_count; j++) {
            if (strcmp(brokers[j], estates_array[i].broker_name) == 0) {
                found = true;
                break;
            }
        }
        if (!found) {
            strcpy_s(brokers[broker_count], estates_array[i].broker_name);
            broker_count++;
        }
    }

    for (int i = 0; i < broker_count; i++) {
        int total = 0, sold = 0;
        for (int j = 0; j < estate_count; j++) {
            if (strcmp(brokers[i], estates_array[j].broker_name) == 0) {
                total++;
                if (strcmp(estates_array[j].status, "Продаден") == 0) {
                    sold++;
                }
            }
        }
        if (total > 0) {
            double percentage = (double)sold / total * 100;
            cout << "Брокер: " << brokers[i] << " - " << percentage << "% продадени имоти." << endl;
        }
    }
}
