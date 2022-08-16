#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::istream;
using std::ostream;

class Person{

public:
  Person() = default;
  Person(const std::string &n) : name(n) {}
  Person(const string &n, const string &a) : name(n), address(a) {}
  Person(istream &is);
  string getName() const {return name;}
  string getAddress() const {return address;}

private:
  string name = "";
  string address = "";
};
