//
// Created by caden on 11/22/20.
//

#include "BTree.h"
#include<iostream>

using std::cout;
using std::endl;

const int INT_MAX = 2147483647;
const int INT_MIN = -2147483647;

BTree::BTree() {
  root = nullptr;
}

BTree::BTree(const vector<int>& arr) {
  int size = arr.size();
  root = ConstructorHelper(arr, root, 0, size);
}

BTree::Node* BTree::NewNode(int data) {
  Node* new_node = new Node;
  new_node->data = data;
  new_node->left = nullptr;
  new_node->right = nullptr;
  return new_node;
}

BTree::Node *BTree::ConstructorHelper(vector<int> arr, BTree::Node* temp_root, int i, int size) {
  if (i < size) {
    Node* temp = NewNode(arr[i]);
    temp_root = temp;

    temp_root->right = ConstructorHelper(arr, temp_root->right, 2*i+2, size);

    temp_root->left = ConstructorHelper(arr, temp_root->left, 2*i+1, size);
  }
  counter = size;
  return temp_root;
}

void BTree::Display() {
  DisplayHelper(root);
}

void BTree::DisplayHelper(BTree::Node *temp_root) {
  if (temp_root != nullptr) {
    DisplayHelper(temp_root->left);
    cout << temp_root->data << " ";
    DisplayHelper(temp_root->right);
  }
}

bool BTree::IsBST() {
  return IsBSTHelper(root, INT_MIN, INT_MAX);
}

bool BTree::IsBSTHelper(BTree::Node *temp_root, int min, int max) {
  if (temp_root == nullptr) {
    return true;
  }

  if (temp_root->data < min || temp_root->data > max) {
    return false;
  }

  return IsBSTHelper(temp_root->left, min, temp_root->data - 1)
  && IsBSTHelper(temp_root->right, temp_root->data+1, max);
}

int BTree::MinHelper(Node* temp_root) {
  if (temp_root == nullptr) {
    return INT_MAX;
  }
  int left_min = MinHelper(temp_root->left);
  int right_min = MinHelper(temp_root->right);
  int min = temp_root->data;
  if (right_min < min) {
    min = right_min;
  }
  if (left_min < min) {
    min = left_min;
  }
  return min;
}

int BTree::Min() {
  return MinHelper(root);
}

/*int BTree::Min() {
  if (IsBST()) {
    Node *temp_node = root;
    while (temp_node->left != nullptr) {
      temp_node = temp_node->left;
    }
    return temp_node->data;
  }
  else return 0;
}*/

/*int BTree::Max() {
  if (IsBST()) {
    Node *temp_node = root;
    while (temp_node->right != nullptr) {
      temp_node = temp_node->right;
    }
    return temp_node->data;
  }
  else return 0;
}*/

int BTree::MaxHelper(Node* temp_root) {
  if (temp_root == nullptr) {
    return INT_MIN;
  }
  int left_max = MaxHelper(temp_root->left);
  int right_max = MaxHelper(temp_root->right);
  int max = temp_root->data;
  if (right_max > max) {
    max = right_max;
  }
  if (left_max > max) {
    max = left_max;
  }
  return max;
}

int BTree::Max() {
  return MaxHelper(root);
}

float BTree::AvgHelper(Node* temp_root) {
  if (temp_root != nullptr) {
    return (AvgHelper(temp_root->left) +
            AvgHelper(temp_root->right) +
            temp_root->data);
  }
  return 0;
}

float BTree::Avg() {
  return AvgHelper(root)/counter;
}

int BTree::DepthHelper(int n, vector<int> path, int depth, Node* temp_root) {
  if (temp_root == nullptr) {
    return 0;
  }
  if (temp_root->data == n) {
    cout << "depth = " << depth << endl;
    cout << "path = ";
    for (int i = 0; i < depth; i++) {
      cout << path[i] << " ";
    }
    cout << temp_root->data;
    return depth;
  }
  path.push_back(temp_root->data);
  return DepthHelper(n, path, depth++, temp_root->right) +
  DepthHelper(n, path, depth++, temp_root->left);
}

int BTree::DepthFinder(int n) {
  vector<int> path;
  return DepthHelper(n, path, 1, root);
}

