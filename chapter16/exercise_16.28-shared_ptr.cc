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
    os << "deleting shared_ptr" << std::endl;
    delete p;
  }

private:
  std::ostream &os;
};

template <typename T> void deleteFunc(T *p){
  cout << "deleting pointer" << endl;
  delete p;
}

template <typename T> class Shared_ptr{
  using DF = void (*)(T*);       //point to deleter function object

public:
  Shared_ptr(T *p = nullptr, DF d = nullptr) : sp(p), count(new size_t(1)), del(d) {}
  Shared_ptr(const Shared_ptr &orig): sp(orig.sp), count(orig.count), del(orig.del){
    ++*count;
  }
  Shared_ptr& operator=(const Shared_ptr &rhs){
    ++*rhs.count;
    if(--*count == 0){
      del? del(sp) : delete(sp);
      delete count;
    }
    sp = rhs.sp;
    count = rhs.count;
    return *this;
  }

  ~Shared_ptr(){
    if(--*count == 0){
      del? del(sp) : delete(sp);
      delete count;
    }
  }

  T* get() const{
    return sp;
  }

  T& operator*() const{
    return *sp;
  }

  T* operator->() const{
    return & this->operator*();
  }

  void swap(Shared_ptr &rhs){
    using std::swap;
    swap(sp, rhs.sp);
    swap(count, rhs.count);
    swap(del, rhs.del);
  }

  size_t use_count(){
    return *count;
  }



private:
  T *sp;
  size_t *count;
  DF del;
};



int main(int argc, char const *argv[]) {
  Shared_ptr<vector<int>> sv1(new vector<int>({1,2,3,4,5}), deleteFunc);
  Shared_ptr<vector<int>> sv2 = sv1;
  (*sv1)[2] = 1;
  for(auto i : *sv1)
    cout << i << " ";
  cout << endl;
  for(auto i : *sv2)
    cout << i << " ";
  cout << endl;
  cout << "sv1 count: " << sv1.use_count() << endl;
  cout << "sv2 count: " << sv2.use_count() << endl;
  Shared_ptr<vector<int>> sv3(new vector<int>({4, 5, 6, 7, 8}));
  cout << "sv3 count: " << sv3.use_count() << endl;
  sv2.swap(sv3);
  for(auto i : *sv1)
    cout << i << " ";
  cout << endl;
  for(auto i : *sv2)
    cout << i << " ";
  cout << endl;
  for(auto i : *sv3)
    cout << i << " ";
  cout << endl;
  cout << "sv1 count: " << sv1.use_count() << endl;
  cout << "sv2 count: " << sv2.use_count() << endl;
  cout << "sv3 count: " << sv3.use_count() << endl;
  return 0;
}
