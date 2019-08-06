class Solution {
public:
    string customSortString(string S, string T) {
        int hash[256];
        for(int i=0; i<T.length(); i++){
            hash[T[i]]++;
        }
        string ans = "";
        for(int i=0; i<S.length(); i++){
            for(int j=0; j<hash[S[i]]; j++){
                ans += S[i];
            }
            hash[S[i]] = 0;
        }
        
        for(int i=0; i<T.length(); i++){
            for(int j=0; j<hash[T[i]]; j++){
                ans += T[i];
            }
            hash[T[i]] = 0;
        }
        return ans;
    }
};