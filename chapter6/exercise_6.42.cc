#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

string make_plural(size_t ctr, const string &word = "s", const string &ending = "s"){
  return (ctr > 1) ? word + ending : word;
}

int main(int argc, char const *argv[]) {
  int ctr;
  string word;
  string temp;
  cin >> word;
  temp = word;
  while(cin >> word){
    if (temp == word)
      ++ctr;
    else{
      temp = word;
      ctr = 1;
    }
    cout << make_plural(ctr, word, "s") << endl;
  }
  return 0;
}
