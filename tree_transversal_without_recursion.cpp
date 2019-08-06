
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

void inorder_transversal(node* root){
	stack<node*> s;
	node* cur_node = root;
	while(cur_node != NULL || !s.empty()){

		while(cur_node != NULL){
			s.push(cur_node);
			cur_node = cur_node->left;
		}

		// now it reach at the leaf, print it and go one node back, that is the parent of this leaf node.
		cur_node = s.top();
		s.pop();
		cout<<cur_node->data<<" ";
		cur_node = cur_node->right;
	}
}

void postorder_transversal(node *root){
	stack<node*> s;
	if(root == NULL){
		cout<<"NULL";
	}
	else{
		s.push(root);
		root = root->left;
		while(!s.empty()){
			int top = s.top();
			if(root != NULL){
				s.push(root);
				root = root->left;
			}
			else{
				cout<<top->data<<" ";
				s.pop();
				top = s.top();
				if(top->right != NULL){
					s.top(top->right);
				}
			}
		}
	}
}


int main()
{
	node* root = NULL;
	root = getNewNode(3);
	root->left = getNewNode(9);
	root->right = getNewNode(20);
	root->right->left = getNewNode(15);
	root->right->right = getNewNode(7);

	inorder_transversal(root);

	return 0;
}

