#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
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
using std::allocator;
using std::begin;
using std::end;
using std::uninitialized_copy;

class String{
  friend ostream &operator<<(ostream &os, const String &s);

public:
  String():start(nullptr),first_free(nullptr),cap(nullptr){}
  String(const char *s):String(){
    char *s1 = const_cast<char*>(s);
    while (*s1) {
      push_back(*s1);
      ++s1;
    }
    //auto newdata = alloc_n_copy(s, s1);
    //start = newdata.first;
    //first_free = cap = newdata.second;
  }
  String(const String&);
  String &operator=(const String&);
  ~String();
  void push_back(const char&);
  size_t size() const { return first_free - start; }
  size_t capacity() const { return cap - start;}
  char *begin() const { return start;}
  char *end() const { return first_free;}

private:
  allocator<char> alloc;
  void chk_n_alloc(){ if (size() == capacity()) reallocate(); }
  std::pair<char*, char*> alloc_n_copy(const char*, const char*);
  void free();
  void reallocate();
  char *start;
  char *first_free;
  char *cap;
};

void String::push_back(const char& c){
  chk_n_alloc();
  alloc.construct(first_free++, c);
}

pair<char*, char*>
String::alloc_n_copy(const char *b, const char *e){
  auto data = alloc.allocate(e - b);
  return {data, uninitialized_copy(b, e, data)};
}

void String::free(){
  if(start){
    for(auto p = first_free; p!= start; )
      alloc.destroy(--p);
    alloc.deallocate(start, cap - start);
  }
}

String::String(const String &s){
  auto newdata = alloc_n_copy(s.begin(), s.end());
  start = newdata.first;
  first_free = cap = newdata.second;
}

String& String::operator=(const String &rhs){
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  start = data.first;
  first_free = cap = data.second;
  return *this;
}

String::~String(){
  free();
}

void String::reallocate(){
  auto newcapacity = size() ? 2 * size() : 1;
  auto newdata = alloc.allocate(newcapacity);
  auto dest = newdata;
  auto elem = start;
  for (size_t i = 0; i != size(); ++i)
    alloc.construct(dest++, std::move(*elem++));
  free();
  start = newdata;
  first_free = dest;
  cap = start + newcapacity;
}

ostream &operator<<(ostream &os, const String &s){
  for(const auto &i : s)
    cout << i;
  return os;
}

int main(int argc, char const *argv[]) {
  char c;
  //while (cin >> c)
    //s.push_back(c);
  char ca[] = {'c', '+', '+'};
  cout << strlen("c++") << endl;
  String s("c++");
  cout << s << endl;
  return 0;
}
