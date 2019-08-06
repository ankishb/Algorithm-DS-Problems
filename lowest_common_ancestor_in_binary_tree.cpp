
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

bool find_path(node* root, int n, vector<int> &n_path){
	if(root==NULL){
		return false;
	}
	n_path.push_back(root->data);
	if(root->data == n){
		return true;
	}
	else if(find_path(root->left, n, n_path) 
		|| find_path(root->right, n, n_path)){
		return true;
	}
	else{
		n_path.pop_back();
		return false;
	}
}

void naive_solution(node* root, int n1, int n2){
	vector<int> n1_path;
	vector<int> n2_path;

	cout<<"\n---- Common ancestor ----\n";
	find_path(root, n1, n1_path);
	find_path(root, n2, n2_path);

	vector<int>::iterator it;
	for(it=n1_path.begin(); it!=n1_path.end(); ++it){
		cout<<*it<<" ";
	}
	cout<<endl;
	for(it=n2_path.begin(); it!=n2_path.end(); ++it){
		cout<<*it<<" ";
	}
	cout<<endl;

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


node* recursive_lowest_common_anestor(node* root, int n1, int n2){
	if(root == NULL){
		return NULL;
	}
	if(root->data == n1 || root->data == n2){
		return root;
	}
	node* left_lca = recursive_lowest_common_anestor(root->left, n1, n2);
	node* right_lca = recursive_lowest_common_anestor(root->right, n1, n2);

	if((left_lca==NULL) && (right_lca==NULL)){
		return NULL;
	}
	else if(left_lca && right_lca){
		return root;
	}
	else{
		return (left_lca==NULL)?right_lca:left_lca;
	}
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
	int n1, n2;
	while(test--){
		cin>>n1>>n2;
		// naive_solution(root, n1, n2);
		cout<<recursive_lowest_common_anestor(root, n1, n2)->data<<endl;
		// iterative_lowest_common_anestor(root, n1, n2);
	}
	

	return 0;
}







//
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool preorder(TreeNode* root, int data){
    if(root == NULL){
        return false;
    }
    if(root->val == data){
        return true;
    }
    else{
        bool left_ans = preorder(root->left, data);
        bool right_ans = preorder(root->right, data);
        return (left_ans == true || right_ans == true);
    }
}
TreeNode* recursion(TreeNode* root, int n1, int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->val == n1 || root->val == n2){
        return root;
    }
    TreeNode* left_lca = recursion(root->left, n1, n2);
    TreeNode* right_lca = recursion(root->right, n1, n2);
    if(left_lca == NULL && right_lca == NULL){
        return NULL;
    }
    else if(left_lca && right_lca){
        return root;
    }
    else{
        return (left_lca==NULL)?right_lca:left_lca;
    }
    
}
int Solution::lca(TreeNode* A, int B, int C) {
    // first check, if both node exist in the tree or not,
    // if yes, then proceed further, else return -1
    if(A == NULL){
        return -1;
    }
    // cout<<"for B: "<<preorder(A, B)<<endl;
    // cout<<"for C: "<<preorder(A, C)<<endl;
    
    if(preorder(A, B) && preorder(A, C)){
        TreeNode* ans = recursion(A, B, C);
        return (ans != NULL)?ans->val:-1;
    }
    else{
        return -1;
    }
}
