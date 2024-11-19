#include <iostream>
#define pass (void)0
using namespace std;


// Декларация на функциите
void print_starting_menu();

void add_one_new_estate();
void add_list_of_estate();

void print_all_estate();

void print_highest_area_estate();
void print_sold_estate();

void sort_estate_array();

void export_estate_array_to_file();
void import_estate_array_from_file();


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

        cin >> user_input;
    }


    return 0;
}

void print_starting_menu() {
    cout << "\t\t\tАгенция за недвижими имоти\t\t\t" << endl;
    cout << "[0] Затваряне на програмата" << endl;
    cout << "[1] Добавяне на нов имот" << endl;
    cout << "[2] Извеждане на екрана" << endl;
    cout << "[3] Търсене и извеждане на екрана" << endl;
    cout << "[4] Подреждане на основния масив с имоти, без да се извежда на екрана" << endl;
    cout << "[5] Управление на файл" << endl;
}

void add_one_new_estate() {
    pass;
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
