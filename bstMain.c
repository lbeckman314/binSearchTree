#include <stdio.h>
#include "bst.h"


int main()
{

    printf("\nintializing BST...\n");
    struct BinarySearchTree* newBST = malloc(sizeof(struct BinarySearchTree));
    initBST(newBST);

    int size = 0;
    int contains = 0;
    
    // height 0
    TYPE var0  =  5;

    // height 1
    TYPE var1  =  2;
    TYPE var2  =  8;

    // height 2
    TYPE var3  =  1;
    TYPE var4  =  3;
    TYPE var5  =  7;
    TYPE var6  =  9;

    // height 3
    TYPE var7  =  0;
    TYPE var8  =  4;
    TYPE var9  =  6;
    TYPE var10 = 10;
   
    /*
    
    newBST:
              5
             / \
            /   \
           /     \
          /       \
         /         \
        2           8
       / \         / \
      1   3       7   9
     /     \     /     \
    0       4   6      10
       
    */

    size = sizeBST(newBST);
    printf("size of BST is %i\n", size);

    printf("\nadding nodes to BST...\n");
    // height 0
    addBST(newBST, var0);

    // height 1
    addBST(newBST, var1);
    addBST(newBST, var2);

    // height 2
    addBST(newBST, var3);
    addBST(newBST, var4);
    addBST(newBST, var5);
    addBST(newBST, var6);

    // height 3
    addBST(newBST, var7);
    addBST(newBST, var8);
    addBST(newBST, var9);
    addBST(newBST, var10);

    size = sizeBST(newBST);

    printf("size of BST is now %i\n", size);




    // confirm that the tree includes 8 (var2).
    contains = containsBST(newBST, var2);

    if (contains)
        printf("this BST contains %d\n", var2);
    else
        printf("this BST does NOT contain %d\n", var2);


    // remove 8 (var2)
    printf("\ncalling removeBST()...\n");
    removeBST (newBST, var2);


    // confirm that the tree does NOT include 8 (var2) now.
    contains = containsBST(newBST, var2);

    if (contains)
        printf("this BST contains %d\n", var2);
    else
        printf("this BST does NOT contain %d\n", var2);


    return 0;
}


