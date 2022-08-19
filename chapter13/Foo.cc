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
#include <utility>
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

class Foo{
public:
  Foo() = default;
  Foo(const vector<int> &v ): data(v){};
  Foo(const Foo&);
  Foo &operator=(const Foo&);
  Foo(Foo&&);
  Foo &operator=(Foo &&);
  Foo sorted() &&;        // may run on modifiable rvalues
  Foo sorted() const &;   // may run on any kind of Foo
  vector<int> getVec() const{
    return data;
  }

private:
  vector<int> data;
};

Foo::Foo(const Foo &f) : data(f.data){
  cout << "Foo(const Foo&)" << endl;
}

Foo& Foo::operator=(const Foo &rhs){
  data = rhs.data;
  cout << "Foo &operator=(const Foo&)" << endl;
  return *this;
}

Foo::Foo(Foo &&f) : data(f.data){
  cout << "Foo(Foo&&)" << endl;
}

Foo& Foo::operator=(Foo &&rhs){
  if(this != &rhs)
    data = rhs.data;
  cout << "Foo &operator=(Foo &&)" << endl;
  return *this;
}

Foo Foo::sorted() &&
{
  sort(data.begin(), data.end());
  cout << "Foo sorted() &&" << endl;
  return *this;
}

Foo Foo::sorted() const & {
  Foo ret(*this); // make a copy
  sort(ret.data.begin(), ret.data.end()); // sort the copy
  cout <<"Foo sorted() const &" << endl;
  return ret; // return the copy
}





int main(int argc, char const *argv[]) {
  vector<int> v1{3, 2, 6, 7, 4, 2};
  vector<int> v2{6,7,4,9,2,3,1};
  Foo f1(v1);
  Foo f2(v2);
  f2 = f1.sorted();
  for(auto i : f2.getVec())
    cout << i << endl;
  return 0;
}
