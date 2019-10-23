void find_sum(Node* root, int &sum){
    if(root == NULL) return;
    sum += root->data;
    find_sum(root->left, sum);
    find_sum(root->right, sum);
}

// using inorder (time: O(2N) one for calc sum)
void update_tree(Node* &root, int &sum){
    if(root == NULL) return ;
    update_tree(root->left, sum);
    sum -= root->data;
    root->data += sum;
    update_tree(root->right, sum);
}

// using postorder (time: O(N))
void update_tree2(Node* &root, int &sum){
    if(root == NULL) return ;
    update_tree(root->right, sum);
    sum += root->data;
    root->data = sum;
    update_tree(root->left, sum);
}
void modify(Node **root){
    int sum = 0;
    find_sum(*root, sum);
    update_tree(*root, sum);
}