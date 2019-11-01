
// new try
class Solution {
public:
    int sieve_of_erath(int n){
        vector<bool> prime(n+1, true);
        for(int i=2; i*i<=n; i++){
            if(prime[i] == false) continue;
            for(int j=i*2; j<=n; j=j+i){
                prime[j] = false;
            }
        }
        int count = 0;
        for(int i=2; i<n; i++){
            if(prime[i]) count++;
        }
        return count;
    }
    int countPrimes(int n) {
        return sieve_of_erath(n);
    }
};

// old one
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        prime[0] = false, prime[1] = false;
        for (int i = 0; i < sqrt(n); ++i) {
            if (prime[i]) {
                for (int j = i*i; j < n; j += i) {
                    prime[j] = false;
                }    
            }    
        }
        return count(prime.begin(), prime.end(), true);
    }
};