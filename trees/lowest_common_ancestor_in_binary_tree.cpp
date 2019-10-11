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
    bool search(TreeNode* root, TreeNode* val){
        if(root == NULL) return false;
        if(root == val) return true;
        return search(root->left, val) || search(root->right, val);
    }
    
    TreeNode* recursive1(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
        
        bool l1 = search(root->left,  p);
        bool r1 = search(root->right, q);
        if(l1 && r1) return root;
        
        bool l2 = search(root->right, p);
        bool r2 = search(root->left,  q);
        if(l2 && r2) return root;
        if(l1 && r2) return recursive1(root->left, p, q);
        if(r1 && l2) return recursive1(root->right, p, q);
        return NULL;
    }
    
    TreeNode* recursive2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        TreeNode* l_lcs = recursive2(root->left, p, q);
        TreeNode* r_lcs = recursive2(root->right, p, q);
        if(l_lcs && r_lcs) return root;
        return (l_lcs == NULL) ? r_lcs : l_lcs;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return recursive1(root, p, q);
        // return recursive2(root, p, q);
    }
};


// recursive1: naive approach: search for nodes in each subtree, time complexity is O(n^2)
// recursive2: optimal: O(n)
class Solution {
public:
    bool search(TreeNode* root, TreeNode* val){
        if(root == NULL) return false;
        if(root == val) return true;
        return search(root->left, val) || search(root->right, val);
    }
    
    TreeNode* recursive1(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
        
        bool l1 = search(root->left,  p);
        bool r1 = search(root->right, q);
        if(l1 && r1) return root;
        
        bool l2 = search(root->right, p);
        bool r2 = search(root->left,  q);
        if(l2 && r2) return root;
        if(l1 && r2) return recursive1(root->left, p, q);
        if(r1 && l2) return recursive1(root->right, p, q);
        return NULL;
    }
    
    TreeNode* recursive2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        TreeNode* l_lcs = recursive2(root->left, p, q);
        TreeNode* r_lcs = recursive2(root->right, p, q);
        if(l_lcs && r_lcs) return root;
        return (l_lcs == NULL) ? r_lcs : l_lcs;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return recursive1(root, p, q);
        // return recursive2(root, p, q);
    }
};


// old geeksforgeeks
// binary tree node
Node * LCA(Node* root ,int n1 ,int n2 ){
	if(root==NULL){
		return NULL;
	}
	if(root->data == n1 || root->data == n2){
		return root;
	}
	Node* left_lca = LCA(root->left, n1, n2);
	Node* right_lca = LCA(root->right, n1, n2);

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
