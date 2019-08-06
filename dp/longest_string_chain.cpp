bool custom(const string s1, const string s2){
    return (s1.length() < s2.length());
}

class Solution {
public:
    void print(string s){
        int n=s.length();
        int idx = n-1;
        while(idx !=0){
            string new_ = s.substr(0,idx) + s.substr(idx+1, n);
            cout<< new_ <<" ";
            idx--;
        }
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), custom);
        int n = words.size();
        if(n == 0) return 0;
        unordered_map<string, int> my_map;
        
        string temp, s;
        int max_len = 0, len, best;
        for(int i=0; i<n; i++){
            best = 0;
            s = words[i];
            len = s.length();
            for(int idx=0; idx<len; idx++){
                temp = s.substr(0,idx) + s.substr(idx+1);
                best = max(best, 1 + my_map[temp]);
            }
            my_map[words[i]] = best;
            max_len = max(max_len, best);
        }
        return max_len;
    }
};






// when there is no duplicate character in word
bool custom(const string s1, const string s2){
    return (s1.length() < s2.length());
}

class Solution {
private:
    unordered_map<char, int> my_map;
    vector<int> bit_mask;
    vector<int> len;
    
    int get_count(int a, int b){
        int ans = a^b;
        int count = 0;
        while(ans != 0){
            count += ans&1;
            ans = ans>>1;
        }
        return count;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), custom);
        int n = words.size();
        if(n == 0) return 0;
        
        // prepare mapping
        for(auto word : words){
            cout<< word <<" ";
            for(auto ch : word) my_map[ch] = 1;
        }
        cout<<endl;
        int i = 0;
        for(auto itr : my_map){
            my_map[itr.first] = i; 
            i++;
        }
        // prepare masking
        int temp = 0;
        for(auto word : words){
            temp = 0;
            for(auto ch : word){
                temp += pow(2, my_map[ch]);
            }
            bit_mask.push_back(temp);
        }
        
        len.resize(n, 1);
        for(int j=1; j<n; j++){
            for(int i=0; i<j; i++){
                // count 1s bit in xor(mask[i], mask[j])
                temp = get_count(bit_mask[i], bit_mask[j]);
                if(temp == 1) len[j] = max(len[j], len[i]+1);
            }
        }
        
        int ans = 0;
        for(auto itr : len){
            cout<< itr <<" ";
            ans = max(ans, itr);
        }
        return ans;
    }
};