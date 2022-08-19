#include<iostream>
#include <vector>
//#include<stdexcept>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::runtime_error;

int main(int argc, char const *argv[]) {
  int a, b;
  while (cin >> a >> b) {
    try{
      if (b == 0)
        throw runtime_error("Divide by 0.");
      cout << a / b << endl;
    }catch(runtime_error err) {
      cout << err.what()
           << "\nPlease input again? Enter y or n" << endl;
      char c;
      cin >> c;
      if(!cin || c == 'n')
        break;
    }
  }
  return 0;
}
