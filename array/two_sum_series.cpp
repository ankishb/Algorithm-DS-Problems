
// two-sum-in-array
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        int n = nums.size(), sum;
        unordered_map<int,int> map;
        for(int i=0; i<n; i++){
            sum = t - nums[i];
            if(map.find(sum) != map.end()){
                if(map[sum] != i) return {map[sum], i};
            }
            map[nums[i]] = i;
        }
        return {-1,-1};
    }
};

// two-sum-in-bst
class Solution {
public:
    unordered_map<int, TreeNode*> map;
    
    void preorder(TreeNode* root, int t, bool &ans){
        if(root == NULL) return;
        if(ans == true) return;
        int data = root->val;
        if(map.find(t - data) != map.end()){
            if(map[t-data] != root){
                ans = true;
            }
        }
        map[data] = root;
        preorder(root->left, t, ans);
        preorder(root->right, t, ans);
    }
    
    bool findTarget(TreeNode* root, int k) {
        bool ans = false;
        preorder(root, k, ans);
        return ans;
    }
};

///////// other solution //////////
Method 1.
This method also works for those who are not BSTs. The idea is to use a hashtable to save the values of the nodes in the BST. Each time when we insert the value of a new node into the hashtable, we check if the hashtable contains k - node.val.

Time Complexity: O(n), Space Complexity: O(n).

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> set;
        return dfs(root, set, k);
    }
    
    bool dfs(TreeNode* root, unordered_set<int>& set, int k){
        if(root == NULL)return false;
        if(set.count(k - root->val))return true;
        set.insert(root->val);
        return dfs(root->left, set, k) || dfs(root->right, set, k);
    }

Method 2.
The idea is to use a sorted array to save the values of the nodes in the BST by using an inorder traversal. Then, we use two pointers which begins from the start and end of the array to find if there is a sum k.

Time Complexity: O(n), Space Complexity: O(n).

    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);
        for(int i = 0, j = nums.size()-1; i<j;){
            if(nums[i] + nums[j] == k)return true;
            (nums[i] + nums[j] < k)? i++ : j--;
        }
        return false;
    }
    
    void inorder(TreeNode* root, vector<int>& nums){
        if(root == NULL)return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

///////////////////////////