// C++ program to find sum of 
// all paths from root to leaves  
#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;


class node  
{  
    public: 
    int data;  
    node *left, *right;  
};  
  
// function to allocate new node with given data  
node* newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = Node->right = NULL;  
    return (Node);  
}  

void reversePrint(node *root)
{
    vector<int> ans;
    queue<node*> q;
    
    if(root!=NULL){
        q.push(root);
    }
    while(!q.empty()){
        node* top = q.front();
        q.pop();
        ans.push_back(top->data);
        
        if(top->right != NULL){
            q.push(top->right);
        }
        if(top->left != NULL){
            q.push(top->left);
        }
    }
    
    for(int i=ans.size()-1; i>=0; i--){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main()  
{  
    node *root = newNode(6);  
    root->left = newNode(3);  
    root->right = newNode(5);  
    root->left->left = newNode(2);  
    root->left->right = newNode(5);  
    root->right->right = newNode(4);  
    root->left->right->left = newNode(7);  
    root->left->right->right = newNode(4);  
    cout<<"Reverse Level Tranversal : \n";
    reversePrint(root);  
    return 0;  
}  