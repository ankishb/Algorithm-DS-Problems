
bool custom_sort(const string &a, const string &b){
    return (a+b > b+a);
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> v;
    for(auto a : A){
        v.push_back(to_string(a));
    }
    sort(v.begin(), v.end(), custom_sort);
    string ans = "";
    for(auto a : v){
        ans += a;
    }
    int i = 0, n = ans.length();
    while(i < n){
        if(ans[i] != '0') break;
        i++;
    }
    return (i == n) ? "0" : ans.substr(i);
}


/*
unsigned long long concatenate(int x, int y) {
    unsigned pow = 10;
    while(y >= pow)
        pow *= 10;
    return (unsigned long long)x * pow + y;        
}

bool custom_sorting (int i,int j) { 
    return concatenate(i,j) > concatenate(j,i); 
}
*/