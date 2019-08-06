// here map.find is not working, in unordered_map, but why?
class Solution {
public:
    vector<string> naive_approach(vector<string>& list1, vector<string>& list2) {
        int min_idx = INT_MAX;
        vector<string> ans;
        int min_count = 0;
        
        for(int i=0; i<list1.size(); i++){
            for(int j=0; j<list2.size(); j++){
                if(list1[i] == list2[j]){
                    if(i+j < min_idx){
                        min_idx = i+j;
                        min_count = 1;
                        ans.clear();
                        ans.push_back(list1[i]);
                    }
                    else if(i+j == min_idx){
                        min_count++;
                        ans.push_back(list1[i]);
                    }
                }
            }
        }
        return ans;
    }
    void get_min(vector<string>& list, vector<string>& ans, unordered_map<string, int> &my_map){
        int min_idx = INT_MAX;
        int cur;
        ans.clear();
        for(int i=0; i<list.size(); i++){
            if(my_map.count(list[i]) != 0){//my_map.end()){
                cur = my_map[list[i]] + i ;
                if(cur < min_idx){
                    min_idx = cur;
                    ans.clear();
                    ans.push_back(list[i]);
                }
                else if(cur == min_idx){
                    ans.push_back(list[i]);
                }
            }
        }
    }
    
    void collect_dict(vector<string>& list, unordered_map<string, int> &my_map){
        for(int i=0; i<list.size(); i++){
            // if(my_map[list[i]] != my_map.end()){
                my_map[list[i]] = i;
            // }
        }
    }
    
    vector<string> efficient_approach(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        unordered_map<string, int> my_map;
        int n1=list1.size(), n2=list2.size();
        bool first_large = false;
        if(n1 > n2){
            first_large = true;
            collect_dict(list2, my_map);
        }
        else collect_dict(list1, my_map);
        
        if(first_large) get_min(list1, ans, my_map);
        else get_min(list2, ans, my_map);
        
        return ans;
    }
    
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        // return naive_approach(list1, list2);
        return efficient_approach(list1, list2);
};



	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string>res;
        unordered_map<string,int>m;
        int min = INT_MAX;
        for(int i = 0; i < list1.size(); i++) m[list1[i]] = i;
        for(int i = 0; i < list2.size(); i++)
            if(m.count(list2[i]) != 0)
                if(m[list2[i]] + i < min) min = m[list2[i]] + i, res.clear(), res.push_back(list2[i]);
                else if(m[list2[i]] + i == min) res.push_back(list2[i]);
        return res;
    }