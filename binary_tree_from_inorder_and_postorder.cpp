
#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* get_new_node(int data){
	node* new_node = new node();
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

void inorder_tran(node* root){
	if(root == NULL){
		return ;
	}
	inorder_tran(root->left);
	cout<<root->data<<" ";
	inorder_tran(root->right);
}

node* binary_tree(vector<int> inorder, vector<int> postorder, unordered_map<int, int> my_map, int start, int end, int post_idx){
	if(start>end){
		return NULL;
	}
	int cur_ele = postorder[post_idx];
	node* root = get_new_node(cur_ele);
	post_idx--;
	
	int inorder_idx = my_map[cur_ele];
	root->right = binary_tree(inorder, postorder, my_map, inorder_idx+1, end, post_idx);
	root->left = binary_tree(inorder, postorder, my_map, start, inorder_idx-1, post_idx);

	return root;
}

void make_binary_tree(vector<int> inorder, vector<int> postorder){
	unordered_map<int, int> my_map;
	for(int i=0; i<inorder.size(); i++){
		my_map[inorder[i]] = i;
	}
	int post_idx = postorder.size()-1;
	node* root = binary_tree(inorder, postorder, my_map, 0, inorder.size()-1, post_idx);

	cout<<"\n --verify Binary Tree using Inorder Tranversal--\n";
	inorder_tran(root);
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int el;
		vector<int> inorder;
		vector<int> postorder;
		for(int i=0; i<n; i++){
			cin>>el;
			inorder.push_back(el);
		}
		for(int i=0; i<n; i++){
			cin>>el;
			postorder.push_back(el);
		}

		cout<<"\n --making Binary tree--\n ";
		make_binary_tree(inorder, postorder);

	}
	return 0;
}










    public static TreeNode sufficientSubset(TreeNode root, int limit) {
        if (root == null)
            return root;
        editTree(root, limit);
        if (toBeDeleted.contains(root))
            root = null;
        return root;
    }

    private static void editTree(TreeNode root, int limit) {
        //1. if root is null, nothing to do
        if (root == null) return;
        //2. We have to traverse upto the leaf, use recursion
        editTree(root.left, limit - root.val);
        editTree(root.right, limit - root.val);
        //3. find the leaf
        boolean isLeaf = root.left == null && root.right == null;

        if (!isLeaf) {
            //5. if left child is in the deleted list, make it null
            if (toBeDeleted.contains(root.left)) {
                toBeDeleted.remove(root.left);
                root.left = null;
            }
            //6. if right child is in the deleted list, make it null
            if (toBeDeleted.contains(root.right)) {
                toBeDeleted.remove(root.right);
                root.right = null;
            }
            //7. if both child are null for the parent, make it in the delete list
            if (root.left == null && root.right == null)
                toBeDeleted.add(root);
        }
        //4. if it is leaf, check the limit
        // if root value is smaller than limit, add it to be deleted
        else if (root.val < limit)
            toBeDeleted.add(root);

    }
