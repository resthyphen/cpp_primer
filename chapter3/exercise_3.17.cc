#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  vector<string> words;
  string word;
  while(cin >> word)
    words.push_back(word);
  int i = 0;
  while(i < words.size()){
    if((i+1) % 8 == 0)
      cout << words[i] << endl;
    else
      cout << words[i] << " ";
    ++i;
  }
  return 0;
}
