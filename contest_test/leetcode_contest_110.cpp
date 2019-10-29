

class Solution {
public:
	int mod = 1000000007;
	void helper(string str, int idx, set<string> &store, string cur){
		int n = str.length();
		if(idx >= n) return;
		store.insert(cur);
		for(int i=idx; i<n; i++){
			// either include it
			cur = cur+str[i];
			helper(str, i+1, store, cur);
			cur.pop_back();
		}
	}

    int distinctSubseqII(string str) {
        set<string> store;
        string cur = "";
        helper(str, 0, store, cur);
        return (store.size()%mod);
    }
};




class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int n = logs.size();
        vector<string> ans(n);
        vector<pair<string, int>> store;
        int j;
        for(int i=0; i<n; i++){
        	j = 0;
        	while(logs[i][j] !=' ' && 
        		(!(isalpha(logs[i][j+1])) || 
        		!(isdigit(logs[i][j+1])))){
        		// cout<<logs[i][j]<<" ";
                j++;
        	}
            j++;
        	if(isalpha(logs[i][j])){
                // cout<<logs[i][j];
        		store.push_back(make_pair(logs[i].substr(j), i));
        	}
            // cout<<endl;
        }
        sort(store.begin(), store.end());
        int m = store.size();
        j = 0;
        for(auto itr : store){
        	ans[j] = logs[itr.second];
        	j++;
        }
        int jj;
        for(int i=0; i<n; i++){
        	jj = 0;
            while(logs[i][jj] !=' ' && 
        		(!(isalpha(logs[i][jj+1])) || 
        		!(isdigit(logs[i][jj+1])))){
        		// cout<<logs[i][j]<<" ";
                jj++;
        	}
            jj++;
        	if(isdigit(logs[i][jj])){
        		ans[j] = logs[i];
        		j++;
        	}
        }
        return ans;
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
class Solution {
public:
	void get_sum(TreeNode* root, int l, int r, int &sum){
		if(root == NULL) return ;
		if(root->val >= l && root->val <= r){
			sum += root->val;
		}
		get_sum(root->left, l, r, sum);
		get_sum(root->right, l, r, sum);
	}

    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        get_sum(root, L, R, sum);
        return sum;
    }
};


class Solution {
public:
	int get_dist(vector<vector<int>> points){
		sort(points.begin(), points.end());
		int x1,y1,x2,y2,x3,y3,x4,y4;
		x1 = points[0][0], y1 = points[0][1];
		x3 = points[1][0], y3 = points[1][1];
		x2 = points[2][0], y2 = points[2][1];
		x4 = points[3][0], y4 = points[3][1];
		if(x1!=x3 && y1!=y2) return 0;
		if(x2!=x4 && y3!=y4) return 0;
		return (x2-x1)*(y3-y1);
	}

	void helper(vector<vector<int>>& points, vector<vector<int>> &vect, int idx, int min_area){
		int n = points.size();
		if(vect.size() > 4) return ;
		if(vect.size() == 4){
			int area = get_dist(vect);
			if(area != 0) min_area = min(min_area, area);
		}
		for(int i=idx; i<n; i++){
			vect.push_back(points[i]);
			helper(points, vect, i+1, min_area);
			vect.pop_back();
		}
	}

    int minAreaRect(vector<vector<int>>& points) {
        vector<vector<int>> vect;
        int min_area = INT_MAX;
        helper(points, vect, 0, min_area);
        return (min_area != INT_MAX) ? min_area : 0;
    }
};




















