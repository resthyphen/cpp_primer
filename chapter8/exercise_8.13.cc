#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::istringstream;
using std::ifstream;

struct PersonInfo {
  string name;
  vector<string> phones;
};

int main(int argc, char const *argv[]) {
  string line, word;
  vector<PersonInfo> people;
  ifstream in(argv[1]);
  while (getline(in, line)) {
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
  in.close();
  return 0;
}
