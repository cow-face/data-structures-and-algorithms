//
// Created by caden on 12/1/20.
//

#include<iostream>
#include<iomanip>
#include"BTree.h"
#include<vector>

using std::cin;
using std::cout;
using std::vector;
using std::endl;
using std::setprecision;
using std::fixed;

int main () {
  vector<int> input_vec;
  int input;
  while (cin >> input) {
    input_vec.push_back(input);
  }
  BTree btree(input_vec);
  btree.DepthFinder(7);
}