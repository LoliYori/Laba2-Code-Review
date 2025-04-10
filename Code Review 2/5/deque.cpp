/* Продолжение задания 5 */
#include "deque.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <deque>

using namespace std;

deque<int> GetDataFromKeyboard() {
    int count;
    cout << "Введите количество целых чисел (нечетное и >= 5): ";
    while (!(cin >> count) || count < 5 || count % 2 == 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода! Количество должно быть нечетным и >= 5. Повторите ввод: ";
    }

    deque<int> D;
    cout << "Введите " << count << " целых чисел:" << endl;
    for (int i = 0; i < count; ++i) {
        int number;
        while (!(cin >> number)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода! Введите целое число: ";
        }
        D.push_back(number);
    }

    return D;
}

deque<int> GetRandomData(int count) {
    deque<int> D;
    srand(static_cast<unsigned>(time(0)));

    if (count < 5 || count % 2 == 0) {
        throw invalid_argument("Количество чисел должно быть нечетным и >= 5.");
    }

    for (int i = 0; i < count; ++i) {
        D.push_back(rand() % 100);
    }

    return D;
}

deque<int> GetDataFromFile() {
    deque<int> D;
    ifstream infile("deque.txt");
    int number;

    if (!infile.is_open()) {
        throw runtime_error("Не удалось открыть файл.");
    }

    while (infile >> number) {
        D.push_back(number);
    }

    if (D.size() < 5 || D.size() % 2 == 0) {
        throw invalid_argument("Количество чисел в файле должно быть нечетным и >= 5.");
    }

    return D;
}

void FuncInsert(deque<int>& D) {
    size_t N = D.size();

    size_t MiddleIndex = N / 2;

    deque<int> MiddleElements;
    for (size_t i = MiddleIndex - 2; i <= MiddleIndex + 2; ++i) {
        MiddleElements.push_back(D[i]);
    }

    D.insert(D.begin(), MiddleElements.begin(), MiddleElements.end());
}