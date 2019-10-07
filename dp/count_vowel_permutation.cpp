/*
As we are dealing with vowels, and to prepare any string, we have set of rules.
According to them, each substring will have only vowels. So we need to keep track
only these 5 letter and and there is also some conditions, that which character 
will come after which one. Collecting all those, we obtain following logic:
*/
// #define ll long long int
// #define mod 1000000007
class Solution {
public:
    typedef long long int ll;
    int countVowelPermutation(int n) {
        if(n == 0) return 1;
        int mod = 1000000007;
        unordered_map<char, ll> map1, map2;
        map1['a'] = 1; map1['e'] = 1, map1['i'] = 1;
        map1['o'] = 1; map1['u'] = 1;

        if(n == 1) return 5;
        for(int i=2; i<=n; i++){
            map2['a'] = (map1['e']+map1['i']+map1['u'])%mod;
            map2['e'] = (map1['a']+map1['i'])%mod;
            map2['i'] = (map1['e']+map1['o'])%mod;
            map2['o'] = (map1['i'])%mod;
            map2['u'] = (map1['i']+map1['o'])%mod;
            map1 = map2;
            
        }
        ll count = 0;
        for(auto itr : map1){
            count += itr.second;
            count = count%mod;
        }
        return (int)count;
    }
};