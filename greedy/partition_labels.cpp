
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> m;
        int n = s.length();
        vector<int> ans;
        for(auto ch : s) m[ch]++;
        unordered_set<char> set_;
        int i = 0, j;
        while(i < n){
            j = i;
            set_.insert(s[j]);
            while(!set_.empty()){
                m[s[j]]--;
                if(set_.find(s[j]) == set_.end()){
                    set_.insert(s[j]);
                }
                if(m[s[j]] == 0){
                    set_.erase(s[j]);
                }
                j++;
            }
            ans.push_back(j - i);
            i = j;
        }
        return ans;
    }
};