/****************************************
* ФИ: Лучникова София                   *
* Название: Строки, векторы и словари   *
* Вариант: 13                           *
* Блок: B                                *
****************************************/

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int maxCount = 100;
  int limit = 1000;
  int kolvoElements, value;;

  cout << "kolvoElements = ";
  cin >> kolvoElements;

  if (kolvoElements < 0 || kolvoElements > maxCount) {
    cout << "INVALID\n";
    return 1;
  }
  //creating a vector to store values
  vector<int> values;
  //pre‑allocation of memory
  values.reserve(static_cast<size_t>(kolvoElements));
   
  for (int index = 0; index < kolvoElements; ++index) {

    cout << "value " << index + 1 << " = ";
    cin >> value;

    if (value < -limit || value > limit) {
      cout << "INVALID\n";
      return 1;
    }
    //add a value to the end of the vector
    values.push_back(value);
  }
  //checking for an empty vector
  if (values.empty()) {
    cout << "EMPTY\n";
    return 0;
  }
  //initial maximum value
  int maximum = values[0];
  for (int value : values) {
    if (value > maximum) {
       maximum = value;
    }
  }
  //removing the first occurrence of the maximum value
  for (size_t position = 0; position < values.size(); ++position) {
    if (values[position] == maximum) {
       values.erase(values.begin() + static_cast<long>(position));
       break;                                  
    }
  }
  //re‑check for emptiness after deletion
  if (values.empty()) {
    cout << "EMPTY\n";
    return 0;
  }

  for (size_t index = 0; index < values.size(); ++index) {
    if (index > 0) {
      cout << " ";
    }
    cout << values[index];
  }

  cout << "\n";
  return 0;

}
