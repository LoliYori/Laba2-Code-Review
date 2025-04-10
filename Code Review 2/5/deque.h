/* Продолжение задания 5 */
#ifndef DEQUE_H
#define DEQUE_H

#include <deque>

using namespace std;

deque<int> GetDataFromKeyboard();
deque<int> GetRandomData(int count);
deque<int> GetDataFromFile();
void FuncInsert(deque<int>& D);

#endif