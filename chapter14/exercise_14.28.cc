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

class StrBlobPtr;

class StrBlob {
  friend class StrBlobPtr;

public:
  typedef std::vector<std::string>::size_type size_type;
  StrBlob();
  StrBlob(std::initializer_list<std::string> il);
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  // add and remove elements
  void push_back(const std::string &t) { data->push_back(t); }
  void push_back(string &&t){
    data->push_back(std::move(t));
  }
  void pop_back();
  // element access
  std::string& front();
  std::string& back();
  StrBlobPtr begin();
  StrBlobPtr end();

  string& operator[](size_t n){
    return (*data)[n];
  }

  const string& operator[](size_t n) const {
    return (*data)[n];
  }

private:
  std::shared_ptr<std::vector<std::string>> data;
  // throws msg if data[i] isn't valid
  void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr {
public:
  StrBlobPtr(): curr(0) { }
  StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }
  string& deref() const;
  StrBlobPtr& incr();  // prefix version

  string& operator[](size_t n){
    auto p = check(n, "dereference past end");
    return (*p)[n];
  }

  const string& operator[](size_t n) const{
    auto p = check(n, "dereference past end");
    return (*p)[n];
  }

  StrBlobPtr& operator++();
  StrBlobPtr& operator--();
  StrBlobPtr operator++(int); // postfix operators
  StrBlobPtr operator--(int);
  StrBlobPtr& operator+=(size_t n);
  StrBlobPtr& operator-=(size_t n);
  StrBlobPtr operator+(size_t n);
  StrBlobPtr operator-(size_t n);

private:
// check returns a shared_ptr to the vector if the check succeeds
  shared_ptr<vector<string>> check(size_t, const string&) const;
// store a weak_ptr, which means the underlying vector might be destroyed
  std::weak_ptr<vector<string>> wptr;
  std::size_t curr; // current position within the array
};



StrBlob::StrBlob(): data(make_shared<vector<string>>()) { }
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) { }

void StrBlob::check(size_type i, const string &msg) const{
  if (i >= data->size())
    throw out_of_range(msg);
}

string& StrBlob::front()
{
  // if the vector is empty, check will throw
  check(0, "front on empty StrBlob");
  return data->front();
}

string& StrBlob::back()
{
  check(0, "back on empty StrBlob");
  return data->back();
}

void StrBlob::pop_back()
{
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}

StrBlobPtr StrBlob::begin() {
  return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end(){
  auto ret = StrBlobPtr(*this, data->size());
  return ret;
}



shared_ptr<vector<string>>
StrBlobPtr::check(size_t i, const string &msg) const {
    auto ret = wptr.lock(); // is the vector still around?
    if (!ret)
      throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
      throw out_of_range(msg);
    return ret; // otherwise, return a shared_ptr to the vector
}

string& StrBlobPtr::deref() const {
  auto p = check(curr, "dereference past end");
  return (*p)[curr]; // (*p) is the vector to which this object points
}

// prefix: return a reference to the incremented object
StrBlobPtr& StrBlobPtr::incr(){
  // if curr already points past the end of the container, can't increment it
  check(curr, "increment past end of StrBlobPtr");
  ++curr; // advance the current state
  return *this;
}

StrBlobPtr& StrBlobPtr::operator++(){
  // if curr already points past the end of the container, can't increment it
  check(curr, "increment past end of StrBlobPtr");
  ++curr; // advance the current state
  return *this;
}

StrBlobPtr& StrBlobPtr::operator--(){
  // if curr is zero, decrementing it will yield an invalid subscript
  --curr; // move the current state back one element
  check(curr, "decrement past begin of StrBlobPtr");
  return *this;
}

// postfix: increment/decrement the object but return the unchanged value
StrBlobPtr StrBlobPtr::operator++(int){
  // no check needed here; the call to prefix increment will do the check
  StrBlobPtr ret = *this; // save the current value
  ++*this; // advance one element; prefix ++ checks the increment
  return ret; // return the saved state
}

StrBlobPtr StrBlobPtr::operator--(int){
  // no check needed here; the call to prefix decrement will do the check
  StrBlobPtr ret = *this; // save the current value
  --*this; // move backward one element; prefix -- checks thedecrement
  return ret; // return the saved state
}

StrBlobPtr& StrBlobPtr::operator+=(size_t n){
  curr += n;
  check(curr, "increment past end of StrBlobPtr");
  return *this;
}

StrBlobPtr& StrBlobPtr::operator-=(size_t n){
  curr -= n;
  check(curr, "decrement past begin of StrBlobPtr");
  return *this;
}

StrBlobPtr StrBlobPtr::operator+(size_t n){
  auto ret(*this);
  ret += n;
  return ret;
}

StrBlobPtr StrBlobPtr::operator-(size_t n){
  auto ret(*this);
  ret -= n;
  return ret;
}

int main(int argc, char const *argv[]) {
  StrBlob b1;
  StrBlob b2 = {"a", "an", "the"};
  b1 = b2;
  b1.push_back("about");
  auto p = b1.begin();
  cout << (p++).deref() << endl;
  ++p;
  --p;
  cout << p.deref() << endl;
  StrBlobPtr p2 = b2.begin() + 2;
  cout << p[2] << endl;
  return 0;
}
