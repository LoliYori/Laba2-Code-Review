/* Элементами контейнеров являются целые числа. Для
*заполнения контейнера использовать итератор и конструктор соответствующего контейнера,
*для вывода элементов использовать итератор (для вывода элементов в обратном порядке
*использовать обратные итераторы, возвращаемые функциями-членами rbegin и rend)
*Обязательно наличие дружественного интерфейса. Ввод данных организовать
*разными способами (с клавиатуры, рандом, из файла)
*
*Дан дек D с нечетным количеством элементов N (? 5). Добавить в начало дека пять
*его средних элементов в исходном порядке. Использовать один вызов функции-члена insert. 
*/
#include <iostream>
#include <deque>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include "deque.h"

using namespace std;

int main() {
    int choice = 0;
    cout << "Выберите метод ввода данных: 1.Ввод с клавиатуры  2.Случайные числа  3.Чтение из файла" << endl;
    cin >> choice;

    deque<int> D;

    try {
        switch (choice) {
        case 1:
            D = GetDataFromKeyboard();
            break;
        case 2:
        {
            int count;
            cout << "Введите количество чисел (нечетное и >= 5): ";
            cin >> count;
            while (count < 5 || count % 2 == 0) {
                cout << "Количество должно быть нечетным и >= 5. Повторите ввод: ";
                cin >> count;
            }
            D = GetRandomData(count);
            break;
        }
        case 3:
        {
            D = GetDataFromFile();
            break;
        }
        default:
            cerr << "Некорректный выбор." << endl;
            return 1;
        }

        cout << "Исходный дек: ";
        for (const auto& elem : D) {
            cout << elem << " ";
        }
        cout << endl;

        cout << "Дек в обратном порядке: ";
        for (auto it = D.rbegin(); it != D.rend(); ++it) {
            cout << *it << " ";
        }
        cout << endl;

        FuncInsert(D);

        cout << "Дек после вставки: ";
        for (const auto& elem : D) {
            cout << elem << " ";
        }
        cout << endl;

    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
    return 0;
}