// new try
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool is_leaf(TreeNode* root){
    return (root->left == NULL && root->right == NULL);
} 

bool helper(TreeNode* root, int k, int cur_sum){
    if(root == NULL) return false;
    cur_sum += root->val;
    if(is_leaf(root) && cur_sum == k) return true;
    
    bool left = helper(root->left, k, cur_sum);
    bool right = helper(root->right, k, cur_sum);
    // cur_sum -= root->val; 
    // don't need above step, as cur_sum is not memory refrenced
    return left||right;
} 

int Solution::hasPathSum(TreeNode* root, int k) {
    return helper(root, k, 0);
}






// solution with space of max_path length
void check_path_sum(TreeNode *root, int k, vector<int> &temp, bool &result){
   if(result == true){
       return ;
   }
   if(root==NULL){
        return ;
    }
    temp.push_back(root->val);
    if(root->left==NULL && root->right==NULL){
        int sum = 0;
        for(int i=0; i<temp.size(); i++){
            sum += temp[i];
        }
        if(sum == k){
            result = true;
        }
    }
    check_path_sum(root->left, k, temp, result);
    check_path_sum(root->right, k, temp, result);
    temp.pop_back();
}
int Solution::hasPathSum(TreeNode* A, int B) {
    vector<int> ans;
    bool result = false;
    check_path_sum(A, B, ans, result);
    return result;
}


// easy solution without space 
void check_path_sum(TreeNode *root, int sum, bool &ans, int path_sum){
   if(ans == true){
       return ;
   }
   if(root==NULL){
        return ;
    }
    path_sum += root->val;
    if(root->left==NULL && root->right==NULL){
        if(path_sum == sum){
            ans = true;
        }
    }
    check_path_sum(root->left, sum, ans, path_sum);
    check_path_sum(root->right, sum, ans, path_sum);
    path_sum -= root->val;
}

int Solution::hasPathSum(TreeNode* A, int B) {
    bool ans = false;
    int path_sum = 0;
    check_path_sum(A, B, ans, path_sum);
    return ans;
}







// geeksforgeeks
{
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* Function to get diameter of a binary tree */
long long treePathsSum(Node *root);
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
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
     cout << treePathsSum(root) << endl;
  }
  return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/*You are required to complete below method */
typedef long long ll;

ll make_seq(vector<ll> vect){
    ll result = 0;
    int n = vect.size();
    int count = 0;
    for(int i=n-1; i>=0; i--){
        result += pow(10, count)*vect[i];
        count++;
    }
    return result;
}

void preorder_trans(Node* root, vector<ll> &ans, vector<ll> temp){
    if(root == NULL){
        return ;
    }
    temp.push_back(root->data);
    // check if it reach at leaf node, 
    // then compute the path's ans 10^0 x1 + 10^1 x2 + ..
    if(root->left==NULL && root->right==NULL){
        ll result = make_seq(temp);
        ans.push_back(result);
    }
    preorder_trans(root->left, ans, temp);
    preorder_trans(root->right, ans, temp);
    temp.pop_back();
}

long long treePathsSum(Node *root)
{
    vector<ll> ans;
    vector<ll> temp;
    preorder_trans(root, ans, temp);
    
    ll sum = 0;
    for(int i=0; i<ans.size(); i++){
        sum += ans[i];
    }
    return sum;
}




// easy geeks
 
int treePathsSumUtil(node *root, int val)  {  
    if (root == NULL) return 0;  

    val = (val*10 + root->data);  
    if (root->left==NULL && root->right==NULL)  
        return val;  
  
    return treePathsSumUtil(root->left, val) +  
        treePathsSumUtil(root->right, val);  
}  
  
int treePathsSum(node *root)  {  
    return treePathsSumUtil(root, 0);  
}












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
 void check_path_sum(node *root, int k, vector<int> &temp, bool &result, int path_sum){
   if(result == true){
       return ;
   }
   if(root==NULL){
        return ;
    }
    path_sum += root->data;
    // temp.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
        int sum = path_sum;
        // for(int i=0; i<temp.size(); i++){
        //     sum += temp[i];
        // }
        if(sum == k){
            result = true;
        }
    }
    check_path_sum(root->left, k, temp, result, path_sum);
    check_path_sum(root->right, k, temp, result, path_sum);
    // temp.pop_back();
    path_sum -= root->data;
}
int hasPathSum(node* A, int B) {
    vector<int> ans;
    bool result = false;
    int path_sum = 0
    check_path_sum(A, B, ans, result, path_sum);
    return result;
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
    cout<<"Is there path : "<<hasPathSum(root, 15);  
    return 0;  
}  