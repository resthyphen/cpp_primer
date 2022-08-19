#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <forward_list>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;
using std::array;
using std::forward_list;

int main(int argc, char const *argv[]) {
  vector<string> svec;
  string word;
  svec.reserve(1024);
  cout << "ivec: size: " << svec.size()
       << " capacity: " << svec.capacity() << endl;
//  while (cin >> word)
//     svec.push_back(word);
  for(size_t i = 1; i <= 256; ++i)
    svec.push_back("word");
  svec.resize(svec.size()+svec.size()/2);
  cout << "ivec: size: " << svec.size()
       << " capacity: " << svec.capacity() << endl;
  return 0;
}
