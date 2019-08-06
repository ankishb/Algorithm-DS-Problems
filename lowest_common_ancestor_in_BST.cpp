
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

bool BST_path(node* root, int n, vector<int> &n_path){
	if(root==NULL){
		return false;
	}
	else if(root->data==n){
		cout<<root->data<<"\n";
		n_path.push_back(root->data);
		return true;
	}
	cout<<root->data<<" ";
	n_path.push_back(root->data);

	if(n > root->data){
		BST_path(root->right, n, n_path);
	}
	else{
		BST_path(root->left, n, n_path);
	}
}

void naive_solution(node* root, int n1, int n2){
	vector<int> n1_path;
	vector<int> n2_path;

	cout<<"\n---- Common ancestor ----\n";
	BST_path(root, n1, n1_path);
	BST_path(root, n2, n2_path);

	int common = n1_path[0];
	for(int i=1; i<min(n1_path.size(), n2_path.size()); i++){
		if(n1_path[i] == n2_path[i]){
			common = n1_path[i];
		}
		else{
			break;
		}
	}
	cout<<common;
	cout<<"\n---- Common ancestor ----\n";
}

int recursive_lowest_common_anestor(node* root, int n1, int n2){
	if(root==NULL){
		return 0;
	}
	
	if((n1 < root->data) && (n2 > root->data)){
		return root->data;
	}
	else if((n1 > root->data) && (n2 < root->data)){
		return root->data;
	}
	else if((n1 < root->data) && (n2 < root->data)){
		recursive_lowest_common_anestor(root->left, n1, n2);
	}
	else{
		recursive_lowest_common_anestor(root->right, n1, n2);;
	}
}

void iterative_lowest_common_anestor(node* root, int n1, int n2){
	if(root==NULL){
		cout<<" "<<endl;
	}
	while(root!=NULL){
		// if((n1 < root->data) && (n2 > root->data)){
		// 	cout<<root->data<<endl;
		// 	break;
		// }
		// else if((n1 > root->data) && (n2 < root->data)){
		// 	cout<<root->data<<endl;
		// 	break;
		// }
		if((n1 < root->data) && (n2 < root->data)){
			root = root->left;
		}
		else if((n1 > root->data) && (n2 > root->data)){
			root = root->right;
		}
		else{
			cout<<root->data<<endl;
			break;
		}
	}
}

void rec(node* n1, node* n2){
	
}

int main()
{
	node* root = NULL;
	root = get_new_node(20);
	root->left = get_new_node(8);
	root->right = get_new_node(22);
	
	root->left->left = get_new_node(4);
	root->left->right = get_new_node(12);

	root->left->right->left = get_new_node(10);
	root->left->right->right = get_new_node(14);
	
	int test;
	cin>>test;
	int n1, n2;
	while(test--){
		cin>>n1>>n2;
		// naive_solution(root, n1, n2);
		cout<<rec(root, n1, n2)<<endl;
		// cout<<recursive_lowest_common_anestor(root, n1, n2)<<endl;
		// iterative_lowest_common_anestor(root, n1, n2);
	}
	

	return 0;
}