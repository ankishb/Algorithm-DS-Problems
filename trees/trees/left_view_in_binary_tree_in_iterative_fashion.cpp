
// C++ program to print the 
// left view of Binary Tree 
  
#include <bits/stdc++.h> 
  
using namespace std; 
  
// A Binary Tree Node 
struct node { 
    int data; 
    struct node *left, *right; 
}; 
  
// A utility function to create a new 
// Binary Tree node 
struct node* newNode(int item) 
{ 
    struct node* temp = new node; 
    temp->data = item; 
    temp->left = NULL; 
    temp->right = NULL; 
    return temp; 
} 
  
// Utility function to print the left view of 
// the binary tree 
void leftViewUtil(struct node* root, queue<node*>& q) 
{ 
    if (root == NULL) 
        return; 
  
    // Push root 
    q.push(root); 
  
    // Delimiter 
    q.push(NULL); 
  
    while (!q.empty()) { 
        node* temp = q.front(); 
  
        if (temp) { 
  
            // Prints first node 
            // of each level 
            cout << temp->data << " "; 
  
            // Push children of all nodes at 
            // current level 
            while (q.front() != NULL) { 
  
                // If left child is present 
                // push into queue 
                if (temp->left) 
                    q.push(temp->left); 
  
                // If right child is present 
                // push into queue 
                if (temp->right) 
                    q.push(temp->right); 
  
                // Pop the current node 
                q.pop(); 
  
                temp = q.front(); 
            } 
  
            // Push delimiter 
            // for the next level 
            q.push(NULL); 
        } 
  
        // Pop the delimiter of 
        // the previous level 
        q.pop(); 
    } 
} 
  
// Fucntion to print the leftView 
// of Binary Tree 
void leftView(struct node* root) 
{ 
    // Queue to store all 
    // the nodes of the tree 
    queue<node*> q; 
  
    leftViewUtil(root, q); 
} 
  
// Driver Code 
int main() 
{ 
    struct node* root = newNode(10); 
    root->left = newNode(12); 
    root->right = newNode(3); 
    root->left->right = newNode(4); 
    root->right->left = newNode(5); 
    root->right->left->right = newNode(6); 
    root->right->left->right->left = newNode(18); 
    root->right->left->right->right = newNode(7); 
  
    leftView(root); 
  
    return 0; 
} 
