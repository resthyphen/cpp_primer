#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <memory>
#include <stdexcept>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::istream;
using std::ostream;
using std::ifstream;
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;
using std::list;
using std::map;
using std::set;
using std::pair;
using std::multimap;
using std::istringstream;
using std::runtime_error;
using std::out_of_range;
using std::exception;
using std::allocator;
using std::shared_ptr;

class Employee{
public:
  Employee() = default;
  Employee(const string &s): name(s), id(++n){}
  string getName() const { return name;}
  int getID() const { return id;}

private:
  int id;
  string name;
  static int n;
};

int Employee::n = 0;

int main(int argc, char const *argv[]) {
  Employee e1;
  Employee e2("Jack");

  cout << e1.getID() << " " << e1.getName() << endl;
  cout << e2.getID() << " " << e2.getName() << endl;
  return 0;
}
