
// 1
// 6
// 4 2 L 4 5 R 2 7 L 2 2 R 5 2 L 5 3 R

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

void print_path(vector<int> vect){
    for(auto itr:vect){
        cout<<itr<<" ";
    }
    cout<<endl;
}

void find_longest_path(Node* root, vector<int> &path, vector<int> &ans, int &cur_sum, int &max_sum){
    if(root == NULL) return; 
    // if current node is leaf node, this represent a path
    path.push_back(root->data);
    cur_sum += root->data;
    if(root->left==NULL && root->right==NULL){
        // cout<<path<<" : "<<ans;
        if(path.size() >= ans.size() && cur_sum > max_sum){
            max_sum = cur_sum;
            ans.clear();
            ans = path;
        }
        // if you will use return here, make sure to use pop_back last element from vector too.
        // path.pop_back();
        // return;
    }
    find_longest_path(root->left, path, ans, cur_sum, max_sum);
    find_longest_path(root->right, path, ans, cur_sum, max_sum);
    path.pop_back();
    cur_sum -= root->data;
}

int perform_operation(Node* root){
    // do any operation here
    vector<int> path;
    vector<int> ans;
    int cur_sum = 0;
    int max_sum = 0;
    find_longest_path(root, path, ans, cur_sum, max_sum);
    // cout<<"final ans: "<<ans<<endl;
    int sum = 0;
    for(auto itr:ans){
        sum += itr;
    }
    cout<<sum<<endl;
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








// find maximum sum path from toot to leaf node
void find_longest_path(Node* root, int &path, int &ans){
    if(root == NULL) return; 
    // if current node is leaf node, this represent a path
    path += root->data;
    if(root->left==NULL && root->right==NULL){
        // cout<<path<<" : "<<ans;
        if(path >= ans){
            ans = path;
        }
    }
    find_longest_path(root->left, path, ans);
    find_longest_path(root->right, path, ans);
    path -= root->data;
}

int sumOfLongRootToLeafPath(Node* root){
    // do any operation here
    int path = 0;
    int ans = 0;
    find_longest_path(root, path, ans);
    // cout<<"final ans: "<<ans<<endl;
    return ans;
}