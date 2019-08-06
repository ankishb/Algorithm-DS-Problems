/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        
    }
};



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    TreeNode * root = NULL;
    CBTInserter(TreeNode* root_) {
        root = root_;
    }
    
    int insert(int v) {
        // do level order transversal, and insert when we find first left/right child missing
        queue<TreeNode*> q;
        TreeNode* front;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
        	front = q.front();
        	q.pop();
        	if(front->left != NULL) q.push(front->left);
        	if(front->right != NULL) q.push(front->right);

        	if(front->left == NULL){
        		front->left = new TreeNode(v);
        		return front->val;
        	}
        	if(front->right == NULL){
        		front->right = new TreeNode(v);
        		return front->val;
        	}

        	if(q.front() == NULL){
        		q.pop();
        		q.push(NULL);
        	}
        	if(q.size()==1 && q.front()==NULL){
        		break;
        	}
        }
    }
    
    TreeNode* get_root() {
        return root;
    }
};



919. Complete Binary Tree Inserter

    User Accepted: 993
    User Tried: 1106
    Total Accepted: 1010
    Total Submissions: 1736
    Difficulty: Medium

A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Write a data structure CBTInserter that is initialized with a complete binary tree and supports the following operations:

    CBTInserter(TreeNode root) initializes the data structure on a given tree with head node root;
    CBTInserter.insert(int v) will insert a TreeNode into the tree with value node.val = v so that the tree remains complete, and returns the value of the parent of the inserted TreeNode;
    CBTInserter.get_root() will return the head node of the tree.




/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */







class Solution {
public:
	int efficient(vector<int> &A){
		vector<int> B(A);
        int n = A.size();
        for(int i=0; i<n; i++){
            B.push_back(A[i]);
        }
        queue<int> q;
        int front;

        int cur_sum=0, max_sum=A[0], count=0;
        int i=0, j=0;
        while(j<2*n){
        	if(count > n){
        		front = B[i];
        		cur_sum -= front;
        		i++;
        	}
        	else{
        		// q.push(B[j]);
        		cur_sum += B[j];
        		max_sum = max({B[j], cur_sum, max_sum});
        		if(cur_sum < 0){
        			cur_sum = 0;
        			// while(!q.empty()) q.pop();
        			count = 0;
        		}
        		j++;
        	}
        }
        return max_sum;
	}


	int naive(vector<int> &A){
		vector<int> B(A);
        int n = A.size();
        for(int i=0; i<n; i++){
            B.push_back(A[i]);
        }
        
        int global_sum = A[0];
        int max_sum = A[0], cur_sum = 0;
        for(int i=0; i<n; i++){
            max_sum = A[i];
            cur_sum = 0;
            for(int j=i; j<i+n; j++){
                cur_sum += B[j];
                max_sum = max({B[j], max_sum, cur_sum});
                if(cur_sum < 0) cur_sum = 0;
            }
            global_sum = max(global_sum, max_sum);
        }
        return global_sum;
	}

    int maxSubarraySumCircular(vector<int>& A) {
        return naive(A);
    }
};












class Solution {
public:
    string reverseOnlyLetters(string S) {
        string s = "";
        int n = S.length();
        for(int i=0; i<n; i++){
            if((S[i]>=65 && S[i]<=90) || S[i]>=97 && S[i]<=122){
                s += S[i];
            }
        }
        cout<<s<<endl;
        
        string ans = "";
        int j = n-1;
        for(int i=0; i<n; i++){
            if((S[i]>=65 && S[i]<=90) || S[i]>=97 && S[i]<=122){
                ans += s[j];
                j--;
            }
            else{
                ans += S[i];
            }
            cout<<i<<" "<<j<<endl;
        }
        cout<<ans<<endl;
        return ans;
    }
};
















class Solution {
public:
	int efficient(vector<int> &A){
		vector<int> B(A);
        int n = A.size();
        for(int i=0; i<n; i++){
            B.push_back(A[i]);
        }
        queue<int> q;
        int front;

        int cur_sum=0, max_sum=A[0], count=0;
        int temp_sum = 0;
        int i=0, j=0;
        while(j<2*n){
        	if(count >= n){
        		front = B[i];
        		cur_sum -= front;
        		i++;
                count--;
                
                temp_sum = cur_sum;
                while(i<j && count>0 && cur_sum - B[i] >= temp_sum){
                    cur_sum = cur_sum - B[i];
                    temp_sum = cur_sum;
                    i++;
                    count--;
                }
        	}
        	else{
        		// q.push(B[j]);
        		cur_sum += B[j];
                count++;
        		max_sum = max({B[j], cur_sum, max_sum});
                
                
                temp_sum = cur_sum;
                while(i<j && count>0 && cur_sum - B[i] >= temp_sum){
                    cur_sum = cur_sum - B[i];
                    temp_sum = cur_sum;
                    i++;
                    count--;
                }
                
        		if(cur_sum < 0){
        			cur_sum = 0;
        			// while(!q.empty()) q.pop();
        			count = 0;
        		}
        		j++;
        	}
        }
        return max_sum;
	}


	int naive(vector<int> &A){
		vector<int> B(A);
        int n = A.size();
        for(int i=0; i<n; i++){
            B.push_back(A[i]);
        }
        
        int global_sum = A[0];
        int max_sum = A[0], cur_sum = 0;
        for(int i=0; i<n; i++){
            max_sum = A[i];
            cur_sum = 0;
            for(int j=i; j<i+n; j++){
                cur_sum += B[j];
                max_sum = max({B[j], max_sum, cur_sum});
                if(cur_sum < 0) cur_sum = 0;
            }
            global_sum = max(global_sum, max_sum);
        }
        return global_sum;
	}

    int maxSubarraySumCircular(vector<int>& A) {
        // return naive(A);
        return efficient(A);
    }
};