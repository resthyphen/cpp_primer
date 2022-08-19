#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <memory>
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
using std::istringstream;
using std::runtime_error;
using std::out_of_range;
using std::exception;
using std::allocator;
using std::shared_ptr;

class TextQuery{
public:
  TextQuery(ifstream &f);
  void query(string s){
    if((*pw).find(s) != (*pw).end()){
      cout << s << " occurs " << (*pw)[s].first << "times" << endl;
      for(const auto &i : (*pw)[s].second)
        cout << "line " << i << ": " << (*pv)[i - 1] << endl;
      }
    else
        cout << "not found" << endl;
  }

private:
  ifstream &file;
  shared_ptr<vector<string>> pv;
  //vector<string> v;
  //map<string, pair<int, set<int>>> word_count;
  shared_ptr<map<string, pair<int, set<int>>>> pw;
};

TextQuery::TextQuery(ifstream &f): file(f){
  string line, word;
  int lineno = 0;
  while(getline(f, line)){
    ++lineno;
    pv->push_back(line);
    istringstream record(line);
    while(record >> word){
      //++word_count[word].first;
      ++(*pw)[word].first;
      (*pw)[word].second.insert(lineno);
    }
  }
}

class QueryResult{

};

int main(int argc, char const *argv[]) {
  ifstream in(argv[1]);
  vector<string> v;
  vector<int> n;
  int lineno = 0;

  map<string, pair<int, set<int>>> word_count;
  string line, word;
/*  while(getline(in, line)){
    ++lineno;
    v.push_back(line);
    istringstream record(line);
    while(record >> word){
      //word_count[word].push_back(lineno);
      ++word_count[word].first;
      word_count[word].second.insert(lineno);
    }
  } */
  //for(const auto &i : v)
    //cout << i << endl;
  /*
  for(const auto &w : word_count)
    cout << w.first << " occurs " << w.second
         << ((w.second > 1) ? " times" : " time") << endl;*/

/*
  for(const auto &w : word_count){
    cout << w.first << " occurs " << w.second.first << " times"
         << " in: ";
    for(const auto &i : w.second.second)
      cout << i <<" ";
    cout << endl;
  }*/
  string s;
  cout << "enter word to look for : ";
  cin >> s;
  /*
  if(word_count.find(s) != word_count.end()){
    cout << s << " occurs " << word_count[s].first << "times" << endl;
    for(const auto &i : word_count[s].second)
      cout << "line " << i << ": " << v[i - 1] << endl;
    }
  else
      cout << "not found" << endl;
      */
    TextQuery tq(in);
    tq.query(s);
  return 0;
}
