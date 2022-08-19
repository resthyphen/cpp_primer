#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::istream;
using std::ostream;

class Account {
public:
  Account() = default;
  Account(const string &s, double b): owner(s), amount(b){};
  void calculate() { amount += amount * interestRate; }
  static double rate() { return interestRate; }   
  static void rate(double);
private:
  std::string owner;
  double amount;
  static double interestRate;   //static member
  static double initRate();     //static member function
  static constexpr int period = 30;
  double daily_tbl[period];
};

void Account::rate(double newRate){
  interestRate = newRate;
}

double Account::interestRate = initRate();

double Account::initRate(){
  return 0.1;
}

int main(int argc, char const *argv[])
{
  Account ac1;
  Account *ac2 = &ac1;
  double r;
  r = Account::rate();
  cout << r << endl;
  cout << ac1.rate() << endl;
  cout << ac2->rate() << endl;
  
  return 0;
}
