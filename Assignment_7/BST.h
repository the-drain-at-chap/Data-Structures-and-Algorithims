// template class for BST

#include "TreeNode.h"
#include <iostream>

template <typename E>
class BST{
private:
  TreeNode<E>* root; // root of tree
  int size; // number of elements in tree

public:
  BST();
  ~BST();
  bool contains(int k);
  E find(int k);
  void insert(TreeNode<E>* node);
  bool remove(int k);
  TreeNode<E>* getSuccessor(TreeNode<E>* d);
  TreeNode<E>* getMin();
  TreeNode<E>* getMax();
  void inOrder(TreeNode<E>* node);
  void printTree();
  TreeNode<E>* getRoot();
  int length();
  bool isEmpty();
};

/*
Constructor, sets root and size values.
*/
template <typename E>
BST<E>::BST(){
  root = nullptr;
  size = 0;
}

/*
Destructor
*/
template <typename E>
BST<E>::~BST(){

}

/*
contains
Checks if tree contains node with key k.
@param k: key to find.
@return T/F
*/
template <typename E>
bool BST<E>::contains(int k){
  if(root == nullptr)
    return false;
  TreeNode<E>* curr = root;
  while(curr->key != k){
    if(k < curr->key)
      curr = curr->left;
    else
      curr = curr->right;
    if(curr == nullptr)
      return false;
  }
  return true;
}

/*
find
Finds node with key k.
@param k: key to find.
@return value
*/
template <typename E>
E BST<E>::find(int k){
   if(root == nullptr)
    return E();
  TreeNode<E>* curr = root;
  while(curr->key != k){
    if(k < curr->key)
      curr = curr->left;
    else
      curr = curr->right;
    if(curr == nullptr)
      return E();
  }
  return curr->value;
}

/*
insert
Inserts node in tree.
@param node: tree node to insert.
*/
template <typename E>
void BST<E>::insert(TreeNode<E>* node){
  if(root == nullptr)
    root = node;
  else{
    TreeNode<E>* curr = root;
    TreeNode<E>* parent;
    
    while(true){
      parent = curr; //update parent
      //based on value, update curr
      if(node->key < curr->key){
        curr = curr->left;
        if(curr == nullptr){
          parent->left = node;
          break;
        }
      }
      else{
        curr = curr->right;
        if(curr == nullptr){
          parent->right = node;
          break;
        }
      }
    }
  }
  size++;
}

/*
delete
Delete a node from tree.
@param k: key to find and delete.
@return T/F whether delete was successful.
*/
template <typename E>
bool BST<E>::remove(int k){
  if(root == nullptr)
    return false;
  TreeNode<E>* curr = root;
  TreeNode<E>* parent = root;
  bool isLeft = true;

  //find the node to delete
  while(curr->key != k){
    parent = curr;
    if(k < curr->key){
      curr = curr->left;
      isLeft = true;
    }
    else{
      curr = curr->right;
      isLeft = false;
    }
    if(curr == nullptr)
      return false;
  }
  //at this point, we have found the node to remove
  //case 1: no children
  if(curr->left == nullptr && curr->right == nullptr){
    if(curr == root)
      root = nullptr;
    else if(isLeft)
      parent->left = nullptr;
    else
      parent->right = nullptr;
  }
  //case 2: one child on the left
  else if(curr->right == nullptr){
    if(curr == root)
      root = curr->left;
    else if(isLeft)
      parent->left = curr->left;
    else
      parent->right = curr->left;
  }
  //case 3: one child on the right
  else if(curr->right == nullptr){
    if(curr == root)
      root = curr->right;
    else if(isLeft)
      parent->left = curr->right;
    else
      parent->right = curr->right;
  }
  //case 4: two children
  else{
    TreeNode<E>* successor = getSuccessor(curr);
    if(curr == root)
      root = successor;
    else if(isLeft)
      parent->left = successor;
    else
      parent->right = successor;
    successor->left = curr->left;
  }
  size--;
  delete curr;
  return true;
}

/*
getSuccessor
Find a node's left most child of its right child
@param d: Node to find successor for.
@return successor node.
*/
template <typename E>
TreeNode<E>* BST<E>::getSuccessor(TreeNode<E>* d){
  TreeNode<E>* sp = d;
  TreeNode<E>* successor = d;
  TreeNode<E>* curr = d->right;

  while(curr != nullptr){
    sp = successor;
    successor = curr;
    curr = curr->left;
  }

  if(successor != d->right){
    sp->left = successor->right;
    successor->right = d->right;
  }

  return successor;
}

/*
getMin
Find a tree's smallest key node.
@return smallest key node
*/
template <typename E>
TreeNode<E>* BST<E>::getMin(){
  TreeNode<E>* curr = root;
  if(root == nullptr)
    return new TreeNode<E>();
  while(curr->left != nullptr)
    curr = curr->left;
  return curr;
}


/*
getMax
Find a tree's largest key node.
@return largest key node
*/
template <typename E>
TreeNode<E>* BST<E>::getMax(){
  TreeNode<E>* curr = root;
  if(root == nullptr)
    return new TreeNode<E>();
  while(curr->right != nullptr)
    curr = curr->right;
  return curr;
}

/*
inOrder
Inorder traversal starting at some node.
@param node: node to begin traversal
*/
template <typename E>
void BST<E>::inOrder(TreeNode<E>* node){
  if(node == nullptr)
    return;
  inOrder(node->left);
  std::cout << node->key << "-";
  inOrder(node->right);
}

/*
printTree
Caller for inOrder.
*/
template <typename E>
void BST<E>::printTree(){
  inOrder(root);
  std::cout << std::endl;
}

/*
getRoot
@return root: root of tree.
*/
template <typename E>
TreeNode<E>* BST<E>::getRoot(){
  return root;
}

/*
length
@return size: size of tree.
*/
template <typename E>
int BST<E>::length(){
  return size;
}

/*
isEmpty
@return T/F: if size is 0 or not.
*/
template <typename E>
bool BST<E>::isEmpty(){
  return (size == 0);
}
