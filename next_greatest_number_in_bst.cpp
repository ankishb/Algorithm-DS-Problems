// https://www.interviewbit.com/problems/next-greater-number-bst/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* searchNode(TreeNode* root, int B){
    if(root->val == B){
        return root;
    }
    else if(root->val < B){
        return searchNode(root->right, B);
    }
    return searchNode(root->left, B);
}
 
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    TreeNode* required = searchNode(A, B);
    TreeNode* prev = NULL;
    TreeNode* ancestor = A;
    TreeNode* successor = NULL;
    
    if(required == NULL){
        return NULL;
    }
    else if(required->right != NULL){
        prev = required->right;
        TreeNode* temp = required->right;
        while(temp != NULL){
            prev = temp;
            temp = temp->left;
        }
        return prev;
    }
    else{
        while(ancestor != required){
            if(ancestor->val < B){
                ancestor = ancestor->right;
            }
            else{ // ancestor->val > B
                successor = ancestor;
                ancestor = ancestor->left;
            }
        }
    }
    
    return successor;
    
}







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