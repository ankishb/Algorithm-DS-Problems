
class pq_custom{
public:
    int el, idx, freq;
    pq_custom(int a, int b, int c)
        : el(a), idx(b), freq(c){}
};

/*
Note how operator overloading work for max_heap,
    1. We want max element at top, so arrange the element in increasing order
    2. Notice, sorting is maintained in increasing order of freq or indices
*/
bool operator<(const pq_custom &p1, const pq_custom &p2){
    return (p1.freq < p2.freq) 
    || (p1.freq == p2.freq && p1.idx < p2.idx);
}

// Another method with structure
// struct pq_custom{
//     int el, idx, freq;
//     pq_custom(int a, int b, int c)
//         : el(a), idx(b), freq(c){}
// };

  
// struct custom_sort { 
//     bool operator()(pq_custom const& p1, pq_custom const& p2){ 
//         return (p1.freq < p2.freq) 
//         || (p1.freq == p2.freq && p1.idx < p2.idx);
//     } 
// }; 

// (with O(log size) time removal and insertion)
vector<int> Solution::solve(vector<vector<int> > &A) {
    // priority_queue<pq_custom, vector<pq_custom>, custom_sort> pq; 
    priority_queue<pq_custom> pq;
    
    vector<int> ans;
    unordered_map<int, int> freq;
    int n = A.size();
    
    for(int i=0; i<n; i++){
        if(A[i][0] == 1){
            freq[A[i][1]]++;
            pq.push(pq_custom(A[i][1], i, freq[A[i][1]]));
            ans.push_back(-1);
        }
        else{
            int el = pq.top().el;
            freq[el]--;
            pq.pop();
            ans.push_back(el);
        }
    }
    return ans;
}




// another elegant solution (with constant time removal and insertion)
vector<int> Solution::solve(vector<vector<int> > &A) {
    vector<int> ans;
    unordered_map <int, int> f;
    unordered_map <int, stack<int>> m;
    int maxfreq = 0;
    for (int i = 0; i < A.size(); i++)
    {
        int opt = A[i][0];
        int elem = A[i][1];
        if (opt == 1)
        {
            f[elem]++;
            maxfreq = max(maxfreq, f[elem]);
            m[f[elem]].push(elem);
            ans.push_back(-1);
        }
        else if (opt == 2)
        {
            int x = m[maxfreq].top();
            f[x]--;
            m[maxfreq].pop();
            if (m[maxfreq].size() == 0) maxfreq--;
            ans.push_back(x);
        }
    }
    return ans;
}


