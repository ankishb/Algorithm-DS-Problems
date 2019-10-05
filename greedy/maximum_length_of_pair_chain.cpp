class pq_custom{
public:
    int last, len;
    pq_custom(int a, int b){
        last = a; len = b;
    }
};
bool operator<(const pq_custom &p1, const pq_custom &p2){
    return (p1.last == p2.last && p1.len < p2.len)||(p1.last > p2.last);
}

bool sort_by_sec(const vector<int> &p1, const vector<int> &p2){
    return (p1[1]==p2[1] && p1[0]<p2[0])||(p1[1]<p2[1]);
}

class Solution {
private:
    static bool cmp(vector<int>& a, vector<int>&b) {
        return a[1] < b[1] || a[1] == b[1] && a[0] < b[0];
    }
public:
    int findLongestChain1(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), sort_by_sec);
        vector<vector<int>> chains;
        for(auto v : pairs){
            if(chains.size() == 0){
                chains.push_back(v);
                continue;
            }
            bool found = false;
            int idx = 0, size = 0;
            for(int c=0; c<chains.size(); c++){
                // cout<<c.back()<<" "<<v[0]<<endl;
                if(chains[c].back() < v[0]){
                    // cout<<chains[c].size()<<" :: ";
                    if(found == true && size < chains[c].size()){
                        size = chains[c].size();
                        idx = c;
                    }
                    // cout<<chains[c].size()<<endl;
                    if(found == false){
                        found = true;
                        size = chains[c].size();
                        idx = c;
                    }
                }
            }
            if(!found) chains.push_back(v);
            else{
                chains[idx].push_back(v[0]);
                chains[idx].push_back(v[1]);
            }
        }
        int len = 0;
        for(auto c : chains){
            // for(auto d : c) cout<<d<<" "; cout<<endl;
            int size = c.size();
            len = max(len, size/2);
        }
        return len;
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), sort_by_sec);
        int n = pairs.size();
        int count = 1;
        vector<int> last;
        for(int i=0; i<n; i++){
            if(i == 0){
                last = pairs[i];
                continue;
            }
            if(pairs[i][0] > last.back()){
                last = pairs[i];
                count++;
            }
        }
        return count;
    }
};
