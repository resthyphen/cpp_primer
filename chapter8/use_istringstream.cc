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

struct PersonInfo {
  string name;
  vector<string> phones;
};

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
  for (auto p : people){
    cout << p.name << " ";
    for(auto i : p.phones)
      cout << i << " " ;
    cout << endl;
  }
  return 0;
}
