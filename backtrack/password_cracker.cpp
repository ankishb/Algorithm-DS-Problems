
/*
Input:
    5
    10
    rqee momxnlfjb xrbmeih mgcxy fvsfbdliyp xtvuhieo dxjokfldc yetcavnlof yvadkh ngut
    pouxllfpbxtvzhieoovsfbdlkyb
    10
    yjwcocch wsta elfvzzbxq swwxfq ilwk xiqtb hnxxiot ejxtmxvf jeurpxyf glkhe
    elfvzzbxqwstailwkilwk
    10
    obcojozpu oahrqef gogla qdzb pmidz wyaq ykqntgi uztucyo byut nnwaldaop
    nnkalcanpybcsjtspuoblojqzpu
    10
    ddihmxzgdk sutvgb ifvqzlxc tmoccqna qxscvwxaif muihxrmdx olgga xjaqeq vtuc akfwn
    xjaqeqvtucsutvgbakfwn
    10
    a aa aaa aaaa aaaaa aaaaaa aaaaaaa aaaaaaaa aaaaaaaaa aaaaaaaaaa
    aaaaaaaaaaaaaaaaaaaaaaaaab

Output:
    WRONG PASSWORD
    elfvzzbxq wsta ilwk ilwk
    WRONG PASSWORD
    xjaqeq vtuc sutvgb akfwn
    WRONG PASSWORD
*/

// Note: memorization is necessaary, as last kind of test case have "exponential" time complexity nature

// string passwordCracker(vector<string> passwords, string loginAttempt) {
class solution{
public:
    bool flag;
    string ans;
    unordered_set<string> collect;
    unordered_set<int> memory;

    solution(vector<string> A){
        flag = false;
        for(auto s : A) collect.insert(s);
    }

    void helper(vector<string> A, string L, int idx, string cur) {
        if(idx >= L.length()){
            // cout<<idx<<" "<<cur<<endl;  
            ans = cur;
            flag = true;
            return ;
        }
        if(memory.find(idx) != memory.end()) return ;
        memory.insert(idx);
        
        int n = A.size();
        for(int i=0; i<n && !flag; i++){
            int len = A[i].length();
            string s = L.substr(idx, len);
            if(collect.find(s) != collect.end()){
                helper(A, L, idx+s.length(), cur+s+" ");
                if(flag) return;
            }
        }
    }
};

bool custom_sort(const string s1, const string s2){
    return (s1.length() > s2.length());
}
string passwordCracker(vector<string> A, string L) {
    solution sol(A);
    // sorting doesn't help
    sort(A.begin(), A.end(), custom_sort);
    
    sol.helper(A, L, 0, "");
    string ans = sol.ans;
    int n = ans.length();
    return (sol.flag) ? ans.substr(0,n-1) : "WRONG PASSWORD";
}