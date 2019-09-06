class Solution {
public:
    vector<string> store;
    int count_bits(int n){
        int count = 0;
        while(n > 0){
            if(n&1) count++;
            n = n>>1;
        }
        return count;
    }
    void get_comb(int hi, int mj){
        // cout<<hi<<" "<<mj<<endl;
        vector<int> hour, min;
        for(int i=0; i<=11; i++){
            // cout<<count_bits(i)<<" "<<hi<<"--";
            if(count_bits(i) == hi){
                hour.push_back(i);
            }
        }
        for(int i=0; i<=59; i++){
            if(count_bits(i) == mj){
                min.push_back(i);
            }
        }
        for(auto h : hour){
            for(auto m : min){
                // cout<<h<<" "<<m<<"--";
                string s = to_string(h) + ":";
                if(m < 10) s += "0";
                s += to_string(m);
                store.push_back(s);
            }
        }
    }
    
    vector<string> readBinaryWatch(int num) {
        for(int i=0; i<=min(num,4); i++){
            get_comb(i, min(num-i, 6));
        }
        return store;
    }
};





vector<string> readBinaryWatch(int num) {
    vector<string> rs;
    for (int h = 0; h < 12; h++)
    for (int m = 0; m < 60; m++)
        if (bitset<10>(h << 6 | m).count() == num)
            rs.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
    return rs;
}