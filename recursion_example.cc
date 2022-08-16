#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <memory>
#include <initializer_list>
#include <functional>
#include <stdexcept>
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
using std::initializer_list;
using std::shared_ptr;
using std::weak_ptr;
using namespace std::placeholders;
//using namespace std;
using std::to_string;

int eval(vector<string> exp){
  auto i = exp.begin();
  int r = 0;                //result
  int tmpr = 0;                 //temporary result
  int n = 0;                //use to store the number in the vector
  string o = "";            //operator
  bool first = false;       //whether the first number has been processed in r
  //vector<string>::iterator enter, exit;
  vector<string> subexp;
  while (i != exp.end()) {
    string value = *i;
    if(value.find_first_of("+-*/()") != string::npos)
      o = value;

    if(o[0] == '(' && first == true){
      //cout << *i << endl;
       // while(!subexp.empty())
       //   subexp.pop_back();

      subexp.push_back(to_string(r));
      subexp.push_back(*(i-1));
      o = "";
      first = false;

    }

    if(o[0] == ')'){
      // while(!subexp.empty())
      //   subexp.pop_back();
      tmpr = r;
      cout << tmpr << endl;
      subexp.push_back(to_string(tmpr));
      r = eval(subexp);
      o = "";
    }

    if(value.find_first_of("0123456789") != string::npos){
      n = stoi(value);
      if(first == false){
        first = true;       //sign that the first number has been put in r
        r = n;
      }
      //cout << n << endl;
      if(o != ""){
        switch (o[0]) {
          case '+': r += n; break;
          case '-': r -= n; break;
          case '*': r *= n; break;
          case '/': r /= n; break;
          // case '(':
          //   subexp.push_back(to_string(r));
          //   subexp.push_back(*(i-2));
          //   r = n;
          //   break;
          // case ')':
          //   tmpr = r;
          //   subexp.push_back(to_string(tmpr));
          //   r = eval(subexp);
          //   break;
          default: break;
        }
      }
      //cout << r << endl;
      o = "";
    }
    ++i;
  }
  for(auto i : subexp)
    cout << i;
  cout << endl;
  return r;
}

int main(int argc, char const *argv[]) {
  string s;
  vector<string> exp;
  string tmp = "";
  while (getline(cin, s)) {
    for(int i = 0; i != s.size(); ++i){
      string sub = s.substr(i,1);
      if(sub != " " && (sub.find_first_of("+-*/()") == string::npos)){  //just add number to vector
        //cout << sub << endl;
        tmp += sub;       //combine the every consecutive digit character
      }
      else{
        //cout << tmp << endl;
        if(tmp != "")
          exp.push_back(tmp);
        if(sub.find_first_of("+-*/()") != string::npos)   //push operator onto vector
          exp.push_back(sub);
        tmp = "";
      }
    }
    exp.push_back(tmp);     //rememeber to push last number
  }

  // cout << exp.size() << endl;    //new line will be counted into the size
  // cout << exp[6] << endl;
  int r = eval(exp);
  cout << r << endl;
  return 0;
}
