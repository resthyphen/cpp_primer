#include "sales_data.h"


int main(){
  using cplusplus_primer::Sales_data;
  // using cplusplus_primer::operator>>;
  // using cplusplus_primer::operator<<;
  // using cplusplus_primer::operator+;
  Sales_data trans1, trans2, sum;

  cin >> trans1;
  cin >> trans2;
  sum = trans1 + trans2;
  cout << sum << endl;
  return 0;
}
