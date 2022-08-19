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

 //this funcion is used for processing the precedence of operator,
 //assume that there are no more brace in the expression;
int precedence_cal(vector<string> exp){
  auto i = exp.begin();
  vector<string> subexp;        //store the elements in the brace of the orgina;
  int lhs, rhs;                 //left hand side, righ hand side
  int tmpr;                     //temporary result
  while(i != exp.end()){        // '*', '/' operator will be processed priorly
    if((*i)[0] == '*'){
      lhs = stoi(*(i - 1));
      rhs = stoi(*(i + 1));
      tmpr = lhs * rhs;
      i = exp.erase(i - 1, i + 2);          //remove the binary operator expression
      exp.insert(i, to_string(tmpr));       //use the temporary result replace it

    }
    else if((*i)[0] == '/'){
      lhs = stoi(*(i - 1));
      rhs = stoi(*(i + 1));
      tmpr = lhs / rhs;
      i = exp.erase(i - 1, i + 2);
      exp.insert(i, to_string(tmpr));

    }
    ++i;
  }

  // for(auto i : exp)
  //   cout << i;
  // cout << endl;

  i = exp.begin();
  int r = 0;                //result
  int n = 0;                //use to store the number in the vector
  string o = "";            //operator
  bool first = false;       //whether the first number has been processed in r
  while(i != exp.end()){
    string value = *i;
    if(value.find_first_of("+-*/()") != string::npos && value.size() == 1)
      o = value;

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
          default: break;
        }
      }
      //cout << r << endl;
      o = "";
    }
    ++i;
  }
  return r;
}

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
    if(*i == ")"){
      while(!subexp.empty())
         subexp.pop_back();
      auto j = i;
      for(; j != exp.begin() - 1; --j){
        if(*j == "(")
          break;
      }
      auto tmpi = j + 1;
      while(tmpi != i){
        subexp.push_back(*tmpi);
        ++tmpi;
    }
    tmpr = precedence_cal(subexp);
    i = exp.erase(j, i + 1);
    exp.insert(i, to_string(tmpr));
    }
    ++i;
  }

  for(auto i : exp)
     cout << i;
   cout << endl;

   r = precedence_cal(exp);
  return r;
}


// separate the numberic character and operator character, use vector to store them respectively
vector<string> separater(string s){
  vector<string> exp;
  string tmp = "";
  for(int i = 0; i != s.size(); ++i){
    string sub = s.substr(i,1);
    if(sub != " " && (sub.find_first_of("+-*/()") == string::npos)){  //just add number to vector
      //cout << sub << endl;
      tmp += sub;       //combine the every successive numberic character until encounters a operator
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
  return exp;
}

int main(int argc, char const *argv[]) {
  string s;
  getline(cin, s);
  vector<string> exp;
  exp = separater(s);
  int r = eval(exp);
  cout << r << endl;
  return 0;
}
