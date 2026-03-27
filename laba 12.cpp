#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <Windows.h>
#include "Header.h"

int main() {
    using namespace std;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(0));
    int choice;
    do {
        cout << "\n    ВЫБОР ЗАДАНИЯ \n";
        cout << "1. STL2Seq5: Вывести третями в обратном порядке\n";
        cout << "2. STL2Seq9: Вставка пяти средних элементов в начало\n";
        cout << "3. STL2Seq26: Поменять местами первую половину L1 со второй половиной L2\n";
        cout << "4. STL1Iter17: Записать удвоенные кодовые значения всех символов\n";
        cout << "0. Выход\n";
        cout << "Выбор: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Ошибка ввода! \n";
            continue;
        }
        switch (choice) {
        case 1:
            STL2Seq5();
            break;
        case 2:
            STL2Seq9();
            break;
        case 3:
            STL2Seq26();
            break;
        case 4:
            STL1Iter17();
            break;
        case 0:
            cout << "Программа завершена." << endl;
            break;
        default:
            cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);
}