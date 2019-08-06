// https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1
// https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1/?ref=self

#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* get_new_node(int data){
	node* new_node = new node();
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
}

// Node* insert(Node* node, int data){
// 	if(node==NULL){
// 		node = new Node(data);
// 		return node;
// 	}
// 	else if(data > node->data){
// 		node->right = insert(node->right, data);
// 	}
// 	else if(data < node->data){
// 		node->left = insert(node->left, data);
// 	}
// 	else if(data = node->data){
// 	    return node;
// 	}
// }


node* insert(node* root, int data){
	if(root==NULL){
		root = get_new_node(data);
		return root;
	}
	else if(data > root->data){
		root->right = insert(root->right, data);
	}
	else if(data < root->data){
		root->left = insert(root->left, data);
	}
}

void inorder_transversal(node* root){
	if(root == NULL){
		return ;
	}
	inorder_transversal(root->left);
	cout<<root->data<<" ";
	inorder_transversal(root->right);
}

void create_BST(){
	int n;
	cin>>n;
	int arr[n];

	node* root = NULL;
	node* main_r = NULL;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		cout<<"inserting data: "<<arr[i]<<endl;
		
		if (i==0){
			root = insert(root, arr[i]);
			main_r = root;
		}
		else{
			insert(root, arr[i]);
		}
	}

	inorder_transversal(main_r);
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		create_BST();
	}
	return 0;
}