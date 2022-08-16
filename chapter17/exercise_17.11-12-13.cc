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

template <size_t N> struct QuizResponses{
  QuizResponses() = default;
  QuizResponses(const string& s) : answers(s){}
  void answer(size_t n, bool v) {
    answers.set(n - 1, v);
  }

  int score(const QuizResponses& correct){
    return (answers ^ correct.answers).flip().count() * 1.0 / N * 100;
  }
  
  bitset<N> answers;
};

int main(int argc, char const *argv[]) {
  QuizResponses<10> correct("1011010110");
  cout << correct.answers << endl;
  string s;
  cin >> s;
  QuizResponses<10> qr(s);
  //qr.answer(1, true);
  cout << qr.score(correct) << endl;

  return 0;
}
