#include <iostream>
using namespace std; 

/*
Definitions
- Binary tree: each node has max 2 children
- Size: no. of nodes in the tree
- Height: distance of root to farthest child
- Depth: distance from node to root
- Leaf: node with no children
- Full: node with max. no. of children

Tree storage
- Parent-multi-child: array of children
        Data
  | | | | | | | | |
  
- Parent-Child-Sibling
        Data
    Child | Sibling
*/

/* 
Binary Search Tree
Runtime: 
- Search (O log N) 
- Insertion (O log N)
- Deletion (O log N)

- Each node only contains left + right pointer
- left child: data less than node
- right child: data more than node
*/

// BST Node Code
template <class T> 
class BSTNode {
  T data;
  BSTNode<T>* parent;
  BSTNode<T>* left; 
  BSTNode<T>* right; 
public:
  BSTNode (T newdata = t(), BSTNode<T>* newParent = nullptr, 
          BSTNode<T>* newLeft = nullptr, BSTNode<T>* newRight = nullptr) : 
          data(newdata), parent(newParent), left(newLeft), right(newRight) ()
  friend class BST<T>;
  int getSize() const{
    int count = 1;
    if (left != nullptr)
        count += left->getSize();
    if (right != nullptr)
        count += right->getSize();
    return count;
  }

  /* TREE TRAVERSALS
  - In order: bottom left -> root -> right
  - Pre order: root -> left -> right
  - Post order: bottom left -> bottom right -> root 
  - Level order: nodes closest to root -> lower levels (left to right)
  */

  void printInOrder(BSTNode<T>* node){
   if (node != nullptr){
     printInOrder(node->left);
     cout << node->data << ",";
     printInOrder(node->right);
   } 
  }
  void printPreOrder(BSTNode<T>* node){
   if (node != nullptr){
     cout << node->data << ", ";
     printPreOrder(node->left);
     printPreOrder(node->right);
   } 
  }
  void printPostOrder(BSTNode<T>* node){
   if (node != nullptr){
     printPostOrder(node->left);
     printPostOrder(node->right);
     cout << node->data << ", ";
   } 
  }
  void printLevelOrder(BSTNode<T>* node){
    queue<BSTNode<T>*> q;
    q.push(root);
    while(!q.empty()){
      BSTNode<T>* temp = q.front();
      q.pop();
      cout << temp->data << ",";
      if (temp->left != nullptr)
          q.push(temp->left);
      if (temp->right != nullptr)
          q.push(temp->right);
    }
  }
};

// Insertion into trees
template <class T> 
void BST<T>::insert(T item){
 if (root == nullptr){ // tree is empty
   root = new BSTNode<T>(item);
   return;
 } 
  BSTNode<T>* temp = root; // find the nullptr
  BSTNode<T>* prev = root; 
  while (temp != nullptr){ // if tree is not empty
    prev = temp; 
    if (item < temp->data)
        temp = temp->left;
    else 
        temp = temp->right;
  }
  if (item < prev->data)
      prev->left = new BSTNode<T>(item, prev);
  else
      prev->right = new BSTNode<T>(item, prev);
}
// Insertion into BST: finding a nullpoint in the tree and inserting


// REMOVING FROM TREE
template <class T>
void BST<T>::remove(BSTNode<T>*& temp){

/* REMOVAL IF NO CHILD */
  if (temp->left == nullptr && temp->right == nullptr) // no children
    // determine if this is the root
    parent = temp;
    if (parent == nullptr)
        root = nullptr;
    else if (parent->left == temp)
        parent->left = nullptr;
    else 
        parent->right = nullptr;
    delete temp; 

/* REMOVAL IF THERE IS 1 CHILD */
  // right child but no left child
  else if (temp->left == nullptr){ 
    // Promote temp->right
    BSTNode<T>* toDelete = temp->right;
    temp->data = toDelete->data;
    temp->left = toDelete->left;
    if (temp->left != nullptr)
        temp->left->parent = temp; 
    temp->right = toDelete->right;
    if (temp->right != nullptr)
        temp->right->parent = temp; 
    delete toDelete;
  }
    
  // left but no right child
  else if (temp->right == nullptr) {
    // promote temp->left
    BSTNode<T>* toDelete = temp->left;
    temp->data = toDelete->data;
    temp->left = toDelete->left;
    if (temp->left != nullptr)
        temp->left->parent = temp; 
    temp->right = toDelete->right;
    if (temp->right != nullptr)
        temp->right->parent = temp; 
    delete toDelete;
  }

  // both children
  else {
    BSTNode<T>* minOfRight = temp->right;
    while (minOfRight->left != nullptr)
      minOfRight = minOfRight->left;
    temp->data = minOfRight->data;
    remove(minOfRight); //recursion 
  }
}

/* when BSTs fail 
- In best case: O (log N)
- In worst case: if insertions are already in order (e.g. 5 -> right subchild 10 -> -> right subchild 15)
      - This is a linked list -> search is linear time 
- Solution: balanced BST to guarantee O(log N) search time (closer to 2 log N)
      - AVL Trees (easier but not great performance)
      - Red-Black Trees (harder, better performance)      

AVL TREE 
  - Each node records its own height
  - Requires that the height of the left + right subtrees of every node differ by a height of no more than 1
  - If difference is more than 1, then need to balance through rotation to choose better root
  
    // Good AVL tree: 3 differs from 20's height by 1 
        10 (h=2)
      5 (h=1)  20 (n=1)
    3 (h=0)
      
    // Bad AVL tree
    Example 1: difference of >1 + will end up as a linked list 
        10 (h=2)
      5 (h=1)
    3 (h=0)
    
    Example 2: difference of >1
        10 (h=3)
      5 (h=2)  20 (n=2)
    3 (h=1)
      4 (h=0)
  
    Rotation situations 
    - given a grandparent, parent, child is unbalanced
    
    SINGLE ROTATION
    - if left parent's left subchild > left parent's right subchild
      or right parent's right subchild > right parent's left subchild
      == single rotation: make parent the new grandparent, grandparent and child becomes new children
    
    e.g.       20  -->     10
            10          5      20
          5 
    
    DOUBLE ROTATION
    Perform 2 single rotation to produce a double rotation
    E.g     20     -->       15
          10             10      20
            15

            Case study 1
              
                      5
                  4
              3
            - Height is more than 1, need rotation 
            - Solution: 
                  4
              3       5
             *************************************************            
                         root (this needs to point to 4)
                         |
                         v
              (i) temp -> 5 
                      4
                  3
             *************************************************            
                  temp -> 5 
                      4 <- (ii) root
                  3
             *************************************************            
                  temp -> 5 
                      4 <- (iii) temp->left = root->right 
                  3
             *************************************************            
                      4 
                  3       5 -> (iv) root-right = temp
             *************************************************            
                      4 -> (v) root->parent = nullptr
                  3       5 -> (vi) temp->parent = root
            
            
              Case study 2
            
              1                     4
                2               2        6
                  3            1 3      5 7
                    4                      9
                      5
                        6
            
             *************************************************            
              
              Case study 3
                      
                        3                 2
                    2   a      -->    1      3
                1   b                c d    b a
               c d
            
            *************************************************    
               
   
RED BLACK TREES
  - Solves problems with AVL trees: needing to calculate heights 
      - whenever we do an insertion / removal = need to calculate heights 
      - adds a log N time each time you need to calculate

  - Laws:
    1. All nodes are colored red / black (put bool in each node saying either R/B)
    2. Root is always black (if we find root as red, we color it as black)
    3. Red node cannot have red child 
    4. All paths from root to all children have to pass through same no. of black nodes

  - start off with 1 node (root, always black), 2 nodes on root node
    - if go left, then we go through R
    - if go right, then we go through B
    - if insertion, always R (doesn't change no. of B nodes)
    - If any law violated, means a rotation is necessary
  
  
    
*/



int main(){
  
}
