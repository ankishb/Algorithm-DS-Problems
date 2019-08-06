
int find_max_sum(Node* root, int &max_sum){
	if(root == NULL) return 0;
	int l_sum = find_max_sum(root->left, max_sum);
	int r_sum = find_max_sum(root->right, max_sum);

	max_sum = max(max_sum, root->data + l_sum + r_sum);
	return root->data + max(l_sum, r_sum);
}

int maxPathSum(Node* root){
	int max_sum = INT_MIN;
	find_max_sum(root, max_sum);
	return max_sum;
}
