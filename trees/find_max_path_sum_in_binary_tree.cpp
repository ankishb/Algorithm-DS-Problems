
// Given a binary tree, find the maximum path sum. The path may start and end at any node in the tree.
// 1
// 7
// 10 2 L 10 10 R 2 20 L 2 1 R 10 -25 R -25 3 L -25 4 R
// 12
// -15 5 L -15 6 R 5 -8 L 5 1 R -8 2 L -8 6 R 6 3 L 6 9 R 9 0 R 0 4 L 0 -1 R -1 10 L
// Out:
// 20+2+10+10=42
// 27

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

int collect_max_path_sum(Node* root, int cur_max, int global_max){
    if(root == NULL) return 0;

    int left_Sum = collect_max_path_sum(root->left, cur_max, global_max);
    int right_Sum = collect_max_path_sum(root->right, cur_max, global_max);
    
    if(root->left!=NULL && root->right!=NULL){
        cur_max = root->data + left_Sum + right_Sum;
        global_max = max(global_max, cur_max);
        return max(left_Sum, right_Sum) + root->data;
    }
    else if(root->left != NULL){
        return left_Sum + root->data;
    }
    else{
        return right_Sum + root->data;
    }
}

void perform_operation(Node* root){
    cout<<collect_max_path_sum(root, 0, INT_MIN)<<endl;
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





