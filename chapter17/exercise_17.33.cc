#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <memory>
#include <stdexcept>
#include <initializer_list>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <bitset>
#include <regex>
#include <random>
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
using std::exception;
using std::initializer_list;
using std::shared_ptr;
using std::weak_ptr;
using std::less;
using namespace std::placeholders;
//using namespace std;
using std::allocator;
using std::plus;
using std::begin;
using std::end;
using std::ostringstream;
using std::hash;
using std::unordered_multiset;
using std::tuple;
using std::make_tuple;
using std::get;
using std::make_pair;
using std::bitset;
using std::regex;
using std::smatch;
using std::regex_error;
using std::sregex_iterator;
using std::regex_iterator;
using std::cregex_iterator;
using namespace std::regex_constants;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::uniform_real_distribution;
using std::normal_distribution;
using std::bernoulli_distribution;

map<string, vector<string>> buildMap(ifstream &map_file);
const string &transform(const string &s, const map<string, vector<string>> &m);

void word_transform(ifstream &map_file, ifstream &input){
  auto trans_map = buildMap(map_file); // store the transformations
  string text; // hold each line from the input
  while (getline(input, text)) { // read a line of input
    istringstream stream(text); // read each word
    string word;
    bool firstword = true; // controls whether a space is printed
    while (stream >> word) {
      if (firstword)
        firstword = false;
      else
        cout << " "; // print a space between words
      // transform returns its first argument or its transformation
      cout << transform(word, trans_map); // print the output
    }
    cout << endl; // done with this line of input
  }
}

map<string, vector<string>> buildMap(ifstream &map_file){
  map<string, vector<string>> trans_map; // holds the transformations
  string key; // a word to transform
  vector<string> values;
  string line, word;
  // read the first word into key and the rest of the line into value
  while(getline(map_file, line)){
    values.clear();
    istringstream record(line);
    record >> key;
    while(record >> word)
      values.push_back(word);
    if(values.size() >= 1)
      trans_map[key] = values;
    else
      throw runtime_error("no rule for " + key);
  }
  for(auto i : trans_map){
    cout << i.first << ": " << i.second.size();
    // for(auto j : i.second)
    //   cout << j << " ";
    cout << endl;
  }
  cout << endl;
  return trans_map;
}

const string &transform(const string &s, const map<string, vector<string>> &m){
  default_random_engine e(time(0));
  // the actual map work; this part is the heart of the program
  auto map_it = m.find(s);
  // if this word is in the transformation map
  if (map_it != m.cend()){
    uniform_int_distribution<> u(0, (map_it->second).size() - 1);
    return (map_it->second)[u(e)];
  }
  else
    return s; // otherwise return the original unchanged
}

int main(int argc, char const *argv[]) {
  ifstream in1(argv[1]), in2(argv[2]);
  word_transform(in1, in2);
  return 0;
}
