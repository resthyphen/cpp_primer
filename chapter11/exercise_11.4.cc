#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
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

int main(int argc, char const *argv[]) {
  map<string, size_t> word_count;
  set<string> exclude = {"The", "But", "And", "Or", "An", "A""the", "but", "and", "or", "an", "a"};
  string word;
  while(cin >> word){
    if(ispunct(word[0]))
      word.erase(0, 1);
    word[0] = tolower(word[0]);
    if(ispunct(word[word.size() - 1]))
      word.erase(word.size() - 1);
    if(ispunct(word[word.size() - 1]))
      word.erase(word.size() - 1);
    if (exclude.find(word) == exclude.end())
      ++word_count[word];
  }

  for(const auto &w : word_count)
    cout << w.first << " occurs " << w.second
         << ((w.second > 1) ? " times" : " time") << endl;


  return 0;
}
