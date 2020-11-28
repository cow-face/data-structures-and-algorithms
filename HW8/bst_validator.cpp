#include <iostream>
#include<vector>
#include "BTree.h"

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main() {
  vector<int> input_vec;
  int input;
  while (cin >> input) {
    input_vec.push_back(input);
  }
  BTree tree(input_vec);
  if (tree.IsBST()) {
    cout << "True";
  }
  else {
    cout << "False";
  }
}


