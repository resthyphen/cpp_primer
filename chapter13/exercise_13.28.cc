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
using std::weak_ptr;

class TreeNode {
public:
  TreeNode() = default;
  TreeNode(string s): value(s){}
  TreeNode(const TreeNode &orig): value(orig.value), count(orig.count),
  left(orig.left), right(orig.right){}
  TreeNode& operator=(const TreeNode &rhs){
    value = rhs.value;
    count = rhs.count;
    left = rhs.left;
    right = rhs.right;
    return *this;
  }

  ~TreeNode(){

  }

private:
  string value;
  int count;
  TreeNode *left;
  TreeNode *right;
};

class BinStrTree {
public:
  BinStrTree() = default;
  BinStrTree(const TreeNode &n = TreeNode()): root(new TreeNode(n)){}
  BinStrTree(const BinStrTree &orig): root(orig.root){}
  BinStrTree& operator=(const BinStrTree &rhs){
    root = rhs.root;
    return *this;
  }

  ~BinStrTree(){

  }

private:
  TreeNode *root;
};


int main(int argc, char const *argv[]) {

  return 0;
}
