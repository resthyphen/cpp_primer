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

int main(int argc, char const *argv[]) {
  using line_no = std::vector<std::string>::size_type;
  map<string, size_t> word_count;
  map<string, set<line_no> > word_line;
  map<pair<string, size_t>, set<line_no> > wm;
  ifstream is(argv[1]);
  vector<string> file;
  string text;
  while (getline(is, text)) {
    file.push_back(text);
    int n = file.size() - 1;
    istringstream line(text);
    string word;
    while(line >> word){
      // if(ispunct(word[0]))
      //   word.erase(word.begin());
      // if(ispunct(word[word.size() - 1]))
      //   word.pop_back();
      auto i = word.begin();
      while (i != word.end()) {
        if(ispunct(*i))
          i = word.erase(i);
        else
          ++i;
      }
      ++word_count[word];
      word_line[word].insert(n);
    }
  }

  for(auto &w : word_count)
    wm.insert({w, word_line[w.first]});

  // for(const auto &w : wm)
  //   cout << w.first.first << " occurs " << w.first.second
  //       << ((w.first.second > 1) ? " times" : " time") << endl;

  string qw;
  cin >> qw;
  auto iter = find_if(wm.begin(), wm.end(),
                      [qw](const pair<pair<string, size_t>, set<line_no> > w){
                              return w.first.first == qw;
                      });

  if(iter != wm.end())
    cout << (*iter).first.first << " occurs " << (*iter).first.second
         << (((*iter).first.second > 1) ? " times" : " time") << endl;

  for (auto num : iter->second) // for every element in the set
    // don't confound the user with text lines starting at 0
    cout << "\t(line " << num + 1 << ") "
      << *(file.begin() + num) << endl;
  return 0;
}
