#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <sstream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;
using std::istringstream;

int main(int argc, char const *argv[]) {
  list<int> li;
  vector<int> vi;
  string line;
  cout << "Please enter list<int> li:   ";
  getline(cin, line);
  istringstream record(line);
  int n;
  while (record >> n)
    li.push_back(n);

  cout << "Please enter vector<int> vi: ";
  getline(cin, line);
  record.clear();
  record.str(line);
  while(record >> n)
    vi.push_back(n);

  auto i = li.cbegin();
  auto j = vi.cbegin();
  for(; i != li.cend() && j != vi.cend(); ++i, ++j){
    if(*i > *j){
      cout << "li > vi" << endl;
      return 0;
    }
    if(*i < *j){
      cout << "li < vi" << endl;
      return 0;
    }
  }

  if(li.size() == vi.size())
    cout << "li == vi" << endl;

  if(li.size() > vi.size())
    cout << "li > vi" << endl;

  if(li.size() < vi.size())
    cout << "li < vi" << endl;

  return 0;
}
