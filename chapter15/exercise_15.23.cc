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
  virtual int fcn(){
    cout << "Base::fcn"<< endl;
    return 0;
  }
};

class D1 : public Base {
public:
  // hides fcn in the base; this fcn is not virtual
  // D1 inherits the definition of Base::fcn()
  int fcn(int i){
    cout << "D1::fcn(int i)" << endl;
    return i;
  } // parameter list differs from fcn in Base

  int fcn(){
    cout << "D1::fcn()" << endl;
    return 0;
  }
  virtual void f2(){
    cout << "D1::f2()" << endl;
  } // new virtual function that does not exist in Base
};

class D2 : public D1 {
public:
  int fcn(int i){
    cout << "D2::fcn(int i)" << endl;
    return i;
  } // nonvirtual function hides D1::fcn(int)
  int fcn() {
    cout << "D2::fcn"<< endl;
    return 0;
  }       // overrides virtual fcn from Base
  void f2(){
    cout << "D2::f2()" << endl;
  }     // overrides virtual f2 from D1
};



int main(int argc, char const *argv[]) {
  Base bobj; D1 d1obj; D2 d2obj;
  Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
  bp1->fcn(); // virtual call, will call Base::fcn at run time
  bp2->fcn(); // virtual call, will call D1::fcn at run time
  bp3->fcn(); // virtual call, will call D2::fcn at run time
  D1 *d1p = &d1obj; D2 *d2p = &d2obj;
  //bp2->f2(); // error: Base has no member named f2
  d1p->fcn();
  d1p->f2(); // virtual call, will call D1::f2() at run time
  d2p->f2(); // virtual call, will call D2::f2() at run tim
  return 0;
}
