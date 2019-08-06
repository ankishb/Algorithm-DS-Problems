
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node has data, pointer to left child
    and a pointer to right child  
struct Node {
    int data;
    Node* left, * right;
}; */
void inorder_trans(Node* root, vector<int> &ans){
    if(root==NULL){
        return;
    }
    inorder_trans(root->left, ans);
    ans.push_back(root->data);
    inorder_trans(root->right, ans);
}

bool isBST(Node* root) {
    vector<int> ans;
    inorder_trans(root, ans);
    for(int i=1; i<ans.size(); i++){
        if(ans[i] < ans[i-1]){
            return false;
        }
    }
    return true;
}



#include<climits>
// left_r == left_range && right_r == right_range
bool isBST(Node* root, int left_r, int right_r){
    if(root == NULL){
      return true;
    }
    // check if root doesn't satisfy BST
    if((root->data <= left_r) || (root->data >= right_r)){
        return false;
    }
    return (isBST(root->left, left_r, root->data) &&
            isBST(root->right, root->data, right_r));
}
bool checkBST(Node* root){
    return isBST(root, INT_MIN, INT_MAX);
}











// easiest, but memory expensive
void inorder(Node* root, vector<int> &ans){
    if(root == NULL){
        return ;
    }
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
bool checkBST(Node* root){
    vector<int> ans;
    inorder(root, ans);
    for(int i=1; i<ans.size(); i++){
        if(ans[i] < ans[i-1]){
            return false;
        }
    }
    return true;
}


// another way, but little bit more better, as it remove previous element from vector
bool inorder_tranversal(Node* root, vector<int> &ans, bool break_flag){
    // if break_flag is set, then return false
    if(break_flag){ return false; }
    if(root == NULL){ return true; }
    bool left_check = inorder_tranversal(root->left, ans, break_flag);
    if(ans.size()>=1){
        if(ans[ans.size()-1] > root->data){
            break_flag = true;
            return false;
        }
    }
    ans.push_back(root->data);
    bool right_check = inorder_tranversal(root->right, ans, break_flag);
    
    return (left_check && right_check);
}
bool checkBST(Node* root){
    vector<int> ans;
    bool break_flag = false;
    return inorder_tranversal(root, ans, break_flag);
}



  // bool checkBST(Node* root) {
  //  if(root == NULL){
  // return true;
  // }
  // // if both childs are NULL
  // if((root->left == NULL) || 
  // (root->right == NULL)){
  // return true;
  // }
  // // check if right child is present
  // if(root->left == NULL){
  // return (root->data < root->right->data);
  // }
  // // check if left child is present
  // if(root->right == NULL){
  // return (root->data > root->left->data);
  // }
  // // check if both present
  // if((root->data < root->left->data) || 
  // (root->data > root->right->data)){
  // return false;
  // }
  // return (checkBST(root->left) && checkBST(root->right));
  // }