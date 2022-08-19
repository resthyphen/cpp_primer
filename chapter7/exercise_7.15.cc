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
  Person() = default;
  Person(const std::string &n) : name(n) {}
  Person(const string &n, const string &a) : name(n), address(a) {}
  Person(istream &is);
  string getName() const {return name;}
  string getAddress() const {return address;}
  string name = "";
  string address = "";
};

istream &read(istream &is, Person &item){
  is >> item.name >> item.address;
  return is;
}

ostream &print(ostream &os, const Person &item){
  os << item.getName() << " " << item.getAddress();
  return os;
}

Person::Person(istream &is){
  read(is, *this);
}

int main() {
  Person p1;
  Person p2("Zhang San");
  Person p3("Zhang San", "Earth");
  Person p4(cin);

  print(cout, p1) << endl;
  print(cout, p2) << endl;
  print(cout, p3) << endl;
  print(cout, p4) << endl;

  return 0;
}
