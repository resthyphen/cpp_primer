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
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <bitset>
#include <regex>
#include <random>
#include <iomanip>
#include <cstdlib>
#include <typeinfo>
#include <cmath>
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
using std::ostringstream;
using std::hash;
using std::unordered_multiset;
using std::tuple;
using std::make_tuple;
using std::get;
using std::make_pair;
using std::bitset;
using std::regex;
using std::smatch;
using std::regex_error;
using std::sregex_iterator;
using std::regex_iterator;
using std::cregex_iterator;
using namespace std::regex_constants;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::uniform_real_distribution;
using std::normal_distribution;
using std::bernoulli_distribution;
using std::noskipws;
using std::uppercase;
using std::showbase;
using std::scientific;
using std::fixed;
using std::hexfloat;
using std::defaultfloat;
using std::right;
using std::setw;
using std::fstream;
using std::bad_alloc;
using std::bad_cast;
using std::function;
using std::mem_fn;

int n = 0;


void element(vector<int> v){
  ++n;
  if(n >= 5)
    return;
  for(size_t i = 0; i != v.size(); ++i){
    cout << v[i] << " ";
    //element(v);
  }
  cout << endl;
  element(v);
}

// list all probability of the given set that in different numnber of elements of subcontainer
// a is used to stored permutations of different cardinality that using elements in vector v
void loopv(vector<vector<int>> &a, vector<int> v){      
 ++n;
 if(n >= v.size())         //contain 5 elements
  return;

  bool repeat = false;      
 
 int size = a.size();
 for(size_t i = 0; i != size; ++i){     //traverse elements in a
   //vector<int> subv{a[i]};
   auto end = a.end();
   for(size_t j = 0; j != v.size(); ++j){        
    //cout << "element(a, v)" << endl;
    vector<int> temp = a[i];
    for(auto iter = temp.begin(); iter!= temp.end(); ++iter){   // compare each element in temp to v[j], check that wether it is repeated(equal)
        if(*iter == v[j])
            repeat = true;
    }
    if(repeat == true){
        repeat = false;
        continue;
    }

    temp.push_back(v[j]);
    sort(temp.begin(), temp.end());
    for(size_t k = 0; k!= a.size(); ++k){   // compare each element in a to temp, check that wether it is repeated(equal)
        if (a[k] == temp)
            repeat = true;
    }
    if(repeat == true){
        repeat = false;
        continue;
    }

    a.push_back(temp);
   }
 }
 loopv(a, v);
}


void loopv2(vector<vector<int>> &a, vector<int> v){    // list all probability of the given set that in different numnber of elements of subcontainer
 ++n;
 if(n >= 5)         //contain 5 elements
  return;

  bool repeat = false;
 
 int size = a.size();
 for(size_t i = 0; i != size; ++i){
   //vector<int> subv{a[i]};
   auto end = a.end();
   for(size_t j = 0; j != v.size(); ++j){
    //cout << "element(a, v)" << endl;
    vector<int> temp = a[i];
    for(auto iter = temp.begin(); iter!= temp.end(); ++iter){
        if(*iter == v[j])
            repeat = true;
    }
    if(repeat == true){
        repeat = false;
        continue;
    }

    temp.push_back(v[j]);
    for(size_t k = 0; k!= size; ++k){
        if (a[k] == temp)
            repeat = true;
    }
    if(repeat == true){
        repeat = false;
        continue;
    }

    a.push_back(temp);
    // auto e = a.begin() + i;
    // a.erase(e);
   }
 }
 loopv2(a, v);
}


// use set<set<int>> &subsets to store all subsets of set, the subsets need to be initiated by v.size() subsets that
// each size of subset is 1 and put the elements of v to each subset respectively
// void powerset(set<set<int>> &subsets, vector<int> v){
//  ++n;
//  //if(n >= 5)     //this is gained by the experiment
//  if(subsets.size() == pow(2, v.size()) - 1)    
//  {            
//   subsets.insert(set<int>{});
//   return;
//  }
 
//  auto end = subsets.end();
//  for(auto iter = subsets.begin(); iter != end; ++iter){ // traverse subsets and copy each element
//    //vector<int> subv{a[i]};
//    for(size_t j = 0; j != v.size(); ++j){  // temp is a copy of the element in subsets, spread each element of subsets 
//     //cout << "element(a, v)" << endl;     // to find all permutation of subsets with different cardinality by adding v[j] to temp
//     set<int> temp = *iter;  
//     temp.insert(v[j]);
//     subsets.insert(temp);
//     //cout << a.size() << endl;
//    }
    
//  }
//  powerset(subsets, v);

// }

// use set<set<int>> &subsets to store all subsets of set, the subsets need to be initiated by v.size() subsets that
// each size of subset is 1 and put the elements of v to each subset respectively
template <typename T>
void powerset(set<set<T>> &subsets, vector<T> v){
//  ++n;
//  if(n > 1)     //this is gained by the experiment
//  //if(subsets.size() == pow(2, v.size()) - 1)    
//  {            
//   subsets.insert(set<T>{});
//   return;
//  }
 
 //auto end = subsets.end();
 for(auto iter = subsets.begin(); iter != subsets.end(); ++iter){ // traverse subsets and copy each element
   //vector<int> subv{a[i]};
   for(size_t j = 0; j != v.size(); ++j){  // temp is a copy of the element in subsets, expand each element of subsets 
    //cout << "powerset(set<set<T>> &subsets, vector<T> v)" << endl;     // to find all permutation of subsets with different cardinality by adding v[j] to temp
    set<T> temp = *iter;  
    temp.insert(v[j]);
    subsets.insert(temp);
    //cout << a.size() << endl;
   }
   //break;
   
 }
//  for(auto iter2 = end->begin(); iter2 != end->end(); ++iter2){
//      cout << *iter2 << " ";
//  cout << endl;
//  }

 //powerset(subsets, v);

}

int main(int argc, char const *argv[]) {
  //vector<int> v = {1, 2, 3, 4, 5,6, 7 ,8 ,9, 11,10, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  //vector<int> v{94, 34, 90, 68, 67, 100, 59, 45, 86, 24, 99, 0, 48, 29, 35, 7, 96, 57, 64, 92};
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  //vector<int> v = {1, 2, 3, 4, 5};
  //vector<char> v = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
  default_random_engine e(time(0));
  uniform_int_distribution<unsigned> u(0,100);
//   vector<int> v;
//   for (size_t i = 0; i != 20; ++i)
//     v.push_back(u(e));
  
//   for(auto iter = v.begin(); iter != v.end(); ++iter)
//     cout << *iter << ", ";
//   cout << endl;
  size_t count = 0;
  set<set<int>> subsets;
  //set<set<char>> subsets;
  vector<vector<int>> a;
  for(size_t i = 0; i != v.size(); ++i)
    a.push_back(vector<int> {v[i]});

  //loopv2(a, v);
//   vector<char> cv = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
//   set<set<int>> subsets;

  cout << a.size() << endl;

  cout << endl;

  loopv(a, v);

  for(auto iter = a.begin(); iter != a.end(); ++iter){
      // if(iter->size() == 5)
      //  ++count;
      for(auto i = iter->begin(); i != iter-> end(); ++i)
        cout << *i << " " ;
      cout << endl;
    }

//   cout << count << endl;

  // for(size_t i = 0; i != v.size(); ++i){
  //   set<int> s({v[i]});
  //   subsets.insert(s);
  // }

  // cout << subsets.size() << endl;

  // powerset(subsets, v);

  // cout << subsets.size() << endl;
  // cout << endl;

  // for(auto iter = subsets.begin(); iter != subsets.end(); ++iter){
  //     for(auto i = iter->begin(); i != iter-> end(); ++i)
  //       cout << *i << " " ;
  //     cout << endl;
  //   }

  
  return 0;
}