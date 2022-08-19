#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <algorithm>
#include <functional>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;
using std::array;
using namespace std::placeholders;

void elimDups(vector<string> &words){
  sort(words.begin(), words.end());
  auto end_unique = unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
}

string make_plural(size_t ctr, const string &word, const string &ending){
  return (ctr > 1) ? word + ending : word;
}

bool check_size(const string &s, string::size_type sz){
   return s.size() >= sz;
 }

void biggies(vector<string> &words, vector<string>::size_type sz){
  elimDups(words); // put words in alphabetical order and remove duplicates
  // sort words by size, but maintain alphabetical order for words of the same size
  stable_sort(words.begin(), words.end(),
            [](const string &a, const string &b)
              { return a.size() < b.size();});
  // get an iterator to the first element whose size() is >= sz
  auto wc = find_if(words.begin(), words.end(),
                [sz](const string &a)
                    { return a.size() >= sz; });
  // compute the number of elements with size >= sz
  auto count = count_if(words.begin(), words.end(), bind(check_size, _1, sz));
  cout << count << " " << make_plural(count, "word", "s")
        << " of length " << sz << " or longer" << endl;
      // print words of the given size or longer, each one followed by a space
  for_each(wc, words.end(), [](const string &s)
                              {cout << s << " ";});
  cout << endl;
}

int main(int argc, char const *argv[]) {
  vector<string> words;
  string s;
  while(cin >> s){
    words.push_back(s);
  }
  biggies(words, 6);
  return 0;
}
