https://leetcode.com/problems/word-ladder/

class Solution {
public:
    bool matched(string s1, string s2){
        int hash[256] = {0};
        for(auto ch : s1) hash[ch]++;
        for(auto ch : s2) hash[ch]--;
        bool freq = true, pos = false, neg = true;
        int count = 0;
        // we should have same freq of each word 
        // and only 2 character can be differ
        for(int i=0; i<256; i++){
            if(hash[i] != 0) count++;
            if(hash[i] > 1) return false;
            if(hash[i] <-1) return false;
            if(hash[i] == 1) pos = true;
            if(hash[i] == -1) neg = true;
        }
        if(count > 2) return false;
        if(pos == false || neg == false) return false;
        return true;
    }
    int ladderLength(string bw, string ew, vector<string>& wl) {
        int n = wl.size();
        bool found = false;
        for(auto s : wl){
            if(s == ew){ 
                found = true; 
                break; 
            }
        }
        if(!found) return 0;
        queue<pair<string,int>> q;
        unordered_set<string> vis;
        int count;
        q.push({bw,1});
        cout<<"==============\n";
        while(!q.empty()){
            string s1 = q.front().first;
            count = q.front().second;
            q.pop();
            if(s1 == ew) return count;
            if(vis.find(s1) != vis.end()){
                continue;
            }
            cout<<s1<<" "<<count<<endl;
            count++;
            vis.insert(s1);
            for(auto s2 : wl){
                if(vis.find(s2) == vis.end() && matched(s1,s2)){
                    q.push({s2,count});
                }
            }
        }
        
        return 0;
    }
};