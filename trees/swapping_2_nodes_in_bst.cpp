
// Approach:
// 1. Use Inorder transversal
// 2. We find the node, where its value is not in increasing order
// 3. Now swap those 2 nodes

void swap( int* a, int* b ) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
bool custom_sort(const TreeNode* r1, const TreeNode* r2){
    return r1->val < r2->val;
}
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> store;
        trans(root, store);
        vector<TreeNode*> store_c(store);
        sort(store.begin(), store.end(), custom_sort);
        vector<TreeNode*> nodes;
        for(int i=0; i<store.size(); i++){
            if(store[i] != store_c[i]){
                nodes.push_back(store[i]);
            }
        }
        store.clear();
        store_c.clear();
        
        swap(&(nodes[0]->val), &(nodes[1]->val));
        // swap(nodes[0], nodes[1]);
    }
    
    void trans(TreeNode* root, vector<TreeNode*> &store){
        if(root == NULL) return;
        trans(root->left, store);
        store.push_back(root);
        trans(root->right, store);
    }
};





/*
There can be 2 cases:
    1. When both nodes are adjacent to each other
    2. When there are some other nodes between them
Approach
1. Use Inorder Tranversal
2. Track if the cur_node value is less than prev node, then it violate the rule
3. Create 4 nodes, [first, middle, last, prev]. 
    prev will helps in track wrong guy. 
    [first and middle] will track the first wrong node or adjacent node (case:1 or case:2)
    [last] will track last node (case: 1)
*/

class Solution {
public:
    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void collect_wrong_nodes(TreeNode* root, TreeNode**prev, TreeNode** first, TreeNode** middle, TreeNode** last){
        if(root == NULL) return;
        collect_wrong_nodes(root->left, prev, first, middle, last);
        if(*prev!=NULL && (root->val < (*prev)->val)){
            if(*first == NULL){
                *first = *prev;
                *middle = root;
            }
            else{
                *last = root;
            }
        }
        *prev = root;
        collect_wrong_nodes(root->right, prev, first, middle, last);
    }

    void recoverTree(TreeNode* root) {
        TreeNode *prev, *first, *middle, *last;
        prev = first = middle = last = NULL;   
        collect_wrong_nodes(root, &prev, &first, &middle, &last);
        // second case
        if(first!=NULL && last!=NULL){
            swap(&(first->val), &(last->val));
        }
        else{
            swap(&(first->val), &(middle->val));
        }
    }  
};