
class Solution {
private:
    vector<TreeNode*> helper(int start, int end){
        vector<TreeNode*> res;
        if(start > end) {
            res.push_back(NULL);
            return res;
        }
        for(int i = start; i <= end; i++){
            vector<TreeNode*> lefts = helper(start, i - 1);
            vector<TreeNode*> rights = helper(i + 1, end);
            for(int j = 0; j < (int)lefts.size(); j++){
                for(int k = 0; k < (int)rights.size(); k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = lefts[j];
                    root->right = rights[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>(0);
        return helper(1,n);
    }
};




explaination:
Given a tree which n nodes, it has the follwing form:
(0)root(n-1)
(1)root(n-2)
(2)root(n-3)
where (x) denotes the trees with x nodes.

Now take n=3 for example. Given n=3, we have [1 2 3] in which each of them can be used as the tree root.

when root=1: [1 # 2 # 3]; [1 # 3 2];
when root=2: [2 1 3];
when root=3: (similar with the situations when root=1.)

Thus, if we write a recursive function who generates a group of trees in which the numbers range from f to t, we have to generate the left trees and right trees of each tree in the vector.

I give the following recursive code and expect to see non-recursive ones. please!

code:

vector<TreeNode *> generateTree(int from, int to)
{
    vector<TreeNode *> ret;
    if(to - from < 0) ret.push_back(0);
    if(to - from == 0) ret.push_back(new TreeNode(from));
    if(to - from > 0)
    {
        for(int i=from; i<=to; i++)
        {
            vector<TreeNode *> l = generateTree(from, i-1);
            vector<TreeNode *> r = generateTree(i+1, to);

            for(int j=0; j<l.size(); j++)
            {
                for(int k=0; k<r.size(); k++)
                {
                    TreeNode * h = new TreeNode (i);
                    h->left = l[j];
                    h->right = r[k];
                    ret.push_back(h);
                }
            }
        }
    }
    return ret;
}

vector<TreeNode *> generateTrees(int n) {
    return generateTree(1, n);
}





/*
// elegant solution and explanation
The basic idea is that we can construct the result of n node tree just from the result of n-1 node tree.
Here's how we do it: only 2 conditions: 1) The nth node is the new root, so newroot->left = oldroot;
2) the nth node is not root, we traverse the old tree, every time the node in the old tree has a right child, we can perform: old node->right = nth node, nth node ->left = right child; and when we reach the end of the tree, don't forget we can also add the nth node here.
One thing to notice is that every time we push a TreeNode in our result, I push the clone version of the root, and I recover what I do to the old node immediately. This is because you may use the old tree for several times.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode * clone(TreeNode * root){
        if(NULL == root) return NULL;
        TreeNode * newRoot = new TreeNode(root->val);
        newRoot->left = clone(root->left);
        newRoot->right = clone(root->right);
        return newRoot;
    }
    void addToLeft(TreeNode * oldRoot, TreeNode * newRoot, vector<TreeNode *> & results){
        TreeNode * cloneRoot = clone(oldRoot);
        newRoot->left = cloneRoot;
        results.push_back(newRoot);
    }
    void addRight(TreeNode * oldRoot, TreeNode * cur, TreeNode * newNode, vector<TreeNode *> & results){
        TreeNode *cloneRoot = clone(oldRoot);
        TreeNode *newCur = cloneRoot;
        while(NULL != newCur){
            if(newCur->val == cur->val) break;
            else newCur = newCur->right;
        }
        assert(NULL != newCur);
        TreeNode * temp = newCur->right;
        newCur->right = newNode;
        newNode->left = temp;
        results.push_back(cloneRoot);
    }
public:
    vector<TreeNode *> generateTrees(int n) {
        // DP:
        // for n-1 to n , for each n -1
        // 1) left to n
        // 2) for each right child down
        //    n replace right and right will be n left
        vector<TreeNode *> results;
        vector<TreeNode *> preResults(1, NULL);
        for(int i = 1; i <=n; i ++){
            for(int j = 0; j < preResults.size(); j++){
                // add n-1 left to n 
                TreeNode * oldRoot = preResults[j];
                TreeNode * newRoot = new TreeNode(i);
                addToLeft(oldRoot, newRoot, results);
                TreeNode * cur = oldRoot;
                while(NULL != cur){
                    TreeNode *newNode = new TreeNode(i);
                    addRight(oldRoot, cur, newNode, results);
                    cur = cur->right;
                }
            }
            swap(results, preResults);
            results.clear();
        }
        return preResults;
    }
};



