#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void perform_operation(Node* root){
    inorder(root);
    cout<<endl;
}

void insert(Node ** tree, int val){
    Node *temp = NULL;
    if(!(*tree))
    {
        *tree = new Node(val);
        return;
    }
    if(val < (*tree)->data)
    { insert(&(*tree)->left, val);}
    else if(val > (*tree)->data)
    { insert(&(*tree)->right, val);}
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        Node *root;
        Node *tmp;
        root = NULL;
        int N;
        cin>>N;

        for(int i=0;i<N;i++){
            int k;
            cin>>k;
            insert(&root, k);}
        
        perform_operation(root);
    }
}