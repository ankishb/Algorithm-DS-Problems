
// 1
// 6
// 4 2 L 4 5 R 2 7 L 2 2 R 5 2 L 5 3 R

/*
Naive approach: Worst: O(N^2) Avg: O(N logN)
Check the condition if self balancing tree on each node, there are many overlapping steps.

Optimized approach: Worst: O(N)
- transverse tree in (bottom up approach) and track its height
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int get_height(TreeNode* root){
        if(root == NULL) return 0;

        int left_h = get_height(root->left);
        int right_h = get_height(root->right);

        return max(left_h, right_h) + 1;
    }

    bool naive_approach(TreeNode* root){
        if(root == NULL) return true;
        
        int left_h = get_height(root->left);
        int right_h = get_height(root->right);

        return (abs(left_h - right_h) <= 0 && naive_approach(root->left) && naive_approach(root->right));
    }

    int optimized_approach(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left_h = optimized_approach(root->left);
        if(left_h == -1) return -1;

        int right_h = optimized_approach(root->right);
        if(right_h == -1) return -1;
        
        // if(left_h == -1 || right_h == -1) return -1;
        if(abs(left_h - right_h) > 1) return -1;
        
        return max(left_h, right_h) + 1;
    }

    bool isBalanced(TreeNode* root) {
        // return naive_approach(root);
        return optimized_approach(root) != -1 ;
    }
};





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

bool naive_check_balanced(Node* root)


void perform_operation(Node* root){
    cout<< naive_check_balanced(root)<<endl;;
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





/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void preorder(TreeNode* root, int depth, int &min_depth){
        if(root == NULL) return ;
        if(root->left==NULL && root->right==NULL){
            min_depth = min(min_depth, depth);
        }
        preorder(root->left, depth+1, min_depth);
        preorder(root->right, depth+1, min_depth);
    }

    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int min_depth = INT_MAX;
        preorder(root, 1, min_depth);
        return min_depth;
    }
};
