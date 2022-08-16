#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <array>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::ifstream;
using std::list;
using std::array;

int main(int argc, char const *argv[]) {
  ifstream in(argv[1]);
  vector<string> v;
  vector<string> v2;      //storing word that contains neither ascenders nor descenders
  if(in){
    string word;
    while(in >> word)
      v.push_back(word);
  }else
    cerr << "couldn't open the f" << endl;
  in.close();
  cout << v.size() << endl;

  string ascender = "bdfhijklt", descender = "gjpqy";

  auto iter = v.begin();
  string::size_type pos;
  while(iter != v.end()){
    auto s = *iter;
    if(s.find_first_of(ascender) == string::npos &&
        s.find_first_of(descender) == string::npos)
      v2.push_back(s);
    ++iter;
  }

  if(v2.size() == 0)
    cout << "There is no word contains neither ascenders nor descenders" << endl;

  iter = v2.begin();
  string::size_type maxSize = 0;
  string word;
  while(iter != v2.end()){
    if((*iter).size() > maxSize){
      maxSize = (*iter).size();
      word = *iter;
    }
    ++iter;
  }

  cout << word <<":" << maxSize << endl;

  return 0;
}
