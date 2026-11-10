/****************************************
* ФИ: Лучникова София                   *
* Название: Строки, векторы и словари   *
* Вариант: 13                           *
* Блок: C                                *
****************************************/

#include <iostream>
#include <map>

using namespace std;

int main() {
  int countPars, value;

  cout << "countPars = ";
  cin >> countPars;

  if (countPars < 0 || countPars > 100) {
    cout << "INVALID" << endl;
    return 1;
  }

  map<string, int> data;
  for (int index = 0; index < countPars; ++index) {
    string key;

    cout << "key = ";
    cin >> key;

    cout << "value = ";
    cin >> value;
       
    data[key] = value;
  }

  if (data.empty()) {
    cout << "EMPTY" << endl;
    return 0;
  }

  //find the minimum value, initial maximum value
  int maxValue = data.begin()->second;
  //the key to the maximum value
  string maxKey = data.begin()->first;

  for (const auto & pair : data) {
    if (pair.second > maxValue) {
      maxValue = pair.second;
      maxKey = pair.first;
    }
  }

  cout << maxKey << " " << maxValue << endl;
  return 0;

}