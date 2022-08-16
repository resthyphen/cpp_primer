#include <iostream>
int main()
{
  int sum = 0;

  for (int i = -100; i <= 100; ++i)      //The expression is executed after the for body
    sum += i;                           //After executing the body,val is incremented again

  std::cout << "Sum of -100 to 100 inclusive is " << sum << std::endl;
  return 0;
}
