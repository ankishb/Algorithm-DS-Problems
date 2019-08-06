#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
    void inorder(Node* root){
        if(root==NULL){
            return ;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void topView(Node * root) {
        cout<<"\n Inorder trans\n";
        inorder(root);
        cout<<endl;
        Node* temp = root;
        stack<int> s;
        while (temp != NULL) {
          s.push(temp->data);
          temp = temp->left;
        }
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }

        root = root->right;
        while (root != NULL) {
            cout<<root->data<<" ";
            root = root->right;
        }        
    }

}; //End of Solution