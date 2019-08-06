/*
Input:
  1
   \
    2
   / \
  3   4

Ouput:
[1, 3, 4, 2]

Explanation:
The root doesn't have left subtree, so the root itself is left boundary.
The leaves are node 3 and 4.
The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
So order them in anti-clockwise without duplicates and we have [1,3,4,2].

Example 2

Input:
    ____1_____
   /          \
  2            3
 / \          / 
4   5        6   
   / \      / \
  7   8    9  10  
       
Ouput:
[1,2,4,7,8,9,10,6,3]

Explanation:
The left boundary are node 1,2,4. (4 is the left-most node according to definition)
The leaves are node 4,7,8,9,10.
The right boundary are node 1,3,6,10. (10 is the right-most node).
So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].




We break the problem in 3 parts:
1. Print the left boundary in top-down manner.
2. Print all leaf nodes from left to right, which can again be sub-divided into two sub-parts:
…..2.1 Print all leaf nodes of left sub-tree from left to right.
…..2.2 Print all leaf nodes of right subtree from left to right.
3. Print the right boundary in bottom-up manner.

We need to take care of one thing that nodes are not printed again. e.g. The left most node is also the leaf node of the tree.


*/

  
#include <stdio.h> 
#include <stdlib.h> 
  
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node { 
    int data; 
    struct node *left, *right; 
}; 
  
// A simple function to print leaf nodes of a binary tree 
void printLeaves(struct node* root) 
{ 
    if (root) { 
        printLeaves(root->left); 
  
        // Print it if it is a leaf node 
        if (!(root->left) && !(root->right)) 
            printf("%d ", root->data); 
  
        printLeaves(root->right); 
    } 
} 
  
// A function to print all left boundary nodes, except a leaf node. 
// Print the nodes in TOP DOWN manner 
void printBoundaryLeft(struct node* root) 
{ 
    if (root) { 
        if (root->left) { 
            // to ensure top down order, print the node 
            // before calling itself for left subtree 
            printf("%d ", root->data); 
            printBoundaryLeft(root->left); 
        } 
        else if (root->right) { 
            printf("%d ", root->data); 
            printBoundaryLeft(root->right); 
        } 
        // do nothing if it is a leaf node, this way we avoid 
        // duplicates in output 
    } 
} 
  
// A function to print all right boundary nodes, except a leaf node 
// Print the nodes in BOTTOM UP manner 
void printBoundaryRight(struct node* root) 
{ 
    if (root) { 
        if (root->right) { 
            // to ensure bottom up order, first call for right 
            // subtree, then print this node 
            printBoundaryRight(root->right); 
            printf("%d ", root->data); 
        } 
        else if (root->left) { 
            printBoundaryRight(root->left); 
            printf("%d ", root->data); 
        } 
        // do nothing if it is a leaf node, this way we avoid 
        // duplicates in output 
    } 
} 
  
// A function to do boundary traversal of a given binary tree 
void printBoundary(struct node* root) 
{ 
    if (root) { 
        printf("%d ", root->data); 
  
        // Print the left boundary in top-down manner. 
        printBoundaryLeft(root->left); 
  
        // Print all leaf nodes 
        printLeaves(root->left); 
        printLeaves(root->right); 
  
        // Print the right boundary in bottom-up manner 
        printBoundaryRight(root->right); 
    } 
} 
  
// A utility function to create a node 
struct node* newNode(int data) 
{ 
    struct node* temp = (struct node*)malloc(sizeof(struct node)); 
  
    temp->data = data; 
    temp->left = temp->right = NULL; 
  
    return temp; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Let us construct the tree given in the above diagram 
    struct node* root = newNode(20); 
    root->left = newNode(8); 
    root->left->left = newNode(4); 
    root->left->right = newNode(12); 
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(14); 
    root->right = newNode(22); 
    root->right->right = newNode(25); 
  
    printBoundary(root); 
  
    return 0; 
} 
