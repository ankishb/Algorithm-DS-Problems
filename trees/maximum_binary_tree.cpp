
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int get_max(vector<int> &A, int left, int right){
        int max_el = A[left], max_idx = left;
        for(int i=left+1; i<=right; i++){
            if(A[i] > max_el){
                max_el = A[i];
                max_idx = i;
            }
        }
        return max_idx;
    }

    TreeNode* efficient1(TreeNode* root, vector<int> nums, int l_idx, int r_idx){
        if(l_idx > r_idx) return NULL;
        
        if(l_idx <= r_idx){
            int max_idx = get_max(nums, l_idx, r_idx);
            root = new TreeNode(nums[max_idx]);
            root->left = efficient1(root, nums, l_idx, max_idx-1);
            root->right = efficient1(root, nums, max_idx+1, r_idx);
        }
        return root;
    }

    void efficient2(vector<int> &A, TreeNode* &root, int left, int right){
        int max_idx = get_max(A, left, right);
        root = new TreeNode(A[max_idx]);
        if(max_idx-1 >= left) efficient2(A, root->left, left, max_idx-1);
        if(max_idx+1 <= right) efficient2(A, root->right, max_idx+1, right);        
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = NULL;
        efficient2(nums, root, 0, nums.size()-1);
        return root;
        // return efficient1(root, nums, 0, nums.size()-1);
    }
};
