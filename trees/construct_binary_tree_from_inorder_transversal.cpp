
#include <bits/stdc++.h>
using namespace std;
#define v vector<int>
#define vv vector<vector<int> >

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

void trans(TreeNode* root){
	if(root == NULL) return;
	trans(root->left);
	cout<<root->val<<" ";
	trans(root->right);
}

int find_idx(v nums, int l_idx, int r_idx){
	int max_el = INT_MIN;
	int max_idx;
	for(int i=l_idx; i<=r_idx; i++){
		if(nums[i] > max_el){
			max_idx = i;
			max_el = nums[i];
		}
	}
	return max_idx;
}

TreeNode* construct_tree(TreeNode* root, vector<int> vect, int l_idx, int r_idx){
	if(l_idx > r_idx) return NULL;
	if(l_idx <= r_idx){
		int max_idx = find_idx(vect, l_idx, r_idx);
		TreeNode* temp = new TreeNode(vect[max_idx]);
		root = temp;
		root->left = construct_tree(root, vect, l_idx, max_idx-1);
		root->right = construct_tree(root, vect, max_idx+1, r_idx);
	}
	return root;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> vect(n, 0);
		for(int i=0; i<n; i++){
			cin>>vect[i];
		}
		TreeNode* root = NULL;
		root = construct_tree(root, vect, 0, n);
		trans(root);
		cout<<endl;
	}
	return 0;
}








// leetcode
/*
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
int find_max(vector<int> &nums, int left_idx, int right_idx){
    int max_el = INT_MIN;
    int max_idx;
    for(int i=left_idx; i<=right_idx; i++){
        if(nums[i] > max_el){
            max_el = nums[i];
            max_idx = i;
        }
    }
    return max_idx;
}

TreeNode* construct_tree(TreeNode* root, vector<int> nums, int l_idx, int r_idx){
    if(l_idx > r_idx) return NULL;
    
    if(l_idx <= r_idx){
        int max_idx = find_max(nums, l_idx, r_idx);
        TreeNode* temp = new TreeNode(nums[max_idx]);
        root = temp;
        root->left = construct_tree(root, nums, l_idx, max_idx-1);
        root->right = construct_tree(root, nums, max_idx+1, r_idx);
    }
    return root;
}


class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = NULL;
        return construct_tree(root, nums, 0, nums.size()-1);
    }
};
*/
