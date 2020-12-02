//
// Created by caden on 11/22/20.
//

#include "BTree.h"
#include<iostream>

using std::cout;
using std::endl;

const int MAX = 2147483647;
const int MIN = -2147483647;


/*
 * BTree
 *  Let root = nullptr
 * */
BTree::BTree() {
  root = nullptr;
}


/*
 * BTree(arr)
 *  Let size = arr size
 *  Let root = ConstructorHelper(arr, root, 0, size)
 * */
BTree::BTree(const vector<int>& arr) {
  int size = arr.size();
  root = ConstructorHelper(arr, root, 0, size);
}

/*
 * NewNode(data)
 *  Declare new_node
 *  Let new_node's data = data
 *  Let new_node's left = nullptr
 *  Let new_node's right = nullptr
 *  Return new_node
 * */
BTree::Node* BTree::NewNode(int data) {
  Node* new_node = new Node;
  new_node->data = data;
  new_node->left = nullptr;
  new_node->right = nullptr;
  return new_node;
}


/*
 * ConstructorHelper(arr, temp_root, i, size)
 *  If i < size
 *    Let temp = NewNode(arr[i])
 *    Let temp_root = temp
 *    Let temp_root's right = ConstructorHelper(arr, temp_root's right, 2*i+2, size)
 *    Let temp_root's right = ConstructorHelper(arr, temp_root's left, 2*i+1, size)
 *  counter = size
 *  Return temp_root
 * */

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

/*
 * IsBst()
 *  Return IsBSTHelper(root, MIN, MAX)
 * */
bool BTree::IsBST() {
  return IsBSTHelper(root, MIN, MAX);
}

/*
 * IsBSTHelper(temp_root, min, max)
 *  If temp_root == nullptr
 *    Return true
 *
 *  If temp_root's data < min or > max
 *    Return false
 *
 *  Return IsBSTHelper(temp_root's left, min, temp_root's data - 1)
 *  and IsBSTHelper(temp_root's right, temp_root's data + 1, max)
 *
 * */
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


/*
 * MinHelper(temp_root)
 *  If temp_root == nullptr
 *    Return MAX
 *  Let left_min = MinHelper(temp_root's left)
 *  Let right_min = MinHelper(temp_root's right)
 *  Let min = temp_root's data
 *  If (right_min < min)
 *    Let min = right_min
 *  If (left_min < min)
 *    Let min = left_min
 *  Return min
 * */
int BTree::MinHelper(Node* temp_root) {
  if (temp_root == nullptr) {
    return MAX;
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

/*
 * Min()
 *  Return MinHelper(root)
 * */
int BTree::Min() {
  return MinHelper(root);
}

/*
 * MaxHelper(temp_root)
 *  If temp_root == nullptr
 *    Return MIN
 *  Let left_max = MaxHelper(temp_root's left)
 *  Let right_max = MaxHelper(temp_root's right)
 *  Let max = temp_root's data
 *  If (right_max < max)
 *    Let max = right_max
 *  If (left_min < min)
 *    Let max = left_max
 *  Return max
 * */
int BTree::MaxHelper(Node* temp_root) {
  if (temp_root == nullptr) {
    return MIN;
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


/*
 * Max()
 *  Return MaxHelper(root)
 * */
int BTree::Max() {
  return MaxHelper(root);
}

/*
 * AvgHelper(temp_root)
 *  If temp_root != nullptr
 *    Return (AvgHelper(temp_root's left) +
 *           AvgHelper(temp_root's right) +
 *           temp_root's data)
 *  Return 0
 * */
float BTree::AvgHelper(Node* temp_root) {
  if (temp_root != nullptr) {
    return (AvgHelper(temp_root->left) +
            AvgHelper(temp_root->right) +
            temp_root->data);
  }
  return 0;
}

/*
 * Avg()
 *  Return AvgHelper(root)/counter;
 * */
float BTree::Avg() {
  return AvgHelper(root)/counter;
}


/*
 * DepthHelper(n, path, depth, temp_root)
 *  If temp_root == nullptr
 *    Return 0
 *  If temp_root's data == n
 *    Print line "depth = " + depth
 *    Print "path = "
 *    For i = 0, i < depth, i++
 *      Print path[i] + " "
 *    Print temp_root's data
 *    Return depth
 *  Add temp_root's data to the back of path
 *  Return DepthHelper(n, path, depth++, temp_root's right) +
 *  DepthHelper(n, path, depth++, temp_root's left)
 * */
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

/*
 * DepthFinder(n)
 *  Declare path
 *  Return DepthHelper(n, path, 1, root)
 * */
int BTree::DepthFinder(int n) {
  vector<int> path;
  return DepthHelper(n, path, 1, root);
}

