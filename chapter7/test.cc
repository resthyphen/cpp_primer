#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;

class Screen{
public:
  void dummy_fcn(pos height){
    cursor = width * height;
  }
private:
  pos cursor = 0;
  pos height = 0, width = 0;

  typedef string::size_type pos;
};

int main(int argc, char const *argv[]) {
  vector<int> v{10};
  cout << v[3] << endl;
}
