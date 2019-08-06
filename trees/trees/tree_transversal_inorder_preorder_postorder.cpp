// inorder  : left, root, right
// preorder : root, left, right 
// postorder: left, right, root

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


void inorder(node* root){
	// inorder: left, root, right
	if(root == NULL){
		return ;
	}
	else{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

void preorder(node* root){
	// preorder:  root, left, right 
	if(root == NULL){
		return ;
	}
	else{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node* root){
	// postorder: left, right, root
	if(root == NULL){
		return;
	}
	else{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}

int main()
{
	node* root = NULL; // init NULL tree
	root              = GetNewNode(25);
	root->left        = GetNewNode(15); 
  	root->right       = GetNewNode(50); 
	
	root->left->left  = GetNewNode(10); 
	root->left->right = GetNewNode(22); 

	root->right->left  = GetNewNode(35); 
	root->right->right = GetNewNode(70); 

	root->left->left->left  = GetNewNode(4); 
	root->left->right->left = GetNewNode(18); 
	root->left->right->right = GetNewNode(24); 

	/* 		   25
	         /     \
	       /        \ 
	      15         50 
	    /   \ 		/  \ 
	   10  	 22   35    70	
	  /     /  \ 
	 4    18    24
	*/


	cout<<"preorder : root, left, right \n";
	preorder(root);
	cout<<"\n ============ \n";

	cout<<"inorder  : left, root, right \n";
	inorder(root);
	cout<<"\n ============ \n";

	cout<<"postorder: left, right, root \n";
	postorder(root);
	cout<<"\n ============ \n";

  	return 0;
}