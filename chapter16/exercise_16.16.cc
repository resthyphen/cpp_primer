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

template <typename T> class Vec{
public:
  Vec():elements(nullptr), first_free(nullptr), cap(nullptr) {}
  Vec(initializer_list<T> il){
    cout << "Vec(initializer_list<T> il)" << endl;
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
  }

  T& operator[](size_t n){
    return elements[n];
  }

  const T& operator[](size_t n) const {
    return elements[n];
  }

  Vec(const Vec<T>&); // copy constructor
  Vec &operator=(const Vec<T>&); // copy assignment
  Vec &operator=(initializer_list<T> il);
  Vec(Vec<T>&&) noexcept;
  Vec &operator=(Vec<T> &&) noexcept;
  ~Vec();
  void push_back(const T&); // copy the element
  void push_back(T&&);
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
  T *begin() const { return elements; }
  T *end() const {return first_free; }
  void reserve(size_t n);
  void resize(size_t n, const T &t);

private:
  allocator<T> alloc;   // allocates the elements
  // used by the functions that add elements to the Vec
  void chk_n_alloc(){ if (size() == capacity()) reallocate(); }
  // utilities used by the copy constructor, assignment operator, and destructor
  pair<T*, T*> alloc_n_copy(const T*, const T*);
  void free();
  void reallocate();  // get more space and copy the existing elements
  void reallocate_v2();
  T *elements;    // pointer to the first
  T *first_free;   // pointer to the first free element in the array
  T *cap;      // pointer to one past the end of the array
};

template <typename T>
void Vec<T>::push_back(const T& t)
{
  cout << "push_back(const T& t)" << endl;
  chk_n_alloc(); // ensure that there is room for another element
  // construct a copy of s in the element to which first_free points
  alloc.construct(first_free++, t);
}

template <typename T>
void Vec<T>::push_back(T &&t){
  cout << "push_back(T &&t)" << endl;
  chk_n_alloc(); // reallocates the StrVec if necessary
  alloc.construct(first_free++, std::move(t));
}

template <typename T>
pair<T*, T*>
Vec<T>::alloc_n_copy(const T *b, const T *e)
{
  // allocate space to hold as many elements as are in the range
    auto data = alloc.allocate(e - b);
  // initialize and return a pair constructed from data and
  // the value returned by uninitialized_copy
    return {data, uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::free()
{
  // may not pass deallocate a 0 pointer; if elements is 0, there's no work to do
  if (elements) {
    // destroy the old elements in reverse order
    for (auto p = first_free; p != elements; /* empty */)
      alloc.destroy(--p);
    alloc.deallocate(elements, cap - elements);
  }
}

template <typename T>
Vec<T>::Vec(const Vec<T> &v)
{
  // call alloc_n_copy to allocate exactly as many elements as in s
  auto newdata = alloc_n_copy(v.begin(), v.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
  cout << "StrVec(const StrVec &s)" << endl;
}

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec<T> &rhs)
{
  // call alloc_n_copy to allocate exactly as many elements as in rhs
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  cout << "operator=(const StrVec &rhs)" << endl;
  return *this;
}

template <typename T>
Vec<T> &Vec<T>::operator=(initializer_list<T> il){
  // alloc_n_copy allocates space and copies elements from the given range
  cout << "operator=(initializer_list<T> il)" << endl;
  auto data = alloc_n_copy(il.begin(), il.end());
  free(); // destroy the elements in this object and free the space
  elements = data.first; // update data members to point to the new space
  first_free = cap = data.second;
  return *this;
}

template <typename T>
Vec<T>::~Vec() { free(); }

template <typename T>
void Vec<T>::reallocate()
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

template <typename T>
void Vec<T>::reallocate_v2(){
  // allocate space for twice as many elements as the current size
  auto newcapacity = size() ? 2 * size() : 1;
  auto first = alloc.allocate(newcapacity);
  auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);
  free();
  elements = first;
  first_free = last;
  cap = elements + newcapacity;
}

template <typename T>
Vec<T>::Vec(Vec<T> &&v) noexcept : elements(v.elements),
first_free(v.first_free), cap(v.cap){
  cout << "Vec(Vec &&v)" << endl;
  v.elements = v.first_free = v.cap = nullptr;
}

template <typename T>
Vec<T> &Vec<T>::operator=(Vec<T> &&rhs) noexcept
{
  cout << "operator=(Vec &&rhs)" << endl;
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

template <typename T>
void Vec<T>::reserve(size_t n){
  if(n > capacity()){
    auto newcapacity = n;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
      alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
  }
}

template <typename T>
void Vec<T>::resize(size_t n, const T &t){
  if(size() > n){
    auto d = size() - n;
    for(auto p = first_free; p != first_free - 1 - d; )
      alloc.destroy(--p);
    //alloc.deallocate(first_free - d, d);
    first_free = first_free - d;
  }else{
    auto d = n - size();
    for(size_t i = 0; i != d; ++i)    //for(size_t i = size(); i != n; ++i)
      push_back(t);
      //(*this).push_back(s);
  }
}

int main(int argc, char const *argv[]) {
  Vec<string> v({"", "red", "turtle", "iufe"});
  v = {"a", "an", "the"};
  string s = "disk";
  cout << s << endl;
  v.push_back(std::move(s));
  for(auto i : v)
    cout << i << endl;
  cout << s << endl;
  return 0;
}
