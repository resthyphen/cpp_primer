#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <memory>
#include <stdexcept>
#include <initializer_list>
#include <functional>
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
using std::multiset;
using std::istringstream;
using std::runtime_error;
using std::make_shared;
using std::out_of_range;
using std::exception;
using std::initializer_list;
using std::shared_ptr;
using std::weak_ptr;
using std::less;
using namespace std::placeholders;
//using namespace std;
using std::allocator;
using std::plus;
using std::begin;
using std::end;

class DebugDelete {
public:
  DebugDelete(std::ostream &s = std::cerr): os(s) { }
  // as with any function template, the type of T is deduced by the compiler
  template <typename T> void operator()(T *p) const{
    os << "deleting pointer" << std::endl;
    delete p;
  }

private:
  std::ostream &os;
};

template <typename T, typename D> class Unique_ptr{
public:
  Unique_ptr(T *p = nullptr, D d = D()) : up(p), del(d){}
  Unique_ptr(const Unique_ptr&) = delete;
  Unique_ptr& operator=(const Unique_ptr&) = delete;

  ~Unique_ptr(){
    del(up);
  }

  T* release(){
    T* ret = up;
    up = nullptr;
    return ret;
  }

  T* reset(T* q = nullptr){
    up = q;

  }

  T* get() const {
    return up;
  }

  T& operator*() const{
    return *up;
  }

  T* operator->() const{
    return & this->operator*();
  }

  void swap(Unique_ptr& rhs){
    using std::swap;
    swap(up, rhs.up);
    swap(del, rhs.del);
  }

private:
  T *up;
  D del;
};

int main(int argc, char const *argv[]) {
  Unique_ptr<int, DebugDelete> p(new int(42), DebugDelete());
  Unique_ptr<string, DebugDelete> sp(new string, DebugDelete());
  p = sp;
  return 0;
}
