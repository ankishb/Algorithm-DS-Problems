
class Solution {
public:
    TreeNode* ans;
    
    bool lcs(TreeNode* root, TreeNode* p, TreeNode* q, bool &found){
        if(root == NULL) return false;
        // cout << found << " ";
        if(found) return false;
        
        bool lb = lcs(root->left, p, q, found);
        bool rb = lcs(root->right, p, q, found);
        
        if(!found && (root == p && (lb || rb)) 
           || (root == q && (lb ||rb)) || (lb && rb)){
            ans = root;
            found = true;
        }
        
        return (lb || rb || root == p || root == q);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool flag, found = false;
        flag = lcs(root, p, q, found);
        return ans;
    }
};


// super new try
/*
1. If root is matched with either one of them, we get ans
2. If root is less than one of them and greater for other, we get ans
3. If both in left subtree or right subtree, we move towards it
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return root;
        int rv = root->val, pv = p->val, qv = q->val;
        if(rv == pv || rv == qv) return root;
        if((rv > pv && rv < qv) || (rv > qv && rv < pv)){
            return root;
        }
        else if(rv > pv && rv > qv){
            return lowestCommonAncestor(root->left, p, q);
        }
        else if(rv < pv && rv < qv){
            return lowestCommonAncestor(root->right, p, q);
        }
        else return NULL;
    }
};


// optimal1: same as binary tree (search naively)
// optimal2: search using BST property
// best: Avoid naivesness of optimal2 solution, by completely taking advantage of BST property
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
        // return optimal2(root, p, q);
        return new_try(root, p, q);
    }
    
    TreeNode* new_try(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;
        int rv = root->val, pv = p->val, qv = q->val;
        if(rv == pv || rv == qv) return root;
        else if(rv < pv && rv < qv){
            return new_try(root->right, p, q);
        }
        else if(rv > pv && rv > qv){
            return new_try(root->left, p, q);
        }
        else if((rv > pv && rv < qv) || rv < pv && rv > qv){
            return root;
        }
        else{
            return NULL;
        }
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