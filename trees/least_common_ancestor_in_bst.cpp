
// optimal1: same as binary tree (search naively)
// optimal2: search using BST property
class Solution {
public:
    TreeNode* optimal1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        TreeNode* l_lcs = optimal1(root->left, p, q);
        TreeNode* r_lcs = optimal1(root->right, p, q);
        if(l_lcs && r_lcs) return root;
        return (l_lcs == NULL) ? r_lcs : l_lcs;
    }
    TreeNode* optimal2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        int rv = root->val, pv = p->val, qv = q->val;
        if(rv > pv && rv > qv) return optimal2(root->left, p, q);
        if(rv < pv && rv < qv) return optimal2(root->right, p, q);
        else{
            TreeNode* l_lcs = optimal2(root->left, p, q);
            TreeNode* r_lcs = optimal2(root->right, p, q);
            if(l_lcs && r_lcs) return root;
            return (l_lcs == NULL) ? r_lcs : l_lcs;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // return optimal1(root, p, q);
        return optimal2(root, p, q);
    }
};




// old geeksforgeeks Iterative approach
Node* LCA(Node *root, int n1, int n2){
	if(root==NULL){
		cout<<" "<<endl;
	}
	bool break_flag = false;
	while(root!=NULL && break_flag==false){
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
// 			cout<<root->data<<endl;
			return root;
			break_flag = true;
		}
	}
}