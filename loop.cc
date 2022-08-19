#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;

vector<int> v{1,2,3,4,5,6,7,8,9};

for(auto &i : v)
  i *= i;

for(auto i : v)
  cout << i << " ";

for(decltype(v.size()) i = 0; i != 10; ++i)
  cout << i << " ";

for(auto i = v.begin(); i != v.end(); ++i)
  cout << *i << endl;

  for (auto beg = v.begin(), end = v.end(); beg != end; ++beg){
      auto &r = *beg;   // r must be a reference so we can change the element
      r *= 2;           // double the value of each element in v
}


int arr[] = {0,1,2,3,4,5,6,7,8,9};
int *e = &arr[10];
for (int *b = arr; b != e; ++b)
  cout << *b << endl;


for (size_t i = 0; i != rowCnt; ++i) {    // for each column within the row
        for (size_t j = 0; j != colCnt; ++j) {        // assign the element's positional index as its value
            ia[i][j] = i * colCnt + j;
        }
  }


for (auto p = ia; p != ia + 3; ++p) {
    // q points  to  the  first  element  of  an  array  of four ints;  that  is, q points  to  an int
    for (auto q = *p; q != *p + 4; ++q)
        cout << *q << ' ';
      cout << endl;
  }



for (auto p = begin(ia); p != end(ia); ++p) {       // q points to the first element in an inner array
    for (auto q = begin(*p); q != end(*p); ++q)
          cout << *q << ' ';   // prints  the  int  value to which q points
     cout << endl;
  }



using int_array = int[4]; // new style type alias declaration; see § 2.5.1 (p.
typedef int int_array[4]; // equivalent typedef declaration; § 2.5.1 (p. 67)
  // print the value of each element in ia, with each inner array on its own line
for (int_array *p = ia; p != ia + 3; ++p) {
  for (int *q = *p; q != *p + 4; ++q)
    cout << *q << ' ';
    cout << endl;
}



for  (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
    *it = toupper(*it);



for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index)
    s[index]  =  toupper(s[index]);



for (decltype(v.size()) i = 0, sz = v.size(); i != sz; ++i)
    v.push_back(v[i]);



int *beg = begin(ia); // pointer to the first element in ia
int *last = end(ia);  // pointer one past the last element in ia
int *pbeg = begin(arr),  *pend = end(arr);
while (pbeg != pend && *pbeg >= 0)
  ++pbeg;



auto pbeg = v.begin();
while (pbeg != v.end() && *beg >= 0)
  cout << *pbeg++ << endl;      // print the current value and advance pbeg



for (auto beg = authors.lower_bound(search_item), end = authors.upper_bound(search_item); beg != end; ++beg)
        cout << beg->second << endl;


for (auto pos = authors.equal_range(search_item); pos.first != pos.second; ++pos.first)
        cout << pos.first->second << endl;



vector<int> v;
for (int i; cin >> i; /* no expression */ )
          v.push_back(i);

for (int i; cin >> i; v.push_back(i))
  ;


for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it){
  // check whether the number's formatting is valid
  if (valid(*it))       //dereference the iterator, we get an smatch object representing the current match
    cout << "valid: " << it->str() << endl;
  else
    cout << "not valid: " << it->str() << endl;
}
