
class Solution {
public:
	// time complexity: O(m+n) Space complexity: O(m)
	vector<int> efficient(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> res;
        for(int i = 0; i < (int)nums1.size(); i++) dict[nums1[i]]++;
        for(int i = 0; i < (int)nums2.size(); i++)
            if(--dict[nums2[i]] >= 0) res.push_back(nums2[i]);
        return res;
    }

	// time complexity: O(mlogm + nlogn) Space complexity: O(1)
    vector<int> naive(vector<int>& nums1, vector<int>& nums2) {
  		int n1=nums1.size(), n2=nums2.size();
  		int i1=0, i2=0;
  		vector<int> ans;
  		while(i1<n1 && i2<n2){
  			if(nums1[i1] == nums2[i2]){
  				ans.push_back(nums1[i1]);
  				i1++, i2++;
  			}
  			else{
  				(n1 < n2) ? i2++ : i1++;
  			}
  		}
  		return ans;
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    	return naive(nums1, nums2);
    	return efficient(nums1, nums2);
	}
};




class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
  		int n1=nums1.size(), n2=nums2.size();
  		int i1=0, i2=0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
  		vector<int> ans;
  		while(i1<n1 && i2<n2){
  			if(nums1[i1] == nums2[i2]){
  				ans.push_back(nums1[i1]);
  				i1++, i2++;
  			}
  			else if(nums1[i1] < nums[i2]){
  				i1++;
  			}
  			else{
  				i2++;
  			}
  		}
  		return ans;
    }
};




class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    	vector<int> ans;
        int n1=nums1.size(), n2=nums2.size();
        unordered_map<int,int> my_map;
        for(int i=0; i<n1; i++){
        	my_map[nums1[i]]++;
        }
        for(int i=0; i<n2; i++){
        	if(my_map.find(nums2[i]) != my_map.end()){
        		ans.push_back(nums2[i]);
        		my_map.erase(nums2[i]);
        	}
        }
        return ans;
    }
};