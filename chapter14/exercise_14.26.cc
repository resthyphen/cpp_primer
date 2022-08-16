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
using std::uninitialized_copy;

class StrBlobPtr;

class StrBlob {
  friend class StrBlobPtr;
  friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
  friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
  friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);

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
  friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
  friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
  friend bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);

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

bool operator==(const StrBlob &lhs, const StrBlob &rhs){
  return lhs.data == rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs){
  return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs){
  return *lhs.data < *rhs.data;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
  return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
  return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
  return lhs.curr < rhs.curr;
}

class StrVec {
  friend bool operator==(const StrVec &lhs, const StrVec &rhs);
  friend bool operator!=(const StrVec &lhs, const StrVec &rhs);
  friend bool operator<(const StrVec &lhs, const StrVec &rhs);

public: // the allocator member is default initialized
  StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(const initializer_list<string> &il){
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
  }

  StrVec(const StrVec&); // copy constructor
  StrVec &operator=(const StrVec&); // copy assignment
  StrVec(StrVec&&) noexcept;
  StrVec &operator=(StrVec &&) noexcept;
  ~StrVec(); // destructor
  void push_back(const std::string&); // copy the element
  void push_back(std::string&&);
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
  std::string *begin() const { return elements; }
  std::string *end() const { return first_free; }
  void reserve(size_t n);
  void resize(size_t n, const string &s);
// ...
private:
  std::allocator<std::string> alloc; // allocates the elements
  // used by the functions that add elements to the StrVec
  void chk_n_alloc(){ if (size() == capacity()) reallocate(); }
  // utilities used by the copy constructor, assignment operator, and destructor
  std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
  void free(); // destroy the elements and free the space
  void reallocate(); // get more space and copy the existing elements
  void reallocate_v2();
  std::string *elements; // pointer to the first element in the array
  std::string *first_free; // pointer to the first free element in the array
  std::string *cap; // pointer to one past the end of the array
};


void StrVec::push_back(const string& s)
{
  chk_n_alloc(); // ensure that there is room for another element
  // construct a copy of s in the element to which first_free points
  alloc.construct(first_free++, s);
}

void StrVec::push_back(string &&s){
  chk_n_alloc(); // reallocates the StrVec if necessary
  alloc.construct(first_free++, std::move(s));
}

pair<string*, string*>
StrVec::alloc_n_copy(const string *b, const string *e)
{
  // allocate space to hold as many elements as are in the range
    auto data = alloc.allocate(e - b);
  // initialize and return a pair constructed from data and
  // the value returned by uninitialized_copy
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
  // may not pass deallocate a 0 pointer; if elements is 0, there's no work to do
  if (elements) {
    // destroy the old elements in reverse order
    for (auto p = first_free; p != elements; /* empty */)
      alloc.destroy(--p);
    alloc.deallocate(elements, cap - elements);
  }
}


StrVec::StrVec(const StrVec &s)
{
  // call alloc_n_copy to allocate exactly as many elements as in s
  auto newdata = alloc_n_copy(s.begin(), s.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
  cout << "StrVec(const StrVec &s)" << endl;
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
  // call alloc_n_copy to allocate exactly as many elements as in rhs
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  cout << "operator=(const StrVec &rhs)" << endl;
  return *this;
}

StrVec::~StrVec() { free(); }

void StrVec::reallocate()
{
  // we'll allocate space for twice as many elements as the current size
  auto newcapacity = size() ? 2 * size() : 1;
  // allocate new memory
  auto newdata = alloc.allocate(newcapacity);
  // move the data from the old memory to the new
  auto dest = newdata; // points to the next free position in the new array
  auto elem = elements; // points to the next element in the old array
  for (size_t i = 0; i != size(); ++i)
    alloc.construct(dest++, std::move(*elem++));
  free(); // free the old space once we've moved the elements
    // update our data structure to point to the new elements
  elements = newdata;
  first_free = dest;
  cap = elements + newcapacity;
}

void StrVec::reallocate_v2(){
  // allocate space for twice as many elements as the current size
  auto newcapacity = size() ? 2 * size() : 1;
  auto first = alloc.allocate(newcapacity);
  auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);
  free();
  elements = first;
  first_free = last;
  cap = elements + newcapacity;
}

StrVec::StrVec(StrVec &&s) noexcept : elements(s.elements),
first_free(s.first_free), cap(s.cap){
  s.elements = s.first_free = s.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
  // direct test for self-assignment
  if (this != &rhs) {
    free(); // free existing elements
    elements = rhs.elements; // take over resources from rhs
    first_free = rhs.first_free;
    cap = rhs.cap;
    // leave rhs in a destructible state
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
  }
  return *this;
}

bool operator==(const StrVec &lhs, const StrVec &rhs){
  return lhs.elements == rhs.elements && lhs.first_free == rhs.first_free
          && lhs.cap == rhs.cap;
}

bool operator!=(const StrVec &lhs, const StrVec &rhs){
  return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs){
  for(auto p1 = lhs.begin(), p2 = rhs.begin(); p1 != lhs.end(), p2 != rhs.end(); ++p1, ++p2){
    if(*p1 < *p2)
      return true;
    else
      return false;
  }
}

class String{
  friend bool operator==(const String &lhs, const String &rhs);
  friend bool operator!=(const String &lhs, const String &rhs);
  friend bool operator<(const String &lhs, const String &rhs);

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
  String(String &&) noexcept;
  String &operator=(String &&) noexcept;

  char& operator[](size_t n){
    return start[n];
  }

  const char& operator[](size_t n) const {
    return start[n];
  }

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

String::String(String &&s) noexcept : start(s.start),
first_free(s.first_free), cap(s.cap){
  s.start = s.first_free = s.cap = nullptr;
  cout << "String(String &&s)" << endl;
}

String& String::operator=(String &&rhs) noexcept{
  if(this != &rhs){
    free();
    start = rhs.start;
    first_free = rhs.first_free;
    cap = rhs.cap;
    rhs.start = rhs.first_free = rhs.cap = nullptr;
  }
  cout << "String &operator=(String &&)" << endl;
  return *this;
}

bool operator==(const String &lhs, const String &rhs){
  return lhs.start == rhs.start && lhs.first_free == rhs.first_free
          && lhs.cap == rhs.cap;
}

bool operator!=(const String &lhs, const String &rhs){
  return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs){
  for(auto p1 = lhs.begin(), p2 = rhs.begin(); p1 != lhs.end(), p2 != rhs.end(); ++p1, ++p2){
    if(*p1 < *p2)
      return true;
    else
      return false;
  }
}

int main(int argc, char const *argv[]) {
  StrBlob b1 = {"a", "an", "the"};
  StrBlob b2 = {"a", "an", "the"};
  //b1 = b2;
  //b1.push_back("about");
  cout << (b1 == b2) << endl;
  //for(const auto &i : *(b2.data))
    //cout << i << endl;

  // for(auto p = b1.begin(); ; p.incr())
  //   cout << p.deref() << " ";
  cout << endl;
  StrVec sv1({"the", "quick", "red", "fox"});
  StrVec sv2{"jumps", "over", "the"};
  StrVec sv3= {"slow", "red", "turtle"};
  cout << (sv1 < sv2) << endl;
  cout << (sv2 < sv1) << endl;
  return 0;
}
