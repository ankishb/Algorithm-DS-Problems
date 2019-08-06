
// Recursive Preorder Transversal 
// 1 -1 -2 -3 5 11 21 6 
// Iterative Preorder Transversal 
// 1 -1 -2 -3 5 11 21 6 

#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* getNewNode(int data){
	node* newNode = new node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
}

void rec_preorder_transversal(node *root){
	if(root == NULL){
		return ;
	}
	cout<<root->data<<" ";
	rec_preorder_transversal(root->left);
	rec_preorder_transversal(root->right);
}




void itr_preorder_transversal(node *root){
	stack<node*> s;
	s.push(root);
	node *top;

	while(!s.empty()){
		top = s.top();
		cout<<top->data<<" ";
		s.pop();
		if(top->right == NUll && top->left == NULL){
			continue;
		}
		if(top->right != NULL){
			s.push(top->right);
		}
		if(top->left != NULL){
			s.push(top->left);
		}
	}
}


int main()
{
	node* root = NULL;
	root = getNewNode(1);
	root->left = getNewNode(-1);
	root->right = getNewNode(11);
	root->left->left = getNewNode(-2);
	root->left->right = getNewNode(-3);
	root->left->right->right = getNewNode(5);
	root->right->left = getNewNode(21);
	root->right->right = getNewNode(6);

	cout<<"\nRecursive Preorder Transversal \n";
	rec_preorder_transversal(root);
	
	cout<<"\nIterative Preorder Transversal \n";
	itr_preorder_transversal(root);

	return 0;
}

