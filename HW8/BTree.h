//
// Created by caden on 11/22/20.
//

#ifndef HW8_BTREE_H
#define HW8_BTREE_H

#include<vector>
#include<iomanip>
using std::vector;


class BTree {
public:
  BTree();
  BTree(const vector<int>&);
  void Display();
  bool IsBST();
  int Min();
  int Max();
  float Avg();
  int DepthFinder(int n);

private:
  struct Node {
    int data;
    Node* left;
    Node* right;
  };
  Node* root = nullptr;
  int counter = 0;

  Node* NewNode(int);
  Node* ConstructorHelper(vector<int>, Node*, int, int);
  void DisplayHelper(Node*);
  bool IsBSTHelper(Node*, int, int);
  float AvgHelper(Node *temp_root);

  int MinHelper(Node *temp_root, int min);

  int MinHelper(Node *temp_root);

  int MaxHelper(Node *temp_root);

  int DepthHelper(int n, vector<int> path, int depth, Node *temp_root);
};


#endif //HW8_BTREE_H
