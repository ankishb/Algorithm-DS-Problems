// Print all the boundary nodes, in counterclockwise direction.

// Approach:
// 1. Print left view of tree from top to bottom
// 2. Print all leaf nodes from left to right
// 3. print right view of tree from bottom to top


// Input:
// 3
// 7
// 20 8 L 20 22 R 8 4 L 8 12 R 22 25 R 12 10 L 12 14 R 
// 3
// 1 2 R 2 3 L 2 4 R
// 9
// 1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 5 7 L 5 8 R 6 9 L 6 10 R

// Output:
// 20 8 4 10 14 25 22 20
// 1 3 4 2
// 1 2 4 7 8 9 10 6 3

/*
Input:
  1
   \
    2
   / \
  3   4

Ouput:
[1, 3, 4, 2]


Input:
    ____1_____
   /          \
  2            3
 / \          / 
4   5        6   
   / \      / \
  7   8    9  10  
       
Ouput:
[1,2,4,7,8,9,10,6,3]
*/

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

bool isLeaf(Node* root){
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    return false;
}
void print_left_view(Node* root){
    if(root == NULL) return ;
    cout<<root->data<<" ";
    root = root->left;
    while(root != NULL){
        if(!isLeaf(root)){
            cout<<root->data<<" ";
        }
        if(root->left != NULL){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
}

void print_right_view(Node* root){
    root = root->right;
    if(root == NULL) return ;
    stack<int> s;
    while(root != NULL){
        if(!isLeaf(root)){
            s.push(root->data);
        }
        if(root->right != NULL){
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
    }
}

void print_leafs_node(Node* root){
    if(root == NULL) return ;
    if(isLeaf(root)){
        cout<<root->data<<" ";
    }
    else{
        if(root->left != NULL){
            print_leafs_node(root->left);
        }
        if(root->right != NULL){
            print_left_view(root->right);
        }
    }
}


void perform_operation(Node* root){
    cout<<"left: "; print_left_view(root);
    cout<<"leaf: "; print_leafs_node(root);
    cout<<"right: "; print_right_view(root);
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





















// Definition for a binary tree node.
// public class TreeNode {
//     int val;
//     TreeNode left;
//     TreeNode right;
//     TreeNode(int x) { val = x; }
// }
 
public class Solution {

    public boolean isLeaf(TreeNode t) {
        return t.left == null && t.right == null;
    }

    public void addLeaves(List<Integer> res, TreeNode root) {
        if (isLeaf(root)) {
            res.add(root.val);
        } 
        else {
            if (root.left != null) {
                addLeaves(res, root.left);
            }
            if (root.right != null) {
                addLeaves(res, root.right);
            }
        }
    }

    public List<Integer> boundaryOfBinaryTree(TreeNode root) {
        ArrayList<Integer> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        if (!isLeaf(root)) {
            res.add(root.val);
        }
        TreeNode t = root.left;
        while (t != null) {
            if (!isLeaf(t)) {
                res.add(t.val);
            }
            if (t.left != null) {
                t = t.left;
            } else {
                t = t.right;
            }

        }
        addLeaves(res, root);
        Stack<Integer> s = new Stack<>();
        t = root.right;
        while (t != null) {
            if (!isLeaf(t)) {
                s.push(t.val);
            }
            if (t.right != null) {
                t = t.right;
            } else {
                t = t.left;
            }
        }
        while (!s.empty()) {
            res.add(s.pop());
        }
        return res;
    }
}