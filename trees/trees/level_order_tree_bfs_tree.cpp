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

// Approach:
// 1. if level == 1: it will be root node(print it)
// 2. if level>1: 
// 	pick left of that node, and iterate through it, each time we do it, decrease level by 1.

void print_given_level(node* root, int level){
	if(root == NULL){
		// cout<<"empty tree";
		return;
	}
	else if(level == 0){ // top level
		// only one node(root)
		cout<<root->data<<" ";
	}
	else if(level >= 1){
		print_given_level(root->left, level-1);
		print_given_level(root->right, level-1);
	}
}

int get_height(node* root){
	if(root == NULL){
		return 0;
	}
	else{
		int left_height = get_height(root->left);
		int right_height = get_height(root->right);

		if(left_height > right_height){
			return left_height+1;
		}
		else{
			return right_height+1;
		}
	}
}

void level_order_treansversal(node* root){
	int height = get_height(root);
	for(int i=0; i<height; i++){
		print_given_level(root, i);
		cout<<endl;
	}
	cout<<"Done with tranversal\n";
}

int main()
{
	node* root = NULL; // init NULL tree
	root              = GetNewNode(1);
	root->left        = GetNewNode(2); 
  	root->right       = GetNewNode(3); 
	root->left->left  = GetNewNode(4); 
	/* 4 becomes left child of 2 
	           1 
	         /    \ 
	       /        \ 
	      2          3 
	    /   \       /  \ 
	   4    NULL  NULL  NULL 
	  /  \ 
	NULL NULL 
	*/

	level_order_treansversal(root);
  	// cout<<"tree was created successfully...";
  	return 0;
}