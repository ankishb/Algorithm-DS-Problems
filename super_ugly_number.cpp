class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> arr, indices;
        arr.push_back(1);
        int minEl;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto p : primes){ 
            pq.push(p); 
            indices.push_back(0); 
        }
        while(arr.size() != n){
            minEl = pq.top();
            // cout<<minEl<<" ";
            arr.push_back(minEl);
            for(int p=0; p<primes.size(); p++){
                if(minEl % primes[p] == 0){
                    pq.pop(); 
                    indices[p]++;
                    pq.push(primes[p] * arr[indices[p]]);
                }
            }
        }
        return arr.back();
    }
};