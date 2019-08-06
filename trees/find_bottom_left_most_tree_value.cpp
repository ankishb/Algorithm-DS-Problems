/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int level_order_tran(TreeNode* root){
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	TreeNode* top;
	while(true){
		if(q.size()==1 && q.front()==NULL) break;
		top = q.front();
		q.pop();
		
		if(top->right != NULL){
			q.push(top->right);
		}
        if(top->left != NULL){
			q.push(top->left);
		}
        
		if(q.front() == NULL){
			q.pop();
			q.push(NULL);
		}
	}
	return top->val;
}
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        return level_order_tran(root);
    }
};








// recusive sol, by tracking depth of tree
class Solution {
public:
    void findBottomLeftValue(TreeNode* root, int& maxDepth, int& leftVal, int depth) {
        if (root == NULL) {
            return;
        }
        //Go to the left and right of each node 
        findBottomLeftValue(root->left, maxDepth, leftVal, depth+1);
        findBottomLeftValue(root->right, maxDepth, leftVal, depth+1);
        
        //Update leftVal and maxDepth
        if (depth > maxDepth) {
            maxDepth = depth;
            leftVal = root->val;
        }
    }
    
    //Entry function
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = 0;
        //Initialize leftVal with root's value to cover the edge case with single node
        int leftVal = root->val;
        findBottomLeftValue(root, maxDepth, leftVal, 0);
        return leftVal;
    }
};




// using DFS
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        pair<int,int> result(root->val,1); //root!=null
        dfs(root,1,result);
        return result.first;
    }
private:
    void dfs(TreeNode* root, int height, pair<int,int> &res)
    {
        if(!root->left && !root->right && height>res.second)
        {
            res = make_pair(root->val,height);
        }
        if(root->left) dfs(root->left,height+1,res);
        if(root->right) dfs(root->right,height+1,res);
    }
};