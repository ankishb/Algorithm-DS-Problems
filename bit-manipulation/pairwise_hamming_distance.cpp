
// #define mod 1000000007
int mod = 1000000007;

// partially passes (Interestingly, we have bug in defining n instead of using A.size())
int Solution::hammingDistance(const vector<int> &A) {
    int n = A.size();
    long long int count = 0;
    for(int i=0; i<31; i++){
        int zeros = 0, ones = 0;
        for(int j=0; j<n; j++){
            // (A[j] & (1<<i)) ? ones++ : zeros++;
            if(A[j] & (1<<i)) ones++;
        }
        // count += (ones*zeros)*2;
        count += (ones*(n-ones))*2;
        count = count%mod;
    }
    count = count%mod;
    return (int)count;
}

// passed all cases: (Remember the difference of const qualifier with container vs general container)
int Solution::hammingDistance(const vector<int> &A) {
    long long int count = 0;
    int ones, n = A.size();

    for(int i = 0; i < 31; i++){
        ones = 0;
        for(int j = 0; j < n; j++){
            if(A[j] & (1 << i)){
                ones++;
            }
        }
        count = count + (2*ones*(A.size()-ones));
        count = count%mod;
    }

    return (int)count;
}



// time-limit exceed O(n^2)
int bit_count(int a){
    int count = 0;
    while(a != 0){
        a = (a & (a-1));
        // cout<<a<<" ";
        count++;
    }
    return count;
}

int Solution::hammingDistance(const vector<int> &A) {
    // cout<<bit_count(10);cout<<endl;
    // cout<<bit_count(123);cout<<endl;
    // cout<<bit_count(77);cout<<endl;
    // cout<<bit_count(89);cout<<endl;
    // cout<<bit_count(1000);cout<<endl;
    
    int n = A.size(), ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            ans += bit_count(A[i]^A[j]);
            // cout<<endl;
            ans = ans%mod;
        }
    }
    ans *= 2;
    ans = ans%mod;
    return ans;
}