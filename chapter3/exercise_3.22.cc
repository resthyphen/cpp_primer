#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  vector<string> text;
  string p;
  while(getline(cin, p))
    text.push_back(p);
  //for(int i = 0; i < text.size(); ++i)
    //cout << text[i] << endl;
  for(auto it = text.begin(); it != text.end() && !it->empty(); ++it)
    cout << *it << endl;
  //auto it = text.empty();
  //cout <<it << endl;

  return 0;
}
