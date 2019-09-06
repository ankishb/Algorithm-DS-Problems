// Given the root of a binary tree, each node in the tree has a distinct value. After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees). Return the roots of the trees in the remaining forest.  You may return the result in any order.

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
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        cout<< root->val <<" ";
        inorder(root->right);
    }
	TreeNode* collect_roots(TreeNode* root, int q, vector<TreeNode*> &store){
		if(root == NULL) return NULL;
		if(root->val == q){
            cout<<"found: \n";
			if(root->left != NULL){
				store.push_back(root->left);
				root->left = NULL;
			}
			if(root->right != NULL){
				store.push_back(root->right);
				root->right = NULL;
			}
            return NULL;
		}
		root->left = collect_roots(root->left, q, store);
		root->right = collect_roots(root->right, q, store);
		return root;
	}

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    	int q = to_delete.size();
        vector<TreeNode*> store;
        for(int i=0; i<q; i++){
        	root = collect_roots(root, to_delete[i], store);
            inorder(root);
            cout<<endl;
        }
        store.push_back(root);
        return store;
    }
};// Given the root of a binary tree, each node in the tree has a distinct value. After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees). Return the roots of the trees in the remaining forest.  You may return the result in any order.

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
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        cout<< root->val <<" ";
        inorder(root->right);
    }
    TreeNode* collect_roots(TreeNode* root, int q, vector<TreeNode*> &store){
        if(root == NULL) return NULL;
        if(root->val == q){
            cout<<"found: \n";
            if(root->left != NULL){
                store.push_back(root->left);
                root->left = NULL;
            }
            if(root->right != NULL){
                store.push_back(root->right);
                root->right = NULL;
            }
            return NULL;
        }
        root->left = collect_roots(root->left, q, store);
        root->right = collect_roots(root->right, q, store);
        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        int q = to_delete.size();
        vector<bool> visited(q, 0);
        vector<TreeNode*> store;
        for(int i=0; i<q; i++){
            root = collect_roots(root, to_delete[i], store, visited);
            inorder(root);
            cout<<endl;
        }
        store.push_back(root);
        return store;
    }
};




class Solution {
public:
    string defangIPaddr(string address) {
        string ans = ""
        int n = address.length();
        for(int i=0; i<n; i++){
            if(address[i] == '.'){
                ans += "[.]";
            }
            else{
                ans += address[i];
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // for(auto itr1 : bookings){
        //     for(auto itr2 : itr1){
        //         cout<<itr2<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int> ans(n, 0);
        int a, b, c;
        for(int i=0; i<n; i++){
            a = bookings[i][0] - 1;
            b = bookings[i][1] - 1;
            
            a = min(max(0, a), n-1);
            b = min(max(0, b), n-1);
            for(int j=a; j<b; j++){
                cout<<j+1<<" "<<bookings[i][2]<<endl;
                ans[j] += bookings[i][2];;
            }
        }
        return ans;
    }
};

















// old code, wrong answer
// Given the root of a binary tree, each node in the tree has a distinct value. After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees). Return the roots of the trees in the remaining forest.  You may return the result in any order.

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
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        cout<< root->val <<" ";
        inorder(root->right);
    }
    TreeNode* collect_roots(TreeNode* root, int q, vector<TreeNode*> &store){
        if(root == NULL) return NULL;
        if(root->val == q){
            cout<<"found: \n";
            if(root->left != NULL){
                store.push_back(root->left);
                root->left = NULL;
            }
            if(root->right != NULL){
                store.push_back(root->right);
                root->right = NULL;
            }
            return NULL;
        }
        root->left = collect_roots(root->left, q, store);
        root->right = collect_roots(root->right, q, store);
        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        int q = to_delete.size();
        vector<TreeNode*> store;
        for(int i=0; i<q; i++){
            root = collect_roots(root, to_delete[i], store);
            inorder(root);
            cout<<endl;
        }
        store.push_back(root);
        return store;
    }
};