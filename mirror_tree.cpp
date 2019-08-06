// https://www.geeksforgeeks.org/check-if-two-trees-are-mirror/

#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* getNewNode(int data){
	node* newNode = new node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
}

bool check_mirror_tree(node* A, node* B){
	if(A==NULL || B==NULL){
		return false;
	}
	else if(A != B){
		return false;
	}
	else{
		return true;
	}
	check_mirror_tree(A->left, B->right);
	check_mirror_tree(A->right, B->left);
}

int main()
{
	// 	   10          10
	//    /  \        /  \ 
	//   20  30      30  20
	//  /  \         	 / \ 
	// 40  60  	  	    60  40 
	node* A = NULL;
	A = getNewNode(10);
	A->left = getNewNode(20);
	A->right = getNewNode(30);
	A->left->left = getNewNode(40);
	A->left->right = getNewNode(60);

	node* B = NULL;
	B = getNewNode(10);
	B->left = getNewNode(30);
	B->right = getNewNode(20);
	B->left->left = getNewNode(60);
	B->left->right = getNewNode(40);
	// B->left->right->left = getNewNode(40);
	

	check_mirror_tree(A, B) ? cout<<"It is Mirrored tree" : cout<<"It is not a mirrored tree";
	return 0;
}
















// // transverse through all nodes present on level
// #include <bits/stdc++.h>
// using namespace std;

// struct node{
// 	int data;
// 	node* left;
// 	node* right;
// };

// node* GetNewNode(int data){
// 	node* newNode = new node();
// 	newNode->data = data;
// 	newNode->left = NULL;
// 	newNode->right = NULL;
// }

// int main()
// {
// 	node* root = NULL; // init NULL tree
// 	root = GetNewNode(1);
// 	/* following is the tree after above statement  
	  
// 	        1 
// 	      /   \ 
// 	     NULL  NULL   
// 	*/
    
  
//   	root->left        = GetNewNode(2); 
//   	root->right       = GetNewNode(3); 
// 	/* 2 and 3 become left and right children of 1 
// 	           1 
// 	         /   \ 
// 	        2      3 
// 	     /    \    /  \ 
// 	    NULL NULL NULL NULL 
// 	  */
	  
  
//   	root->left->left  = GetNewNode(4); 
// 	/* 4 becomes left child of 2 
// 	           1 
// 	       /       \ 
// 	      2          3 
// 	    /   \       /  \ 
// 	   4    NULL  NULL  NULL 
// 	  /  \ 
// 	NULL NULL 
// 	*/

//   	cout<<"tree was created successfully...";
//   	return 0;
// }

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool check_mirror(TreeNode* root1, TreeNode* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL || root2==NULL){
        return false;
    }
    return (root1->val == root2->val)&&
           check_mirror(root1->left, root2->right)&&
           check_mirror(root1->right, root2->left);
}

int Solution::isSymmetric(TreeNode* root) {
    return check_mirror(root, root);
}
