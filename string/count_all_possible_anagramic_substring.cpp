
/* new approach
Approacch:
1. Collect all substring of length 1-N
2. sort them and put it in a map
3. Count its possible permutation count.
*/

int ncr(int n){
    int ans = n*(n-1)/2;
    return ans;
}

int sherlockAndAnagrams(string s) {
    int n = s.length();
    int count = 0;
    for(int i=1; i<n; i++){
        unordered_map<string, int> map;
        for(int j=0; j<=n-i; j++){
            string str = s.substr(j, i);
            sort(str.begin(), str.end());
            map[str]++;
        }
        // do analysis
        for(auto itr : map){
            count += ncr(itr.second);
        }
    }
    return count;
}

/* old one
Approacch:
1. Just collect all substring and sort it and put in map
2. Match if the existed doesn't have same [st_idx, end_idx]
3. else put in map
Note: Instead of sorting we can create special string as aba --> a2b1 (doesn't  make sense by the way)
*/
int ncr(int n){
    int r = 2;
    r = min(r, n-r);
    long int num = 1, den = 1;
    for(int i=0; i<r; i++){ num = num*n; n--; }
    for(int i=0; i<r; i++){ den = den*r; r--; }
    int ans = num/den;
    return ans;
}
// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    unordered_map<string, pair<int, int>> myMap;
    int n = s.length(), count = 0;
    string substr;
    pair<int, int> ipair;
    for(int i=0; i<n; i++){
        for(int j=i; j>=0; j--){
            substr = s.substr(j, i-j+1);
            sort(substr.begin(), substr.end());
            if(myMap.find(substr) != myMap.end()){
                ipair = myMap[substr];
                if(ipair.first != i){
                    myMap[substr].second = myMap[substr].second + 1; 
                }
            }
            else myMap[substr] = make_pair(i, 1);
        }
    }
    for(auto itr : myMap){
        ipair = itr.second;
        if(ipair.second > 1){
            count += ncr(ipair.second);
        }
    }
    return count;
}