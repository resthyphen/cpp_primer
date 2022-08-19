#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <numeric>
#include "Sales_item.h"
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::istream;
using std::ostream;
using std::istream_iterator;
using std::ostream_iterator;

int main(int argc, char const *argv[]) {
    istream_iterator<Sales_item> item_iter(cin), eof;
    vector<Sales_item> v(item_iter, eof);
    sort(v.begin(), v.end(), compareIsbn);
    for(auto i : v)
      cout << i << endl;

    cout << endl;
    auto iter = v.begin();
    auto tmp = iter;
    auto sum = *iter;
    auto result = v.begin();
    while (iter != v.end()) {
      for(tmp = iter; tmp != v.end(); ++tmp){
        result = find(tmp, v.end(), *iter);
        if(result == v.end()){
          //sum = accumulate(iter + 1, tmp, *iter);
          //cout << sum << endl;
          break;
        }
      }
      sum = accumulate(iter + 1, tmp, *iter);
      cout << sum << endl;
      iter = tmp;

    }
      //cout << sum << endl;
      return 0;
}
