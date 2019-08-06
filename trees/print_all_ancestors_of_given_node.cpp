
// 2
// 2
// 1 2 L 1 3 R
// 2
// 5
// 1 2 R 1 3 L 2 4 L 2 5 R 4 7 L
// 7
// Out:
// 1
// 4 2 1

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

void trans(Node* root, vector<int> &vect, int x, bool &found, bool &break_){
    if(found == true || break_==true) return;
    if(root == NULL) return;
    cout<<root->data<<" ";
    vect.push_back(root->data);
    if(root->data == x){
        break_ = true;
        found = true;
        return;
    }
    trans(root->left, vect, x, found, break_);
    trans(root->right, vect, x, found, break_);
    vect.pop_back();
}
// Function should print all the ancestor of the target node
void perform_operation(struct Node *root){
    int target;
    cin>>target;
    bool found = false;
    bool break_ = false;
    vector<int> ancestors;
    trans(root, ancestors, target, found, break_);
    for(auto itr:ancestors) cout<<itr<<" : ";
    int n = ancestors.size();
    for(int i=n-2; i>=0; i--){
        cout<<ancestors[i]<<" ";
    }
    cout<<endl;
    
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





