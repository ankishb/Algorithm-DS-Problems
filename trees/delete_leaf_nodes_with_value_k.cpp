// Given a binary tree and value k. delete all the leaf nodes with value equal to k. If a node becomes leaf after deletion, then it should be deleted if it has value k.

// 1
// 5
// 4 5 L 4 5 R 5 3 L 5 1 R 5 5 L
// 5
// After deleteing leaf nodes 5, it becomes:
// 4 5 L 5 3 L 5 1 R

#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

void trans(Node* root){
    if(root == NULL) return ;
    trans(root->left);
    cout<<root->data<<" ";
    trans(root->right);
}

Node* delete_leaf_node_with_value_k(Node* root, int k){
    if(root == NULL) return NULL;
    
    root->left = delete_leaf_node_with_value_k(root->left, k);
    root->right = delete_leaf_node_with_value_k(root->right, k);
    if(root->left==NULL && root->right==NULL && root->data == k){
        return NULL;
    }
    else{
        return root;
    }
}

// Method:
// 1. Use PostTransversal
// 2. If we find leaf node, check and delete accordingly
void perform_operation(Node* root){
    int k;
    cin>>k;
    trans(root); cout<<endl;
    root = delete_leaf_node_with_value_k(root, k);
    trans(root); cout<<endl;
}



struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        map<int, Node*> m;
        int n;
        scanf("%d ",&n);
        struct Node *root = NULL;
        if(n==1){
            int a;
            cin>>a;
            cout<<a<<endl;
        }
        else{
            while (n--){
                Node *parent;
                char lr;
                int n1, n2;
                scanf("%d %d %c", &n1, &n2, &lr);
                //  cout << n1 << " " << n2 << " " << (char)lr << endl;
                if (m.find(n1) == m.end()){
                    parent = newNode(n1);
                    m[n1] = parent;
                    if (root == NULL)
                        root = parent;
                    }
                else
                    parent = m[n1];
                    child = newNode(n2);
                if (lr == 'L')
                    parent->left = child;
                else
                    parent->right = child;
                    m[n2]  = child;
            }
            perform_operation(root);
        }
    }
    return 0;
}





