
class sort_map{
public:
    int key;
    int value;
    sort_map(int key_, int value_){
        key = key_;
        value = value_;
    }
};

bool operator<(const sort_map& p1, const sort_map& p2) {
    return p1.value > p2.value;
}


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> my_map;
        int n = nums.size();
        for(int i=0; i<n; i++){
            my_map[nums[i]]++;
        }
        
        
        priority_queue<sort_map> pq;
        for(auto itr:my_map){
            if(pq.size() == k){
                sort_map p = pq.top();
                if(p.value < itr.second){
                    // remove top and push current itr's value
                    pq.pop();
                    pq.push(sort_map(itr.first, itr.second));
                }
            }
            else{
                pq.push(sort_map(itr.first, itr.second));
            }
        }
        
        my_map.clear();
        vector<int> ans(k, 0);
        while(!pq.empty()){
            sort_map p = pq.top();
            ans[k-1] = p.key;
            pq.pop();
            k--;
        }
        return ans;
    }
};




//
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }
        
        vector<int> res;
        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int,int> > pq; 
        for(auto it = map.begin(); it != map.end(); it++){
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > (int)map.size() - k){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};




// using hash table and bucket sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int num : nums)
            ++m[num];
        
        vector<vector<int> > buckets(nums.size() +1); 
        for (auto p : m)
            buckets[p.second].push_back(p.first);
        
        vector<int> ans;
        for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; --i) {
            for (int num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k)
                    break;
            }
        }
        return ans;
    }
};