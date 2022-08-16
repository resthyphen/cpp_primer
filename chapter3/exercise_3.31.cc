#include<iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main(int argc, char const *argv[]) {
  int arr[10];
  for(int i = 0; i < 10; ++i )
    arr[i] = i;
  for(auto i : arr)
    cout << i << " ";
  cout << endl;

  return 0;
}
