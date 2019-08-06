// https://www.geeksforgeeks.org/search-a-node-in-binary-tree/

// The idea here is to tranverse through tree and check if it match. Note that, we have to check for both sides of the node, and final ans is the OR operation of both subtree.

#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* get_new_node(int data){
	node* root = new node();
	root->data = data;
	root->left = NULL;
	root->right = NULL;
}

// preorder tranversal
bool search_node(node* root, int key){
	if(root == NULL){
		return false;
	}
	else if(root->data == key){
		return true;
	}
	cout<<root->data<<endl;
	bool s1 = search_node(root->left, key);
	bool s2 = search_node(root->right, key);

	return s1||s2;	
}

int main()
{
	node* root=NULL;

	root = get_new_node(0); 
    root->left = get_new_node(1); 
    root->right = get_new_node(2); 
    
    root->left->left = get_new_node(3); 
    root->left->right = get_new_node(4); 
    
    root->right->left = get_new_node(5); 
    root->right->right = get_new_node(6); 

    root->left->left->left = get_new_node(7); 
    
    root->left->right->left = get_new_node(8); 
    root->left->right->right = get_new_node(9); 
    
    int key;
    cin>>key;

    search_node(root, key) ? cout<<"Found\n" : cout<<"Not Found\n";

    return 0;
}