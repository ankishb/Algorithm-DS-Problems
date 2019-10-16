#define pii pair<int,int>
#define vi vector<int>
#define f first
#define s second

int naive(vector<int> &A, vector<int> &B, vector<int> &C) {
    unordered_map<int, vector<int> > my_map;
    int ans = INT_MAX, a, b, c, tp_, min_, max_, abs_diff;
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<B.size(); j++){
            for(int k=0; k<C.size(); k++){
                a = A[i], b = B[j], c = C[k];
                tp_ = (a>b) ? a : b;
                max_ = (tp_>c) ? tp_ : c;
                tp_ = (a<b) ? a : b;
                min_ = (tp_<c) ? tp_ : c;
                abs_diff = abs(max_ - min_);
                ans = (abs_diff < ans) ? abs_diff : ans;
                // cout<<a<<" "<<b<<" "<<c<<" "<<max_<<" "<<min_<<" "<<ans<<endl;
            }
        }
    }
    return ans;
}

int optimal(vector<int> &A, vector<int> &B, vector<int> &C) {
    int n1 = A.size(), n2 = B.size(), n3 = C.size();
    int i1 = 0, i2 =0 , i3 = 0;
    int max_el, min_el, min_diff = INT_MAX;
    int a = A[i1], b = B[i2], c = C[i3];
    
    while(true){
        max_el = max({a,b,c});
        min_el = min({a,b,c});
        min_diff = min(min_diff, max_el - min_el);
        
        if(a <= b && a <= c && i1+1 < n1){
            i1++; a = A[i1];
        }
        else if(b <= a && b <= c && i2+1 < n2){
            i2++; b = B[i2];
        }
        else if(c <= a && c <= b && i3+1 < n3){
            i3++; c = C[i3];
        }
        else break;
    }
    
    return min_diff;
}

int better_sol(vector<int> &A, vector<int> &B, vector<int> &C) {
    int ans = INT_MAX;
    int i=A.size()-1,j=B.size()-1,k=C.size()-1;
    while(i>=0 and j>=0 and k>=0)
    {
        int maxe = max(A[i], max(B[j],C[k]));
        int mine = min(A[i], min(B[j],C[k]));
        ans = min(ans, maxe - mine);
        if(A[i]==maxe) i--;
        else if(B[j]==maxe) j--;
        else if(C[k]==maxe) k--;
    }
    return ans;
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    // return naive(A, B, C);
    // return optimal(A, B, C);
    return better_sol(A, B, C);
}
