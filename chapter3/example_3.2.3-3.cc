#include<iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main(int argc, char const *argv[]) {
  const string hexdigits = "0123456789ABCDEF";
  string result;
  cout << "Enter a series of numbers between 0 and 15"
       << " separated by spaces. Hit ENTER when finished: "
       << endl;
  string::size_type n;
  while(cin >> n)
    if(n < hexdigits.size())
      result += hexdigits[n];
  cout << "Your hex number is: " << result << endl;
  return 0;
}
