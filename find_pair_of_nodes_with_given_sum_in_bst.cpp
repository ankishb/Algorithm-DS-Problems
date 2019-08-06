/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Note: In worst case: T(n) = O(n) && S(n) = O(n)
bool check_sum(TreeNode* root, int sum, unordered_map<int, int> &my_map){
    if(root == NULL){
        return false;
    }
    
    if(my_map.find(root->val) != my_map.end()){
        return true;
    }
    int cur_diff = sum - root->val;
    my_map[cur_diff] = root->val;
    bool l_ans = check_sum(root->left, sum, my_map);
    bool r_ans = check_sum(root->right, sum, my_map);
    
    return (l_ans||r_ans);
}
int Solution::t2Sum(TreeNode* A, int B) {
    unordered_map<int, int> my_map;
    // Use preorder_tranversal to find element in linear time,
    // but also linear space :(
    return (check_sum(A, B, my_map))? 1 : 0;
}







//
int Solution::t2Sum(TreeNode* A, int B)
{

if(A == NULL || B < 0)   
   return 0;

stack<TreeNode*> st1, st2;

TreeNode *i, *j;
i = j = A;
int f = -1; //flag

while(i != NULL || j != NULL)
{
    while(i != NULL && f != 1)
    {
        st1.push(i);
        i=i->left;
    }
    
    while(j != NULL && f != 0)
    {
        st2.push(j);
        j =j->right;
    }
    
    i = st1.top();
    j = st2.top();
    
    if(i->val == j->val)
        break;
    
    if(i->val + j->val == B)    
        return 1;
    
    else if (i->val + j->val < B)
    {
        st1.pop();
        f=0;
        i = i->right;
    }
    else
    {
        st2.pop();
        f=1;
        j = j->left;
    }
}   
return 0;

}