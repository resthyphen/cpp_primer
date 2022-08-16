#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::runtime_error;
using std::cerr;

int add(int, int);
int subtract(int, int);
int multiply(int,int);
int divide(int, int);

int add(int a, int b){
  return a + b;
}

int subtract(int a, int b){
  return a - b;
}

int multiply(int a, int b){
  return a * b;
}

int divide(int a, int b){
  try{
    if(b == 0)
      throw runtime_error("Divide by 0.");
    return a / b;
  }catch(runtime_error err){
    cerr << err.what() << endl;
    return 0;
  }

}

int main(int argc, char const *argv[]) {
  vector<int(*) (int, int)> v;
  v.push_back(add);
  v.push_back(subtract);
  v.push_back(multiply);
  v.push_back(divide);
  int a,b;
  cin >> a >> b;
  for(auto f : v)
    cout << f(a,b) << endl;
  return 0;
}
