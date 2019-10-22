
#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int data):val(data), left(NULL), right(NULL){}
};

int find_boundary(vector<int> A, int left, int right){
	int i;
	for(i=left+1; i<=right; i++){
		if(A[i] > A[left]) break;
	}
	return i;
}

TreeNode* built_tree(vector<int> A, int left, int right){
	if(left > right) return NULL;
	TreeNode *root = new TreeNode(A[left]);
	int idx = find_boundary(A, left, right);
	root->left = built_tree(A, left+1, idx-1);
	root->right = built_tree(A, idx, right);
	return root;
}

void postorder_trans(TreeNode* root){
	if(root == NULL) return;
	postorder_trans(root->left);
	postorder_trans(root->right);
	cout<<root->val<<" ";
}

int main()
 {
	int test;
	cin>>test;
	while(test--){
	    int n;
	    cin>>n;
	    vector<int> A(n);
	    for(int i=0; i<n; i++){
	        cin>>A[i];
	    }
	    TreeNode* root = built_tree(A, 0, n-1);
	    postorder_trans(root);
	    cout<<endl;
	}
	return 0;
}