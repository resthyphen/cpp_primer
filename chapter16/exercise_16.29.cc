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
  using DF = void(*)(T*);       //point to deleter function object

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


template <typename T> class Blob {
public:
  typedef T value_type;
  typedef typename std::vector<T>::size_type size_type;

  // constructors
  Blob();
  Blob(std::initializer_list<T> il);

  // number of elements in the Blob
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }

  // add and remove elements
  void push_back(const T &t) {data->push_back(t);}

  // move version; see § 13.6.3 (p. 548)
  void push_back(T &&t) { data->push_back(std::move(t)); }
  void pop_back();

  // element access
  T& back();
  T& operator[](size_type i); // defined in § 14.5 (p. 566)

  vector<T> get(){
    return *data;
  }

  private:
  Shared_ptr<std::vector<T>> data;

  // throws msg if data[i] isn't valid
  void check(size_type i, const std::string &msg) const;
};


template <typename T>
Blob<T>::Blob(): data(Shared_ptr<std::vector<T>>()) { }

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il):
data(Shared_ptr<std::vector<T>>(new vector<T>(il))) { }

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const{
  if (i >= data->size())
    throw std::out_of_range(msg);
}

template <typename T>
T& Blob<T>::back(){
  check(0, "back on empty Blob");
  return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i){
  // if i is too big, check will throw, preventing access to a nonexistent element
  check(i, "subscript out of range");
  return (*data)[i];
}

template <typename T> void Blob<T>::pop_back(){
  check(0, "pop_back on empty Blob");
  data->pop_back();
}



int main(int argc, char const *argv[]) {
  Blob<string> b1;
  Blob<string> b2 = {"a", "an", "the"};
  b1 = b2;
  b1.push_back("about");
  for(const auto &i : b2.get())
    cout << i << endl;
  return 0;
}
