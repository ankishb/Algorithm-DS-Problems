/* Should convert tree to its mirror */
void mirror(Node* root) 
{
    if(root == NULL) return;
    mirror(root->left);
    mirror(root->right);
    
    // switch their connection
    swap(root->left, root->right);
}