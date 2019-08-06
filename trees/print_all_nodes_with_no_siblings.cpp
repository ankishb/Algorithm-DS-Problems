// Given a Binary Tree, print all nodes that don’t have a sibling (a sibling is a node that has same parent. In a Binary Tree, there can be at most one sibling). Root should not be printed as root cannot have a sibling.
// 1
// 5
// 1 2 L 1 3 R 2 4 R 3 5 L 5 6 L
// Out:
// Nodes with no siblings:
// 4 5 6

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

void print_nodes_with_no_siblings(Node* root){
    if(root == NULL) return ;
    if(root->left==NULL && root->right!=NULL){
        cout<<root->right->data<<" ";
    }
    if(root->left!=NULL && root->right==NULL){
        cout<<root->left->data<<" ";
    }
    print_nodes_with_no_siblings(root->left);
    print_nodes_with_no_siblings(root->right);
}

void perform_operation(Node* root){
    trans(root); cout<<endl;
    print_nodes_with_no_siblings(root);
    cout<<endl; trans(root); cout<<endl;
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





