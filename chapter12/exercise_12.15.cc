#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <memory>
#include <initializer_list>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::istream;
using std::ostream;
using std::ifstream;
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;
using std::list;
using std::map;
using std::set;
using std::pair;
using std::multimap;
using std::istringstream;
using std::runtime_error;
using std::make_shared;
using std::out_of_range;
using std::initializer_list;
using std::shared_ptr;


struct destination;// represents what we are connecting to
struct connection;// information needed to use the connection
connection connect(destination*);// open the connection
void disconnect(connection);

void end_connection(connection *p) {
  disconnect(*p);
}

void f(destination &d /* other parameters */){
  connection c = connect(&d);
  shared_ptr<connection> p(&c, [](connection *p){ disconnect(*p); });// use the connection
  // when f exits, even if by an exception, the connection will be properly closed
}
