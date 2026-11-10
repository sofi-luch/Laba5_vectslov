/****************************************
* ФИ: Лучникова София                   *
* Название: Строки, векторы и словари   *
* Вариант: 13                           *
* Блок: D                               *
****************************************/

#include <iostream>
#include <vector>
#include <map>
#include <string>

int main() {
  int recordCount;

  cout << "recordCount = ";
  cin >> recordCount;

  if (recordCount < 0 || recordCount > 100) {
    cout << "INVALID" << endl;
    return 1;
  }
  
  //creating a vector to store records
  vector<map<string, string>> records;
  //loop for entering all records
  for (int index = 0; index < recordCount; ++index) {
    //creating a new empty record
    map<string, string> record;
    //declaration of variables for the category and the value
    string title, status;

    cout << "title = ";
    getline(cin, title);
   
    cout << "status = ";
    getline(cin, status);

    //checking for empty values
    if (title.empty() || status.empty()) {
      cout << "INVALID" << endl;
      return 1;
    }
    //adding data to the record
    record["title"] = title;
    record["status"] = status;
    //adding an entry to the general list
    records.push_back(record);
  }
  //creating a dictionary for grouping
  map<string, vector<string>> grouped;
  ////grouping values by categories
  for (const auto& record : records) {
    grouped[record.at("title")].push_back(record.at("status"));
  }
  //output of grouping results
  for (const auto& title : grouped) {
    cout << title.first << ": ";
    for (size_t index = 0; index < title.second.size(); ++index) {
      cout << title.second[index];
      if (index < title.second.size() - 1) {
        cout << ", ";
      }
    }
  }

  cout << endl;
  return 0;

}
