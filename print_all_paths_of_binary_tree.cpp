
#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};

node* get_new_node(int value){
	node *new_node = new node();
	new_node->data = value;
	new_node->left = NULL;
	new_node->right= NULL;
}

void print(vector<int> store){
	for(int i=0; i<store.size(); i++){
		cout<<store[i]<<" ";
	}
	cout<<endl;
}

void print_util(node *root, vector<int> &store){
	if(root == NULL){
		return;
	}

	store.push_back(root->data);
	if(root->left == NULL && root->right == NULL){
		print(store);
	}
	
	print_util(root->left, store);
	print_util(root->right, store);
	store.pop_back();
	
}

void print_all_paths(node *root){
	vector<int> store;
	print_util(root, store);
}

int main()
{
	node *root = NULL;
	root = get_new_node(10);
	root->left = get_new_node(16);
	root->right = get_new_node(5);

	// root->left->left = get_new_node(4);
	root->left->right = get_new_node(-3);

	root->right->left = get_new_node(6);
	root->right->right = get_new_node(11);

	print_all_paths(root);
	return 0;
}