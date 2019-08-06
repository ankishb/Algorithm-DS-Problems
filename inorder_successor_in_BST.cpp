/* The below function should return the node which is 
inorder successor of given node x. */
void find_successor(Node* root, int data, vector<int> &ans, bool found, bool break_){
    if(break_) return ;
    if(root==NULL) return ;
    
    find_successor(root->left, data, ans, found, break_);
    if(!found && root->data > data){
        cout<<root->data<<endl;
        ans.push_back(root->data);
        found = true;
        break_ = true;
    }
    if(break_) return ;
    find_successor(root->right, data, ans, found, break_);
    
    if(!found && root->data > data){
        cout<<root->data<<endl;
        ans.push_back(root->data);
        found = true;
        break_ = true;
    }
}
Node * inOrderSuccessor(Node *root, Node *x)
{
    vector<int> ans;
    bool found = false;
    find_successor(root, x->data, ans, found, false);
    if(found){
        Node* temp = (Node *)malloc(sizeof(Node));
        temp->left = temp->right = NULL;
        temp->data = ans[0];
        return temp;
    }
    return NULL;
}