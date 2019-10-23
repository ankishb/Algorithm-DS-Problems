
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
    bool is_leaf(TreeNode* root){
        return (root->right == NULL && root->left == NULL);
    }
    // leaf : 1, camera : 2, no-camera(but covered) : 3
    int helper(TreeNode* root, int &count){
        if(root == NULL) return 3;
        if(is_leaf(root)) return 1;
        
        int left = helper(root->left, count);
        int right = helper(root->right, count);
        // if its childs are leaf, we must install some camera
        // and return state of camera(2)
        if(left == 1 || right == 1){
            count++;
            return 2;
        }
        // if child have camera, its parent does't need camera
        else if(left == 2 || right == 2){
            return 3;
        }
        else{
            // else, it will be in no-camera(but covered) state, 
            // return 1, as next state
            return 1;
        }
    }
    
    int minCameraCover(TreeNode* root) {
        int count = 0;
        int temp = helper(root, count);
        // if root node comes in leaf state, we must install camera
        return (temp == 1) ? count+1 : count;
    }
};
/*
Explanation:

Apply a recusion function dfs.
Return 0 if it's a leaf.
Return 1 if it's a parent of a leaf, with a camera on this node.
Return 2 if it's coverd, without a camera on this node.

For each node,
if it has a child, which is leaf (node 0), then it needs camera.
if it has a child, which is the parent of a leaf (node 1), then it's covered.

If it needs camera, then res++ and we return 1.
If it's covered, we return 2.
Otherwise, we return 0.

    int res = 0;
    int minCameraCover(TreeNode* root) {
        return (dfs(root) < 1 ? 1 : 0) + res;
    }

    int dfs(TreeNode* root) {
        if (!root) return 2;
        int left = dfs(root->left), right = dfs(root->right);
        if (left == 0 || right == 0) {
            res++;
            return 1;
        }
        return left == 1 || right == 1 ? 2 : 0;
    }
*/