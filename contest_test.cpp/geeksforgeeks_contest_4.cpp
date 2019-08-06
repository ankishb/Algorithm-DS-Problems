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

void inorder(Node* root, vector<int> &leafs){
    if(root == NULL) return;
    if(root->left==NULL && root->right==NULL){
        leafs.push_back(root->data);
    }
    inorder(root->left, leafs);
    // cout<<root->data<<" ";
    inorder(root->right, leafs);
}

void perform_operation(Node* root){
    vector<int> leafs;
    inorder(root, leafs);

    int ans = 0;
    int n = leafs.size();
    for(int i=0; i<n; i++){
        if(i%2 == 0){
            ans += leafs[i];
        }
    }
    cout<<ans<<endl;
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










#include <bits/stdc++.h>
using namespace std;

void jump_and_move(vector<int> A){
    int n = A.size();
    vector<int> ans;
    for(int i=0; i<n-2; i++){
        if(A[i]==A[i+1] && A[i+2]==100){
            A[i] = 100;
            A[i+1] = A[i+1] + floor(A[i+1]*(10/100.0));
        }
    }
    // for(auto itr : A) cout<<itr<<" ";
    // cout<<endl;
    
    bool first = false;
    int count_100 = 0;
    
    for(int i=1; i<n; i++){
        if(A[i] == 100) count_100++;
        else{
            if(!first) cout<<A[i];
            else cout<<"-> "<<A[i];
            first = true;
        }
    }
    for(int i=0; i<count_100; i++){
        cout<<"->"<<100;
    }
    cout<<endl;
}

int main()
{
    int test;
    cin>>test;
    while(test--){
        int n; cin>>n;
        vector<int> A(n, 0);
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        jump_and_move(A);
    }
    return 0;
}






https://practice.geeksforgeeks.org/contest-problem/sum-the-alternate-leaf-nodes4934/0/

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

void inorder(Node* root, vector<int> &leafs){
    if(root == NULL) return;
    if(root->left==NULL && root->right==NULL){
        leafs.push_back(root->data);
    }
    inorder(root->left, leafs);
    // cout<<root->data<<" ";
    inorder(root->right, leafs);
}

void perform_operation(Node* root){
    vector<int> leafs;
    inorder(root, leafs);

    int ans = 0;
    int n = leafs.size();
    for(int i=0; i<n; i++){
        if(i%2 == 0){
            ans += leafs[i];
        }
    }
    cout<<ans<<endl;
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




