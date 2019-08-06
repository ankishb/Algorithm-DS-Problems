
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
	return new_node;
}

void inorder_tran(node* root){
	if(root == NULL){
		return ;
	}
	inorder_tran(root->left);
	cout<<root->data<<" ";
	inorder_tran(root->right);
}

node* make_bst(vector<int> vect, int left, int right){
	if(left > right){
		return NULL;
	}
	int mid = left + (right-left)/2;
	cout<<mid+1<<" ";
	node* root = get_new_node(vect[mid]);
	root->left = make_bst(vect, left, mid-1);
	root->right = make_bst(vect, mid+1, right);

	return root;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int el;
		vector<int> vect;
		while(n--){
			cin>>el;
			vect.push_back(el);
		}

		node* root = NULL;
		cout<<"\n --making BST--\n ";
		root = make_bst(vect, 0, vect.size()-1);

		cout<<"\n --verify BST using Inorder Tranversal--\n";
		inorder_tran(root);
	}
	return 0;
}