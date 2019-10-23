
bool search_bst(Node* root, int k, int &left, int &right){
    if(root == NULL) return false;
    if(root->data > k){
        right = root->data;
        return search_bst(root->left, k, left, right);
    }
    else if(root->data < k){
        left = root->data;
        return search_bst(root->right, k, left, right);
    }
    else return true;
    
}

int maxDiff(Node *root, int k){
    int left = INT_MIN;
    int right= INT_MAX;
    if(search_bst(root, k, left, right)) return 0;
    
    return min(abs(left-k), abs(right-k));
}
