// transverse through all nodes present on level
#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* GetNewNode(int data){
	node* newNode = new node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
}

int main()
{
	node* root = NULL; // init NULL tree
	root = GetNewNode(1);
	/* following is the tree after above statement  
	  
	        1 
	      /   \ 
	     NULL  NULL   
	*/
    
  
  	root->left        = GetNewNode(2); 
  	root->right       = GetNewNode(3); 
	/* 2 and 3 become left and right children of 1 
	           1 
	         /   \ 
	        2      3 
	     /    \    /  \ 
	    NULL NULL NULL NULL 
	  */
	  
  
  	root->left->left  = GetNewNode(4); 
	/* 4 becomes left child of 2 
	           1 
	       /       \ 
	      2          3 
	    /   \       /  \ 
	   4    NULL  NULL  NULL 
	  /  \ 
	NULL NULL 
	*/

  	cout<<"tree was created successfully...";
  	return 0;
}