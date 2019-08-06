
#include <bits/stdc++.h>
using namespace std;

struct BSTnode{
	int data;
	BSTnode* left;
	BSTnode* right;
};

BSTnode* GetNewNode(int data){
	// create new node and insert data
	BSTnode* newNode = new BSTnode();
	// (*newNode).data = data;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
}

// To retun the root node
BSTnode* insert(BSTnode* root, int data){
	if(root == NULL){
		root = GetNewNode(data);
	}
	else if(data <= root->data){
		root->left = insert(root->left, data);
	}
	else{
		root->right = insert(root->right, data);
	}
	return root;
}

bool search(BSTnode* root, int data){
	if(root == NULL){
		return false;
	}
	else if(root->data == data){
		return true;
	}
	else if(data <= root->data){
		return search(root->left, data);
	}
	else{
		return search(root->right, data);
	}
}

int main()
{
	BSTnode* root = NULL;
	root = insert(root, 10);
	root = insert(root, 15);
	root = insert(root, 20);

	if(search(root, 20) == true) cout<<"Found\n";
}

// we used ** to 
void insert(BSTnode** root_ptr, int data){
	if (*root_ptr == NULL){
		*root_ptr = GetNewNode(data);
	}
}

int main()
{
	BSTnode* root = NULL; //empty tree
	insert(root, 15);
	insert(root, 10);
	insert(root, 20);

}


