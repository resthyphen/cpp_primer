#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <stack>
#include <deque>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;
using std::array;
using std::to_string;
using std::stack;
using std::deque;
using std::stoi;

int main(int argc, char const *argv[]) {
  stack<string> expStack;



  string s;
  while(getline(cin, s)){
    for(int i = s.size() - 1; i >= 0; --i){
      string sub = s.substr(i, 1);            //seperate to substring as a char
      if(sub != " ")
        expStack.push(sub);
    }
  }
    /*
  cout << expression.size() << endl;
  for(int i = expression.size() - 1; i >= 0; --i){
    cout << expression[i] << endl;
    if(expression[i] != ' '){
      char e = expression[i];
      expStack.push(e);
    }
  }*/


  string::size_type pos;
  int r = 0;                //result
  int n = 0;
  string t = "";
  string o = "";            //operator
  bool b = false;

  while(!expStack.empty()){
    string value = expStack.top();
    if(value.find_first_of("+-*/") != string::npos){
      o = value;
    }
    if(value.find_first_of("0123456789") != string::npos){
      n = stoi(value);
      if(b == false){
        b = true;
        r = n;
      }
      //cout << n << endl;
      if(o != ""){
        switch (o[0]) {
          case '+': r += n; break;
          case '-': r -= n; break;
          case '*': r *= n; break;
          case '/': r /= n; break;
          default: break;
        }
      }
      //cout << r << endl;
      o = "";
    }
    expStack.pop();
  }
  cout << r << endl;
  return 0;
}
