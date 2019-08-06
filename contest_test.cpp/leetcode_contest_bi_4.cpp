if year is divisible by 400 then is_leap_year
else if year is divisible by 100 then not_leap_year
else if year is divisible by 4 then is_leap_year
else not_leap_year

class Solution {
public:
    int numberOfDays(int Y, int M) {
        int days_31[] = {1,3,5,7,8,10,12};
        int days_30[] = {4,6,9,11};
        for(int i=0; i<7; i++){
        	if(M == days_31[i]) return 31;
        }
        for(int i=0; i<4; i++){
        	if(M == days_30[i]) return 30;
        }

        if(M == 2){
        	if(Y%400 == 0) return 29;
        	else if(Y%100 == 0) return 28;
        	else if(Y%4 == 0) return 29;
        	else return 28;
        }
        return -1;
    }
};


class Solution {
public:
    string removeVowels(string S) {
        string ans = "";
        int n = S.length();
        char a;
        for(int i=0; i<n; i++){
        	a = S[i];
        	if(a!='a' && a!='e' && a!='i' && a!='o' && a!='u'){
        		ans += a;
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
	vector<int> get_sum(TreeNode* root, double &sum){
		if(root == NULL){
			vector<int> temp{0,0};
			return temp;
		}
		// if(root->left==NULL && root->right==NULL){
		// 	vector<int> temp{root->val, 1};
		// 	return temp;
		// }
		vector<int> l_sum = get_sum(root->left, sum);
		vector<int> r_sum = get_sum(root->right,sum);
		
		int cur_sum = l_sum[0] + r_sum[0] + root->val;
		int cur_count = l_sum[1] + r_sum[1] + 1;
		double cur_ = (cur_sum*1.0)/(cur_count*1.0);
        cout<<cur_sum<<" : "<<cur_count<<" : "<<cur_<<endl;
		if(cur_ > sum){
			sum = cur_;
		}
		vector<int> temp{cur_sum, cur_count};
		return temp;
	}

    double maximumAverageSubtree(TreeNode* root) {
        double sum = -100000;
        vector<int> ans;

        ans = get_sum(root, sum);
        // cout<<sum;
        return sum;
    }
};





class Solution {
public:
	int get_max_length_seq(vector<int> A, vector<int> &ans){
		int n = A.size();
		vector<int> len(n, 1);
		vector<int> idx(n, 0);
		for(int i=1; i<n; i++){
			for(int j=0; j<i; j++){
				if(A[j] <= A[i] && len[i] <= len[j]+1){
					len[i] = len[j]+1;
					idx[i] = j;
				}
			}
		}

		int max_len = len[0];
		int max_idx = 0;
		for(int i=0; i<n; i++){
			if(max_len < len[i]){
				max_len = len[i];
				max_idx = i;
			}

		}
        for(auto itr : idx) cout<<itr<<" ";
        cout<<endl;
        for(auto itr : len) cout<<itr<<" ";
        cout<<endl;
        
		for(int i=0; i<max_len; i++) ans.push_back(0);
		int j = max_len - 1;
		while(j >= 0){
			ans[j] = A[max_idx];
			j--;
			// if(A[max_idx] == max_idx) break;
			max_idx = idx[max_idx];
			
		}
		for(auto itr : ans) cout<<itr<<" ";
        cout<<endl;
        
        return max_len;
	}

    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
    	vector<int> seq;
        int max_len = get_max_length_seq(nums, seq);
        cout<<max_len<<" ";
        if(max_len < 2*K) return false;

        // check case, if there are more than 2 repititions
        sort(seq.begin(), seq.end());
        int count = 1;
        for(int i=1; i<seq.size(); i++){
        	if(seq[i] != seq[i-1]) count++;
        }
        cout<<count<<" ";
        if(count < K) return false;
        return true;
    }
};