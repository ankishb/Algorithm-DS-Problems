
// 	           3 
// 	       /       \ 
// 	      2          5 
// 	    /   \    
// 	   1     4 
	
// For example, consider the following tree. If the input key is 3, then your function should return 1. If the input key is 4, then your function should return 3. And for key which is not present in key, then your function should return 0.



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

int get_level(node* root, int data, int level){
	cout<<root->data<<"=="<<level<<endl;
	if(root == NULL){
		return -1;
	}
	else if(data == root->data){
		return level;
	}
	else if(data < root->data){
		get_level(root->left, data, level+1);
	}
	else if(data > root->data){
		get_level(root->right, data, level+1);
	}
	else{
		return -1;
	}
}


int main()
{
	node* root = NULL; // init NULL tree
	root              = GetNewNode(3);
	root->left        = GetNewNode(2); 
  	root->right       = GetNewNode(5); 
	root->left->left  = GetNewNode(1); 
	root->left->right = GetNewNode(4); 

	int level = 1;
	cout<< 3 <<"==>"<<get_level(root, 3, level)<<"\n";
	cout<<"========\n";
	cout<< 4 <<"==>"<<get_level(root, 4, level)<<"\n";
	cout<<"========\n";
	cout<< -1 <<"==>"<<get_level(root, -1, level)<<"\n";
  	cout<<"========\n";
	// cout<<"tree was created successfully...";
  	return 0;
}