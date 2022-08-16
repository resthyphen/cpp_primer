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

void loopv(vector<vector<int>> &a, vector<int> v){
 ++n;
 if(n >= 5){
  a.insert(a.end(), vector<int>{});
  return;
 }

  bool repeat = false;

 int size = a.size();
 for(size_t i = 0; i != size; ++i){     //traverse elements in a
   //vector<int> subv{a[i]};
   auto end = a.end();
   for(size_t j = 0; j != v.size(); ++j){
    //cout << "loopv(vector<vector<int>> &a, vector<int> v)" << endl;
    vector<int> temp = a[i];
    for(auto iter = temp.begin(); iter!= temp.end(); ++iter){   // compare each element in temp to v[j], check that wether it is repeated(equal)
        if(*iter == v[j]) 
            repeat = true;
    }
    if(repeat == true){
        repeat = false;
        continue;
    }

    //temp.push_back(v[j]);
    temp.insert(temp.end(), {v[j]});
    //sort(temp.begin(), temp.end());
    // for(size_t k = 0; k!= a.size(); ++k){   // compare each element in a to temp, check that wether it is repeated(equal)
    //     if (a[k] == temp)
    //         repeat = true;
    // }
    // if(repeat == true){
    //     repeat = false;
    //     continue;
    // }

    a.push_back(temp);

   }
   //cout << a.size() << endl;
 }
 loopv(a, v);
}

//a is used to stored all vectors of permutation
//p is each probability of permutation
//v is original vector that in each recursion we will cut the size of v
void getPermutations(vector<int> v, vector<int> p, vector<vector<int>> &a){
  if(v.size() <= 1){          //if v.size() less than 1, end recursion
    p.push_back(*v.begin());
    a.push_back(p);
    // for(auto iter = p.begin(); iter != p.end(); ++iter)
    //   cout << *iter <<" ";
    // cout << endl;
    return;
  }
  for(size_t i = 0; i != v.size(); ++i){
    p.push_back(v[i]);          //traverse each element of v and expand it to find all possibility and add it to the p
    vector<int> cv = v;         //cv is copy of v and gurantee that we erase different element of v in each recursion
    cv.erase(cv.begin() + i);    
    getPermutations(cv, p, a);
    p.erase(p.end() - 1);      //we need to delete the last element which we just added in order to choose next 
                               //different element because different number will form different permutation
  }
}



int main(int argc, char const *argv[]) {
  //vector<int> v = {1, 2, 3, 4, 5};
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<vector<int>> a;
  
  vector<int> p;
  getPermutations(v, p, a);
  for(auto iter = a.begin(); iter != a.end(); ++iter){
    for(auto i = iter->begin(); i != iter-> end(); ++i)
      cout << *i << " " ;
    cout << endl;
  }

  cout << a.size() << endl;
  return 0;
}
