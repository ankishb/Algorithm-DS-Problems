
int sum_tree(Node* root, int data){
	if(root == NULL) return 0;
	if(root->left == NULL && root->right == NULL){
		data = root->data;
		root->data = 0;
		return data;
	}
	int l_data = sum_tree(root->left, data);
	int r_data = sum_tree(root->right, data);
	data = root->data + l_data + r_data;
	root->data = l_data + r_data;
	return data;
}

void toSumTree(Node* node){
    int data = 0;
    sum_tree(node, data);
}