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

class NoDefault {
public:
  NoDefault(const std::string &s):str(s){}
  // additional members follow, but no other constructors
  string getStr() const{
    return str;
  }
private:
  string str;
};

size_t count_calls(){
  static size_t ctr = 0;  // value will persist across calls
  return ++ctr;
}

template<typename Iter>
void print(Iter beg, Iter end){
    if(beg == end)
        return;
    cout << *beg << endl;
    print(beg + 1, end);
}

constexpr int new_sz() { return 42; }

constexpr size_t scale(size_t cnt) { return new_sz() * cnt; }

template<typename ITER, typename T>
ITER bi_search(ITER b, ITER e, T sought){
  auto beg = b, end = e;
  auto mid = b + (e - b)/2;

  if(*mid == sought )
    return mid;
  //cout << *mid << endl;
  if(sought > *mid)
    bi_search(mid + 1, end, sought);
  else if(sought < *mid)
    bi_search(beg, mid - 1, sought);

}

// set<set<int>>& powerset(vector<int>::iterator begin, vector<int>::iterator end, set<set<int>> &subsets){
//   set<int> s;
//   s.insert(begin, end);

//   // for(auto i = s.begin(); i != s.end(); ++i)
//   //   cout << *i << " ";
//   // cout << endl;
//   subsets.insert(s);
//   if (end - begin == 1 || end - begin == 0){
//     subsets.insert(set<int>{});
//     //subsets.insert(set<int>{*begin});
//     return subsets;
//   }

//   powerset(begin + 1, end, subsets);
//   powerset(begin, end - 1, subsets);

// }

// set<set<int>>& powerset(vector<int> &v, set<set<int>> &subsets){
//   set<int> s;
//   s.insert({*v.begin(), *v.end()});
//   subsets.insert(s);

//   // for(auto i = s.begin(); i != s.end(); ++i)
//   //   cout << *i << " ";
//   // cout << endl;
//   if (v.size() <= 1){
//     subsets.insert(set<int>{});
//     //subsets.insert(set<int>{*begin});
//     return subsets;
//   }

//   vector<int> subv1(v.begin() + 1, v.end());
//   vector<int> subv2(v.begin(), v.end()-1);
//   powerset(subv1, subsets);
//   powerset(subv2, subsets);

// }

int n = 0;


// void element(vector<int> v){
//   ++n;
//   if(n >= 5)
//     return;
//   for(size_t i = 0; i != v.size(); ++i){
//     cout << v[i] << " ";
//     //element(v);
//   }
//   cout << endl;
//   element(v);
// }



// void element(vector<vector<int>> &a, vector<int> v){
//  ++n;
//  if(n >= 5)
//   return;

//  int size = a.size();
//  for(size_t i = 0; i != size; ++i){
//    //vector<int> subv{a[i]};
//    auto end = a.end();
//    for(size_t j = 0; j != v.size(); ++j){
//     //cout << "element(a, v)" << endl;
//     vector<int> temp = a[i];
//     temp.push_back(v[j]);
//     a.push_back(temp);
//    }
//  }
//  element(a, v);

// }

void powerset(set<set<int>> &subsets, vector<int> v){
 ++n;
 //if(n >= 2)     //this is gained by the experiment
 if(subsets.size() == pow(2, v.size()) - 1)
 {
  subsets.insert(set<int>{});
  return;
 }

 auto end = subsets.end();
 for(auto iter = subsets.begin(); iter != end; ++iter){
   //vector<int> subv{a[i]};
   for(size_t j = 0; j != v.size(); ++j){
    //cout << "element(a, v)" << endl;
    set<int> temp = *iter;
    temp.insert(v[j]);
    subsets.insert(temp);
    //cout << a.size() << endl;
   }

 }
 powerset(subsets, v);

}


// typedef struct Sales_data {
//   // new members: operations on Sales_data objects
//   std::string isbn() const { return bookNo; }
//   Sales_data& combine(const Sales_data&);
//   double avg_price() const;
//   // data members are unchanged from § 2.6.1 (p. 72)
//   string bookNo;
//   unsigned units_sold = 0;
//   double revenue = 0.0;
// }sdata, *psdata;
//
// double Sales_data::avg_price() const {
//   if (units_sold)
//     return revenue/units_sold;
//   else
//     return 0;
// }


double find_factor_reward_punish(double profit, double &l_average_profit, double &s_average_profit){
  double reward_punish_step = 0.1;
  double l_factor_attenuate = 0.9;
  double s_factor_attenuate = 0.8;
  //static double l_average_profit = profit;
  //static double s_average_profit = profit;
  double factor_reward_punish = 1;

  l_average_profit = l_average_profit * l_factor_attenuate + profit * (1-l_factor_attenuate);
  s_average_profit = s_average_profit * s_factor_attenuate + profit * (1-s_factor_attenuate);

  if(l_average_profit < 0 || s_average_profit < 0){
    factor_reward_punish = 0;
    return factor_reward_punish;
  }
  else if(s_average_profit > l_average_profit && profit > 0){
    factor_reward_punish += reward_punish_step;
    return factor_reward_punish > 1 ?  1 : factor_reward_punish;
  }
  else if(s_average_profit < l_average_profit && profit < 0){
    factor_reward_punish -= reward_punish_step;
    return factor_reward_punish < 0 ?  0 : factor_reward_punish;
  }
  else
    return factor_reward_punish;
}



int main(int argc, char const *argv[]) {
  vector<double> profits{10, 2, 3, 4, 35, 32, 3, 28, 25, 20, 13, 10};
  //double factor_reward_punish = 1;
  double l_average_profit = 0;
  double s_average_profit = 0;
  for(auto iter = profits.begin(); iter != profits.end(); ++iter){
    cout << find_factor_reward_punish(*iter, l_average_profit, s_average_profit) << endl;
  }
  return 0;
}
