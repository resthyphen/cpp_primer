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
  static double interestRate;
  static double initRate();
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
