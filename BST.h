// Minimum implementation of a binary search tree.
// Author: Ryan Shim
// Date: 11-1-2018
#ifndef BST_H
#define BST_H
#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T value;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
};

template <typename T>
class BinarySearchTree {
    public:
        BinarySearchTree();
        Node<T>* root();
        int size();
        T getMinimum();
        T getMaximum();
        bool insertVal(const T& val);
        void preorderPrint(Node<T>* nodeptr);
        void inorderPrint(Node<T>* nodeptr);
        void postorderPrint(Node<T>* nodeptr);
    private:
        int size_;
        Node<T>* root_;

//helper function (min)
T getMinimumR(Node<T>* r){
if (r->left==nullptr){
	return r->value;
}
else return getMinimumR(r->left);
}

//helper function (max)
T getMaximumR(Node<T>* r){
if (r->right==nullptr){
	return r->value;
}
else return getMaximumR(r->right);
}
};

// Default constructor
template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
	size_=0;
	root_=nullptr;
}

// Returns the maximum in the BST
template <typename T>
T BinarySearchTree<T>::getMinimum() {
    return getMinimumR(root_);
}

// Returns the minimum in the BST
template <typename T>
T BinarySearchTree<T>::getMaximum() {
    return getMaximumR(root_);
}

// Prints the BST using an preorder traversal.
template <typename T>
void BinarySearchTree<T>::preorderPrint(Node<T>* nodeptr) {
    
}

// Prints the BST using an inorder traversal.
template <typename T>
void BinarySearchTree<T>::inorderPrint(Node<T>* nodeptr) {
    if (nodeptr==nullptr) return;
    else {
	inorderPrint(nodeptr->left);
	cout << nodeptr->value;
	inorderPrint(nodeptr->right);
  }
}

// Prints the BST using an postorder traversal.
template <typename T>
void BinarySearchTree<T>::postorderPrint(Node<T>* nodeptr) {
    // TO BE COMPLETED
}


/****************************
 * DO NOT CHANGE CODE BELOW *
 ****************************/
// Returns a node pointer to the root_ node
// DO NOT CHANGE
template <typename T>
Node<T>* BinarySearchTree<T>::root() {
    return root_;
}

// Returns the number of elements in the BST
// DO NOT CHANGE
template <typename T>
int BinarySearchTree<T>::size() {
    return size_;
}

// Insert a value in the BST.
// DO NOT CHANGE
template <typename T>
bool BinarySearchTree<T>::insertVal(const T& val) {
    Node<T>* newNode = new Node<T>;
    newNode->value = val;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (size_ == 0) {
        root_ = newNode;
        size_++;
        return true;
    }

    Node<T>* tmp = root_;

    while (tmp) {
        if (val > tmp->value) {
            if (tmp->right) {
                tmp = tmp->right;
            }
            else {
                tmp->right = newNode;
                size_++;
                return true;
            }
        }
        else if (val < tmp->value) {
            if (tmp->left) {
                tmp = tmp->left;
            }
            else {
                tmp->left = newNode;
                size_++;
                return true;
            }
        }
    }
    return false;
}

#endif
