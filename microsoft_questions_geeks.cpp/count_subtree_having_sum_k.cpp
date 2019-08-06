/*
Approach:
1. Use Postorder transversal
2. Check if current node/subtree has sum equal to given sum, then increase count.
*/

int count_subtree(Node* root, int &count, int sum){
	if(root == NULL) return 0;
	int l_sum = count_subtree(root->left, count, sum);
	int r_sum = count_subtree(root->right,count, sum);
	int cur_sum = l_sum + r_sum + root->data;
	if(cur_sum == sum) count++;
	return cur_sum;
}

int countSubtreesWithSumX(Node* root, int x){
	if (!root)return 0;
	int count = 0;
	int temp = count_subtree(root, count, x);
    return count;
}


