
//decode_ways_1
class Solution {
public:
    int numDecodings(string s) {
        int count = 0, n = s.length(), no1, no2;
        if(n == 0) return 0;
        // if(n == 1) return 1;
        vector<int> hash1(27,0), hash2(27,0);
        
        hash1[s[0]-'1'+1]++;
        for(int i=1; i<n; i++){
            hash2.clear();
            hash2.resize(27,0);
            no1 = s[i] - '1' + 1;
            for(int j=1; j<=26; j++){
                if(hash1[j] != 0){
                    hash2[no1] += hash1[j];
                    no2 = j*10 + no1;
                    if(no2 <= 26){
                        hash2[no2] += hash1[j];
                    }
                }
            }
            
            hash1 = hash2;
        }
        
        for(int i=1; i<=26; i++) count += hash1[i];
        return count;
    }
};


// decode_ways_2
typedef long long int ll;
class Solution {
public:
    int numDecodings(string s) {
        int count = 0, n = s.length(), no1, no2;
        int mod = 1000000007;
        if(n == 0) return 0;
        vector<int> hash1(27,0), hash2(27,0);
        
        if(s[0] == '*'){
            for(int i=1; i<=9; i++) hash1[i]++;
        }
        else hash1[s[0]-'1'+1]++;
        for(int i=1; i<n; i++){
            hash2.clear();
            hash2.resize(27,0);
            if(s[i] == '*'){
                for(int k=1; k<=9; k++){
                no1 = k;
                for(int j=1; j<=26; j++){
                    if(hash1[j] != 0){
                        hash2[no1] = (hash2[no1]%mod + hash1[j]%mod)%mod;
                    }
                    no2 = j*10 + no1;
                    if(hash1[j] != 0 && no2 <= 26){
                        hash2[no2] = (hash2[no2]%mod + hash1[j]%mod)%mod;
                    }
                }
                }
            }
            else{
                no1 = s[i] - '1' + 1;
                for(int j=1; j<=26; j++){
                    if(hash1[j] != 0){
                        hash2[no1] = (hash2[no1]%mod + hash1[j]%mod)%mod;
                    }
                    no2 = j*10 + no1;
                    if(hash1[j] != 0 && no2 <= 26){
                        hash2[no2] = (hash2[no2]%mod + hash1[j]%mod)%mod;
                    }
                }
            }
            hash1 = hash2;
        }
        
        count = 0;
        for(int i=1; i<=26; i++){
            count = (count%mod + hash1[i] % mod)%mod;
        }
        return count;
    }
};