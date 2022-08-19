//Note: g++ -std=c++11 -pthread multithread_test.cc

#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;

// A dummy function
void foo(int Z)
{
    for (int i = 0; i < Z; i++) {
        cout << "Thread using function"
               " pointer as callable\n";
    }
}

// A callable object
class thread_obj {
public:
    void operator()(int x)
    {
        for (int i = 0; i < x; i++)
            cout << "Thread using function"
                  " object as  callable\n";
    }
};

void print(int n, const std::string &str)  {
    std::cout << "Printing integer: " << n << std::endl;
    std::cout << "Printing string: " << str << std::endl;
}

int sum(){
  int a, b;
  cin >> a >> b;
  cout << (a + b) << endl;
  return a + b;
}

int main(){
    //thread t1(print, 10, "Educative.blog");
    // cout << "Threads 1 and 2 and 3 "
    //      "operating independently" << endl;

    // This thread is launched by using
    // function pointer as callable
    //thread th1(foo, 3);

    // This thread is launched by using
    // function object as callable
    //thread th2(thread_obj(), 3);

    // Define a Lambda Expression
    auto f = [](int x) {
        for (int i = 0; i < x; i++)
            cout << "Thread using lambda"
             " expression as callable\n";
    };

    //thread th5(sum);
    auto f2 = [](){
      for(auto i = 1; i <= 20; i++){
        cout << i << " ";

      }
    };

    auto f3 = [](){
      for(auto i = 21; i <= 40; i++){
        cout << i << " ";

      }
    };

    // This thread is launched by using
    // lamda expression as callable
    //thread th3(f, 3);


    //thread t1(f, 3);
    //thread t2(f2);
    //thread t3(f3);

    //t1.join();
    //th5.join();
    //t2.join();
    //t3.join();

    // Wait for the threads to finish
    // Wait for thread t1 to finish
    //th1.join();

    // Wait for thread t2 to finish
    //th2.join();

    // Wait for thread t3 to finish
    //th3.join();

    // thread t1(print, 10, "Educative.blog");
    // t1.join();

    std::cout << "countdown:\n";
    for (int i=10; i>0; --i) {
      std::cout << i << std::endl;
      std::this_thread::sleep_for (std::chrono::seconds(1));
    }
    std::cout << "Lift off!\n";



    return 0;
}
