#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::istringstream;
using std::ostringstream;

struct PersonInfo {
  string name;
  vector<string> phones;
};

bool valid(const string &nums){
  for(auto c : nums)
    if(!isdigit(c)){
      return false;
      break;
    }
  return true;
}

string format(const string &nums){
  return  nums;
}

int main(int argc, char const *argv[]) {
  string line, word;
  vector<PersonInfo> people;
  while (getline(cin, line)) {
    PersonInfo info;
    istringstream record(line);
    record >> info.name;
    while (record >> word)
      info.phones.push_back(word);
    people.push_back(info);
  }

  for (const auto &entry : people){
    ostringstream formatted, badNums;
    for (const auto &nums : entry.phones) { // for each number
        if (!valid(nums)) {
            badNums << entry.name << ":" << nums; // string in badNums
        } else
            // ''writes'' to formatted's string
            formatted << " " << format(nums);
    }

    if (badNums.str().empty()) // there were no bad numbers
        cout << entry.name << " " // print the name
            << formatted.str() << endl;  // and reformatted numbers
    else
        cerr << "input error: " << entry.name
             << " invalid number(s) " << badNums.str() << endl;

  }
  return 0;
}
