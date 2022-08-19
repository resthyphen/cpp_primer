#include<iostream>
#include<string>
#include<vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  vector<string> v;
  vector<string> repWords;              //repeated words
  string s;
  while (cin >> s) {
    v.push_back(s);
  }
  auto beg = v.begin();
/*  while (beg != v.end()) {
    cout << *beg << " ";
    ++beg;
  }*/
  repWords.push_back(*beg);                     //store first word
   while (beg != v.end()) {
      auto temp = *beg;                         //store current word
      ++beg;
      if(*beg != temp){
        auto beg2 = repWords.begin();          //using current word compare with word which in repWords
        while(beg2 != repWords.end()){
          if(*beg2 == temp)
            break;
          ++beg2;
        }
        if(beg2 == repWords.end())            //if doesn't found in repWords, adding it to repWords
          repWords.push_back(temp);
      }

    }
  beg = repWords.begin();
  while(beg != repWords.end()){
    cout << *beg << " ";
    ++beg;
  }
  cout << endl;

  const auto n = repWords.size();
  int cnt[n] = {0};                             //creating arrary to store the repeating times of each word
  int i = 0;                                    //in repWords.(e.g. cnt[0] for repWords[0], cnt[1] for repWords[1]. etc.)
  while (i != n){
    beg = v.begin();
    while(beg != v.end()){                      //finding repeating words in v
      if(*beg == repWords[i]){
        ++cnt[i];
      }
      ++beg;
    }
    ++i;
  }

  i = 0;
  while (i != n) {
    cout << repWords[i] << " occurs " << cnt[i] << " times\n";
    ++i;
  }

//cout << repWords[0];
cout << endl;
  return 0;
}
