
// fresh try
unordered_set<int> uni;
void right_view(Node* root, int level){
    if(root == NULL) return ;
    if(uni.count(level) == 0) cout<<root->data<<" ";
    uni.insert(level);
    right_view(root->right, level+1);
    right_view(root->left, level+1);
}

unordered_set<int> uni;
void left_view(Node* root, int level){
    if(root == NULL) return ;
    if(uni.count(level) == 0) cout<<root->data<<" ";
    uni.insert(level);
    left_view(root->left, level+1);
    left_view(root->right, level+1);
}

void rightView(Node *root){
   uni.clear();
   left_view(root, 0);
   uni.clear();
   right_view(root, 0);
}




// new try
// left view of tree (not a good one, can fail)
void collect_left(TreeNode* root, vector<int> &ans){
    if(root == NULL) return ;
    ans.push_back(root->val);
    if(root->left) collect_left(root->left, ans);
    else if(root->right) collect_left(root->right, ans);
}

vector<int> Solution::solve(TreeNode* root) {
    vector<int> ans;
    collect_left(root, ans);
    return ans;
}




#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
// A wrapper over leftViewUtil()
void leftView(struct Node *root);
void rightView(struct Node *root);
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d ", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     leftView(root);
     cout << endl;
  }
  return 0;
}



void leftView(Node* root){
    queue<Node*> ans;
    queue<Node*> s;
    s.push(root);
    s.push(NULL);
    while(!s.empty()){
        if(s.size()==1 && s.front()==NULL){
            break;
        }
        Node* top = s.front();
        s.pop();
        
        ans.push(top);
        if(top == NULL){
            s.push(NULL);
        }
        else{
            if(top->left != NULL){
                s.push(top->left);
            }
            if(top->right != NULL){
                s.push(top->right);
            }
        }
    }

    cout<<"leftView of tree\n";
    cout<<(ans.front())->data<<" ";
    ans.pop();
    while(!ans.empty()){
        if(ans.size()>=2 && ans.front()==NULL){
            ans.pop();
            cout<<(ans.front())->data<<" ";
            ans.pop();
        }
        else{
            ans.pop();
        }
    }
}

void rightView(Node* root){
    queue<Node*> ans;
    queue<Node*> s;
    s.push(root);
    s.push(NULL);
    while(!s.empty()){
        if(s.size()==1 && s.front()==NULL){
            break;
        }
        Node* top = s.front();
        s.pop();
        
        ans.push(top);
        if(top == NULL){
            s.push(NULL);
        }
        else{
            if(top->right != NULL){
                s.push(top->right);
            }
            if(top->left != NULL){
                s.push(top->left);
            }
        }
    }

    cout<<"RightView of tree\n";
    cout<<ans.front()->data<<" ";
    ans.pop();
    while(!ans.empty()){
        if(ans.size()>2 && ans.front()==NULL){
            ans.pop();
            cout<<ans.front()<<" ";
            ans.pop();
        }
        else{
            ans.pop();
        }
    }
}





// recursive solution

// Recursive function to print right view of a binary tree. 
void rightViewUtil(struct Node *root, int level, int *max_level) 
{ 
    // Base Case 
    if (root==NULL)  return; 
  
    // If this is the last Node of its level 
    if (*max_level < level) 
    { 
        printf("%d\t", root->data); 
        *max_level = level; 
    } 
  
    // Recur for right subtree first, then left subtree 
    rightViewUtil(root->right, level+1, max_level); 
    rightViewUtil(root->left, level+1, max_level); 
} 
  
// A wrapper over rightViewUtil() 
void rightView(struct Node *root) 
{ 
    int max_level = 0; 
    rightViewUtil(root, 1, &max_level); 
} 

// Recursive function to print left view of a binary tree.  
void leftViewUtil(node *root, int level, int *max_level)  
{  
    // Base Case  
    if (root==NULL) return;  
  
    // If this is the first node of its level  
    if (*max_level < level)  
    {  
        cout<<root->data<<"\t";  
        *max_level = level;  
    }  
  
    // Recur for left and right subtrees  
    leftViewUtil(root->left, level+1, max_level);  
    leftViewUtil(root->right, level+1, max_level);  
}  
  
// A wrapper over leftViewUtil()  
void leftView(node *root)  
{  
    int max_level = 0;  
    leftViewUtil(root, 1, &max_level);  
}  