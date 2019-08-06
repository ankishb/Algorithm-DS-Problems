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

bool search_BST(Node* root, int q){
    if(root == NULL) return false;
    if(root->data < q && root->right != NULL){
        search_BST(root->right, q);
    }
    else if(root->data > q && root->left != NULL){
        search_BST(root->left, q);
    }
    else if(root->data == q){
        return true;
    }
    else{
        return false;
    }
}

void preorder(Node* root, int q, bool &break_flag){
    if(break_flag) return;
    if(root == NULL) return;
    if(root->data == q){
        break_flag = true;
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left, q, break_flag);
    preorder(root->right, q, break_flag);

}

void perform_operation(Node* root, vector<int> q){
    for(int i=0; i<q.size(); i++){
        if(root == NULL) cout<<"Empty";
        else if(root->data == q[i]) cout<<"Empty";
        else{
            if(!search_BST(root, q[i])) cout<<"Empty";
            else{
                bool break_flag = false;
                preorder(root, q[i], break_flag);
            }
        }
        cout<<endl;
    }
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
        int N, Q;
        cin>>N>>Q;
        vector<int> queries(Q, 0);
        
        for(int i=0;i<N;i++){
            int k;
            cin>>k;
            insert(&root, k);
        }
        for(int i=0; i<Q; i++){
            cin>>queries[i];
        }
        
        perform_operation(root, queries);
    }
}