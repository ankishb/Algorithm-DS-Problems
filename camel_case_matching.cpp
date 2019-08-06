
class Solution {
public:
    bool check_query(string q, unordered_map<char, int> my_map, int count){
        for(int j=0; j<q.size(); j++){
            // if(q[j]>90 || q[j]<65) continue;
            if(my_map.find(q[j]) != my_map.end()){
                my_map[q[j]]--;
                count--;
            }
            
            
            if(count<0) return false;
        }
        for(auto itr : my_map){
            if(itr.second > 0) return false;
        }
        return true;
    }
    
    vector<bool> camelMatch(vector<string>& q, string p) {
        unordered_map<char, int> my_map;
        for(int i=0; i<p.size(); i++){
            my_map[p[i]]++;
        }
        vector<bool> ans;
        bool q_ans;
        for(int i=0; i<q.size(); i++){
            q_ans = check_query(q[i], my_map, p.size());
            ans.push_back(q_ans);
        }
        return ans;
    }
};