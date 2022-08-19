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

void loopv(vector<vector<int>> &a, vector<int> v){
 // ++n;
 // if(n >= 20){
 //  a.insert(a.end(), vector<int>{});
 //  return;
 // }

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

    temp.push_back(v[j]);

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
   cout << a.size() << endl;
 }
 loopv(a, v);
}

vector<int> f(vector<int> v){
  return vector<int> {*v.begin()};
}


int main(int argc, char const *argv[]) {
  vector<int> v = {1, 2, 3, 4, 5};
  v.insert(v.begin()+1, 42);
  vector<int> p{34};
  // p.insert(p.end(), v.begin(), v.end());
  p = f(v);
  for(auto iter =p.begin(); iter != p.end(); ++iter)
    cout << *iter <<" ";
  cout << endl;
  return 0;
}
