#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

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
    string category, value;

    getline(cin, category);
    getline(cin, value);

    //checking for empty values
    if (category.empty() || value.empty()) {
      cout << "INVALID" << endl;
      return 1;
    }
    //adding data to the record
    record["category"] = category;
    record["value"] = value;
    //adding an entry to the general list
    records.push_back(record);
  }
  //creating a dictionary for grouping
  map<string, vector<string>> grouped;
  ////grouping values by categories
  for (const auto& record : records) {
    grouped[record.at("category")].push_back(record.at("value"));
  }
  //output of grouping results
  for (const auto& category : grouped) {
    cout << category.first << ": ";
    for (size_t index = 0; index < category.second.size(); ++index) {
      cout << category.second[index];
      if (index < category.second.size() - 1) {
        cout << ", ";
      }
    }
  }

  cout << endl;
  return 0;

}