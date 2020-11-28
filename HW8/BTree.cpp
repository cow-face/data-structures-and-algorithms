//
// Created by caden on 11/22/20.
//

#include "BTree.h"
#include<iostream>

using std::cout;

BTree::BTree() {
  root = nullptr;
}

BTree::BTree(vector<int> arr) {
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
  return IsBSTHelper(root, INT32_MIN, INT32_MAX);
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


int BTree::Min() {
  if (IsBST()) {
    Node *temp_node = root;
    while (temp_node->left != nullptr) {
      temp_node = temp_node->left;
    }
    return temp_node->data;
  }
  else return 0;
}

int BTree::Max() {
  if (IsBST()) {
    Node *temp_node = root;
    while (temp_node->right != nullptr) {
      temp_node = temp_node->right;
    }
    return temp_node->data;
  }
  else return 0;
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


