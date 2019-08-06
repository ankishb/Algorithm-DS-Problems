/*
Approach:
1. First find the node in BST
2. Now use inorder transversal, to check if it is subtree.
Note that: T is subtree of tree S, if leaves of T is also leaves of S. It means that, leaves of both tree(subtree part) have same nature.
*/

bool inorder_trans(Node* root1, Node* root2){
	if(root1 == NULL && root2 == NULL) return true;
	if(root1 == NULL || root2 == NULL) return false;
	if(root1->data != root2->data) return false;
	
	bool l_tree = inorder_trans(root1->left, root2->left);
	bool r_tree = inorder_trans(root1->right, root2->right);
	return (l_tree && r_tree);
}

bool check_subtree(Node* root1, Node* root2){
	if(root1 == NULL) return false;
	if(root1->data == root2->data){
		return inorder_trans(root1, root2);
	}
	bool l_tree = check_subtree(root1->left, root2);
	bool r_tree = check_subtree(root1->right, root2);
	return (l_tree || r_tree);
} 

bool isSubtree(Node* root1, Node* root2) {
	if(root1 == NULL) return true;
    return check_subtree(root1, root2);
}