/****************************************
* ФИ: Лучникова София                   *
* Название: Строки, векторы и словари   *
* Вариант: 13                           *
* Блок: A                                *
****************************************/

#include <iostream>
#include <string>

using namespace std;

int main() {
  size_t maxLen = 200;
  string text;
  //read the entire line, including spaces
  getline(cin, text);
  
  if (text.size() > maxLen) {
    cout << "INVALID\n";
    return 1;
  }

  //declaration of a string for the result
  string result;
  //pre‑allocation of memory for optimization
  result.reserve(text.size());

  //iterating through each character of the input string
  for (char symbol : text) {
    //converting a symbol to an unsigned type
    unsigned char byte = static_cast<unsigned char>(symbol);
    //check: is the character an ASCII letter?
    if (isalpha(byte) && byte < 128) {      
      result += symbol;
    }
  }
  //check for empty result
  if (result.empty()) {
    cout << "EMPTY\n";
  } else {
    cout << result << "\n";
  }

  return 0;
}