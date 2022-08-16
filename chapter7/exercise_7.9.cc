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

struct Person{
  string getName() const {return name;}
  string getAdd() const {return address;}
  string name;
  string address;
};

istream &read(istream &is, Person &item)
{
  is >> item.name >> item.address;
  return is;
}

ostream &print(ostream &os, const Person &item)
{
  os << item.getName() << " " << item.getAdd();
  return os;
}
