#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"





void initBST(struct BinarySearchTree *tree) {
    tree->size = 0;
    tree->root = 0;
}


void addBST(struct BinarySearchTree *tree, TYPE newValue) {
   tree->root = _nodeAddBST(tree->root, newValue);  tree->size++; }

int sizeBST (struct BinarySearchTree *tree) { return tree->size; }


//Node add (Node start, E newValue)
struct Node * _nodeAddBST (struct Node *current, TYPE newValue) {

   //if start is null then return a new Node with newValue
    if (current == NULL)
    {
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->value = newValue;
        return newNode;
    }

    //otherwise if newValue is less than the value at start then
    else if (newValue < current->value)
        //set the left child to be the value returned by add(leftChild, newValue)
        current->left = _nodeAddBST(current->left, newValue);

    //otherwise set the right child to be add(rightChild, newValue)
    else
        current->right = _nodeAddBST(current->right, newValue);

    //return the current node
    return current;

}

int containsBST (struct BinarySearchTree *tree, TYPE d) {

    //double b = 10;
    //printf("d is: %d\n", d);
    //printf("tree->root->value is: %d\n", tree->root->value);
    while (tree->root != NULL)
    {
        if (d < tree->root->value)
            tree->root = tree->root->left;
            //tree->root = containsBST(tree->root->left, d);


        else if (d > tree->root->value)
            tree->root = tree->root->right;
            //tree->root = containsBST(tree->root->right, d);

        else if (d == tree->root->value)
            return 1;
    }

    return 0;

}
void removeBST (struct BinarySearchTree *tree, TYPE d) {
    if (containsBST(tree, d))
    {
        //printf("!!%d is found!!\n", d);
        tree->root = _nodeRemoveBST(tree->root, d);
        tree->size--;
    }
}

TYPE _leftMostChild (struct Node * current) {

     // traverse the tree until the leftmost child is found
    current = current->right;

    while (current->left != NULL)
        current = current->left;

    // function returns TYPE, so perhaps it should just return the value of the current node.
    return current->value;
}


struct node * _removeLeftmostChild (struct Node *current) {

    if (current == NULL)
        return NULL;

    if (current->right != NULL)
    {
        // traverse the tree until the leftmost child is found
        current = current->right;

        while (current->left != NULL)
            current = current->left;

        // When found, return the right child (which could possibly be null)
        return current->right;
    }

    // Otherwise make a recursive call and set the left child to the value returned by the recursive call, and return the current Node.
    else {
        current->left = _removeLeftmostChild(current);
        return current;
    }

}





// Node remove (Node start, E testValue)
struct Node *  _nodeRemoveBST (struct Node * current, TYPE d) {

    // if start.value is the value we seek
    //printf("!!d is %d and current->value is %d!!\n", d, current->value);
    if (current->value == d)
    {
        // decrease the value of dataSize
        // TODO: removeBST() takes care of this I think? With tree->size--;


        // if right child is null
        if (current->right == NULL)
        {
            // return left child
            return current->left;
        }

        // otherwise
        else
        {
            // replace value of node with leftmost child of right child
            current->value = _leftMostChild(current);
            // set right child to be removeLeftmost(right child)
            current->right = _removeLeftmostChild(current->right);
        }
    }

    // otherwise if testValue is smaller than start.value
    else if (d < current->value)
    // set left child to remove (left child, testValue)
        current->left = _nodeRemoveBST(current->left, d);

    // otherwise
    else
    // set right child to remove (right child, testValue)
        current->right = _nodeRemoveBST(current->right, d);

    // return current node
    return current;

}


