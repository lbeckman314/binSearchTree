#ifndef BST_H
#define BST_H

#ifndef TYPE
#define TYPE int
#endif

#ifndef LT
#define LT(A, B) ((A) < (B))
#endif

#ifndef EQ
#define EQ(A, B) ((A) == (B))
#endif

struct Node {
   TYPE value;
   struct Node * left;
   struct Node * right;
};
struct BinarySearchTree {
   struct Node *root;
   int size;
};


//struct Node;
//struct BinarySearchTree;
void initBST(struct BinarySearchTree *tree);
void addBST(struct BinarySearchTree *tree, TYPE newValue);
int sizeBST (struct BinarySearchTree *tree);
struct Node * _nodeAddBST (struct Node *current, TYPE newValue);
int containsBST (struct BinarySearchTree *tree, TYPE d);
void removeBST (struct BinarySearchTree *tree, TYPE d);
TYPE _leftMostChild (struct Node * current);
struct node * _removeLeftmostChild (struct Node *current);
struct Node *  _nodeRemoveBST (struct Node * current, TYPE d);

struct Node * getFirst (struct Node * current, TYPE d);
void removeFirst (struct Node * current, TYPE d);



#endif


