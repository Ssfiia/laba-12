#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <iterator>
#include <random>
#include <ctime>
#include <iomanip>
#include "Header.h"

// Вывод списка
void printList(const std::list<int>& l, const std::string& title) {
    using namespace std;
    cout << title << ": ";
    for (auto it = l.begin(); it != l.end(); it++)
        cout << setw(2) << *it << " ";
    cout << endl;
}

// Вывод дека
void printDeque(const std::deque<int>& d, const std::string& title) {
    using namespace std;
    cout << title << ": ";
    for (int i = 0; i < d.size(); i++)
        cout << setw(2) << d[i] << " ";
    cout << endl;
}

// Выбор способа заполнения
int chooseMethod() {
    using namespace std;
    int m;
    cout << "\nСпособ заполнения:\n";
    cout << "1. C консоли\n";
    cout << "2. Случайные числа\n";
    cout << "3. Из файла\n";
    cout << "Выбор: ";
    cin >> m;
    return m;
}

// Заполнение списка с консоли
void ListFromConsole(std::list<int>& l, int count) {
    using namespace std;
    cout << "Введите " << count << " целых чисел: ";
    for (int i = 0; i < count; i++) {
        int x;
        cin >> x;
        l.push_back(x);
    }
}

// Заполнение дека с консоли
void DequeFromConsole(std::deque<int>& d, int count) {
    using namespace std;
    cout << "Введите " << count << " целых чисел: ";
    for (int i = 0; i < count; i++) {
        int x;
        cin >> x;
        d.push_back(x);
    }
}

// Заполнение списка случайными числами
void ListRandom(std::list<int>& l, int count) {
    for (int i = 0; i < count; i++)
        l.push_back(rand() % 100);
}

// Заполнение дека случайными числами
void DequeRandom(std::deque<int>& d, int count) {
    for (int i = 0; i < count; i++)
        d.push_back(rand() % 100);
}

// Заполнение списка из файла
bool ListFromFile(std::list<int>& l, const std::string& filename) {
    using namespace std;
    ifstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла\n";
        return false;
    }
    int x;
    while (file >> x)
        l.push_back(x);
    return true;
}

// Заполнение дека из файла
bool DequeFromFile(std::deque<int>& d, const std::string& filename) {
    using namespace std;
    ifstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла\n";
        return false;
    }
    int x;
    while (file >> x)
        d.push_back(x);
    return true;
}

// Задание 1  STL2Seq5
void STL2Seq5() {
    using namespace std;
    list<int> L;
    int n, method;

    cout << "\n STL2Seq5\n";
    method = chooseMethod();

    if (method == 1) {
        cout << "Введите количество элементов (кратное 3): ";
        cin >> n;
        while (n % 3 != 0) {
            cout << "Ошибка! Введите число кратное 3: ";
            cin >> n;
        }
        ListFromConsole(L, n);
    }
    else if (method == 2) {
        cout << "Введите количество элементов (кратное 3): ";
        cin >> n;
        while (n % 3 != 0) {
            cout << "Ошибка! Введите число кратное 3: ";
            cin >> n;
        }
        ListRandom(L, n);
    }
    else {
        string fname;
        cout << "Имя файла: ";
        cin >> fname;
        if (!ListFromFile(L, fname)) {
            return;
        }
        if (L.size() % 3 != 0) {
            cout << "Ошибка: в файле должно быть кратное 3 количество чисел\n";
            return;
        }
    }

    printList(L, "Исходный список");

    int part = L.size() / 3;

    // Разделяем на три части
    list<int> first, second, third;
    list<int>::iterator it = L.begin();
    for (int i = 0; i < part; i++) {
        first.push_back(*it);
        it++;
    }
    for (int i = 0; i < part; i++) {
        second.push_back(*it);
        it++;
    }for (int i = 0; i < part; i++) {
        third.push_back(*it);
        it++;
    }
    cout << "\nРЕЗУЛЬТАТ: ";
    for (int x : first) cout << x << " ";
    for(auto rit = second.rbegin(); rit != second.rend(); rit++) {
        cout << *rit << " ";
    }
    for (auto rit = third.rbegin(); rit != third.rend(); rit++) {
        cout << *rit << " ";
    }
    cout << endl;
}

// Задание 2 STL2Seq9
void STL2Seq9() {
    using namespace std;
    deque<int> D;
    int n, method;

    cout << "\n STL2Seq9\n";
    method = chooseMethod();

    if (method == 1) {
        cout << "Введите нечетное количество элементов (>=5): ";
        cin >> n;
        while (n < 5 || n % 2 == 0) {
            cout << "Ошибка! Введите нечетное число >=5: ";
            cin >> n;
        }
        DequeFromConsole(D, n);
    }
    else if (method == 2) {
        cout << "Введите нечетное количество элементов (>=5): ";
        cin >> n;
        while (n < 5 || n % 2 == 0) {
            cout << "Ошибка! Введите нечетное число >=5: ";
            cin >> n;
        }
        DequeRandom(D, n);
    }
    else {
        string fname;
        cout << "Имя файла: ";
        cin >> fname;
        if (!DequeFromFile(D, fname)) {
            return;
        }
        if (D.size() < 5 || D.size() % 2 == 0) {
            cout << "Ошибка: в файле должно быть нечетное количество >=5\n";
            return;
        }
    }
    printDeque(D, "Исходный дек");

    auto mid = D.size() / 2;
    auto start = D.begin() + (mid - 2);
    auto end = start + 5;

    D.insert(D.begin(), start, end);

    printDeque(D, "Дек после вставки");
}

// Задание 3 STL2Seq26
void STL2Seq26() {
    using namespace std;
    list<int> L1, L2;
    int n, method;

    cout << "\n STL2Seq26 \n";
    method = chooseMethod();

    if (method == 1) {
        cout << "Введите четное количество элементов: ";
        cin >> n;
        while (n % 2 != 0) {
            cout << "Ошибка! Введите четное число: ";
            cin >> n;
        }
        cout << "Ввод первого списка L1:\n";
        ListFromConsole(L1, n);
        cout << "Ввод второго списка L2:\n";
        ListFromConsole(L2, n);
    }
    else if (method == 2) {
        cout << "Введите четное количество элементов: ";
        cin >> n;
        while (n % 2 != 0) {
            cout << "Ошибка! Введите четное число: ";
            cin >> n;
        }
        ListRandom(L1, n);
        ListRandom(L2, n);
    }
    else {
        string f1, f2;
        cout << "Имя файла для L1: ";
        cin >> f1;
        cout << "Имя файла для L2: ";
        cin >> f2;

        if (!ListFromFile(L1, f1) || !ListFromFile(L2, f2)) {
            return;
        }
        if (L1.size() != L2.size() || L1.size() % 2 != 0) {
            cout << "Ошибка: файлы должны содержать одинаковое четное количество чисел\n";
            return;
        }
    }

    cout << "\nИсходные списки:\n";
    printList(L1, "L1");
    printList(L2, "L2");

    int half = L1.size() / 2;

    auto itL1 = L1.begin();
    for (int i = 0; i < half; i++) itL1++;

    auto itL2 = L2.begin();
    for (int i = 0; i < half; i++) itL2++;

    // Выполняем обмен через splice
    L2.splice(itL2, L1, L1.begin(), itL1);
    L1.splice(L1.begin(), L2, itL2, L2.end());

    cout << "\nПосле обмена половинами:\n";
    printList(L1, "L1");
    printList(L2, "L2");
}

// Задание 4 STL1Iter17 
void STL1Iter17() {
    using namespace std;
    vector<char> symbols;
    string fname;
    int n, method;

    cout << "\n STL1Iter17 \n";
    method = chooseMethod();

    cout << "Имя файла для сохранения: ";
    cin >> fname;

    ofstream outFile(fname);
    if (!outFile) {
        cout << "Ошибка создания файла\n";
        return;
    }

    if (method == 1) {
        cout << "Количество символов: ";
        cin >> n;
        cout << "Введите " << n << " символов: ";
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            symbols.push_back(c);
        }

        cout << "Исходные символы: ";
        for (char c : symbols) cout << c << " ";
        cout << endl;
    }
    else if (method == 2) {
        cout << "Количество символов: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            symbols.push_back('A' + rand() % 26);
        }

        cout << "Сгенерированные символы: ";
        for (char c : symbols) cout << c << " ";
        cout << endl;
    }
    else {
        string filename;
        cout << "Имя файла с символами: ";
        cin >> filename;

        ifstream fin(filename);
        if (!fin) {
            cout << "Ошибка открытия файла\n";
            outFile.close();
            return;
        }

        char c;
        while (fin >> c) {
            symbols.push_back(c);
        }
        fin.close();

        if (symbols.empty()) {
            cout << "Файл пуст\n";
            outFile.close();
            return;
        }

        cout << "Символы из файла: ";
        for (char c : symbols) cout << c << " ";
        cout << endl;
    }

    cout << "Результат: ";
    transform(symbols.begin(), symbols.end(),
        ostream_iterator<int>(outFile, " "),
        [](char c) { return (int)c * 2; });

    outFile.close();
    ifstream in(fname);
    istream_iterator<int> in_it(in), end;
    while (in_it != end) {
        cout << *in_it << " ";
        ++in_it;
    }
    cout << endl;
    in.close();
}