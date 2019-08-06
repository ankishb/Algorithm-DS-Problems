/*
Approach: (Visual explanation)
1. create and array with count, as if A[i]=0, count--, else count++
2. Now create an hash map to get the largest subarray with same value
*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> idx(n+1, 0);

        for(int i=0; i<n; i++){
        	if(nums[i] == 0) idx[i+1] = idx[i] - 1;
        	if(nums[i] == 1) idx[i+1] = idx[i] + 1;
        }
        // for(auto itr : idx) cout<<itr<<" ";
        // cout<<endl;
        pair<int,int> p;
        unordered_map<int, pair<int,int> > my_map;
        for(int i=0; i<=n; i++){
        	if(my_map.find(idx[i]) == my_map.end()){
        		my_map.insert({idx[i], pair(i,i)});
        	}
        	else{
        		p = my_map[idx[i]];
        		if(p.second < i){
        			// my_map.insert({idx[i], pair(p.first,i)});
                    my_map[idx[i]].second = i;
        		}
        	}
        }

        idx.clear();
        int ans = 0;
        for(auto itr : my_map){
            p = itr.second;
        	// cout<<itr.first<<" : ("<< p.first << ", "<<p.second <<")\n";
        	ans = max(ans, (p.second - p.first));
        }
        my_map.clear();
        return ans;
    }
};