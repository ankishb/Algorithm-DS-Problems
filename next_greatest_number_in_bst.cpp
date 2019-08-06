
#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* get_new_node(int val){
	node* new_node = new node();
	new_node->data = val;
	new_node->left = NULL;
	new_node->right = NULL;
}

node* find_BST(node* root, int k){
	if(root->data == k){
		return root;
	}
	if(root->data > k){
		root = find_BST(root->left, k);
	}
	else{
		root = find_BST(root->right, k);
	}
}

node* find_successor(node* root, int k){
	if(root == NULL){
		return NULL;
	}
	node* cur_node = find_BST(root, k);
	cout<<cur_node->data<<endl;
	return cur_node;
} 


int main()
{
	node* root = NULL;
	root = get_new_node(1);
	root->left = get_new_node(2);
	root->right = get_new_node(3);
	
	root->left->left = get_new_node(4);
	root->left->right = get_new_node(5);

	root->right->left = get_new_node(6);
	root->right->right = get_new_node(7);
	
	int test;
	cin>>test;
	while(test--){
		int k;
		cin>>k;
		node* ans = find_successor(root, k);
		cout<<ans->data<<" ";
		if(ans->left != NULL){
			cout<<ans->left->data<<" ";
		}
		if(ans->right != NULL){
			cout<<ans->right->data;
		}
		cout<<endl;
	}

	return 0;
}