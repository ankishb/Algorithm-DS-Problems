
1. https://practice.geeksforgeeks.org/problems/sum-of-binary-tree/1
int sum_of_nodes(Node* root){
    if(root == NULL) return 0;
    int left = sum_of_nodes(root->left);
    int right = sum_of_nodes(root->right);
    return (left+right+root->key);
}

long int sumBT(Node* root)
{
    return sum_of_nodes(root);
}





2. https://practice.geeksforgeeks.org/problems/sum-tree/1/?ref=self

int check(Node* root, bool *flag){
    if(*flag == false) return 0;
    if(root == NULL) return 0;
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    
    int left = check(root->left, flag);
    int right = check(root->right, flag);
    if(left + right != root->data){
        *flag = false;
    }
    return left+right+root->data;
}


bool isSumTree(Node* root)
{
    if(root == NULL) return true;
    bool  flag = true;
    int sum  = check(root, &flag);
    return flag;
}