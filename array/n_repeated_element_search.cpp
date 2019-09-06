class Solution {
public:
    bool check_repetition(vector<int> A, int t){
        int count = 0;
        for(auto a : A){
            if(a == t) count++;
            if(count > 1) return true;
        }
        return false;
    }
    bool rec(vector<int> A, int lo, int hi, int &ans){
        if(lo > hi) return false;
        if(ans != A.size()) return true;
        int n = A.size();
        int idx = lo + rand() % (hi - lo + 1);
        // cout<<lo<<" "<<hi<<" "<<idx<<" "<<n<<endl;
        if(check_repetition(A, A[idx])){
            ans = idx;
            lo = hi + 1;
            return true;
        }
        bool left_half  = rec(A, lo, idx-1, ans);
        bool right_half = rec(A, idx+1, hi, ans); 
        return (left_half || right_half);        
    }
    int rand_algo(vector<int>& A) {
        int n = A.size();
        int ans = n;
        bool flag = rec(A, 0, n-1, ans);
        return A[ans];
    }
    int find_using_space(vector<int>& A) {
        int n = A.size();
        unordered_map<int,int> m;
        for(auto a : A){
            if(m.find(a) != m.end()) return a;
            m[a]++;
        }
        return 1;
    }
    
    // As there are N out of 2N element are repeating, so there are following poss:
    // 1. Either each element occurs alternatively. Exp: [1,4,2,4,3,4]
    // 2. Or one repeated is not alternative at one place, [1,2,4,4,3,4] 
    // 3. If many or all repeated at one place: [1,2,3,4,4,4] or [1,4,4,4,3,2,4] ...
    // After analyzing, it evolves only three possibility, enough to check for our case.
    //      1. A[i] == A[i-1]
    //      2. A[i] == A[i-2]
    //      3. If n < 6, lets say n = 4, then [1,2,3,1] or n = 2, [1,1]
    int best_solution(vector<int> A){
        for(int i=2; i<A.size(); i++){
            if(A[i] == A[i-1] || A[i] == A[i-2]){
                return A[i];
            }
        }
        return A[0];
    }
    
    int repeatedNTimes(vector<int>& A) {
        // return rand_algo(A);
        // return find_using_space(A);
        return best_solution(A);
    }
};