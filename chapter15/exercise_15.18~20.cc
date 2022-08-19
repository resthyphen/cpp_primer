#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <memory>
#include <initializer_list>
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
using std::make_shared;
using std::out_of_range;
using std::initializer_list;
using std::shared_ptr;
using std::weak_ptr;

class Base {
public:
  void pub_mem(){} // public member
protected:
  int prot_mem; // protected member
private:
  char priv_mem; // private member
};

class Sneaky : public Base {
  friend void clobber(Sneaky&); // can access Sneaky::prot_mem
  friend void clobber(Base&); // can't access Base::prot_mem
  int j;  // j is private by default

  void memfcn(Base &b) { b = *this; }
};
// ok: clobber can access the private and protected members in Sneaky objects
void clobber(Sneaky &s) { s.j = s.prot_mem = 0; }
// error: clobber can't access the protected members in Base
//void clobber(Base &b) { b.prot_mem = 0; }

struct Pub_Derv : public Base {
  // ok: derived classes can access protected members
  int f() { return prot_mem; }
  // error: private members are inaccessible to derived classes
  //char g() { return priv_mem; }
  void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv : private Base {
// private derivation doesn't affect access in the derived class
  int f1() const { return prot_mem; }
  void memfcn(Base &b) { b = *this; }
};

struct Prot_Derv: protected Base{
  int f2() const {return prot_mem;}
  void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv {
  // ok: Base::prot_mem remains protected in Pub_Derv
  int use_base() { return prot_mem; }
  void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Private : public Priv_Derv {
  // error: Base::prot_mem is private in Priv_Derv
  //int use_base() { return prot_mem; }
  //void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Protected : public Prot_Derv{
  int use_base() { return prot_mem; }
  void memfcn(Base &b) { b = *this; }
};

int main(int argc, char const *argv[]) {
  Pub_Derv d1;
  Priv_Derv d2;
  Prot_Derv d3;
  Derived_from_Public dd1;
  Derived_from_Private dd2;
  Derived_from_Protected dd3;

  Base *p = &d1; // d1 has type Pub_Derv
  //p = &d2;  // d2 has type Priv_Derv
  //p = &d3; // d3 has type Prot_Derv
  p = &dd1; // dd1 has type Derived_from_Public
  //p = &dd2; // dd2 has type Derived_from_Private
  //p = &dd3; // dd3 has type Derived_from_Protected
  return 0;
}
