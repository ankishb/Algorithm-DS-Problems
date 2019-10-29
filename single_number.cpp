https://leetcode.com/problems/single-number/
    
    int singleNumber(const vector<int> &A) {
        int n = A.size();
        int count[32] = {0};
        int result = 0;
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < n; j++) {
                if ((A[j] >> i) & 1) {
                    count[i]++;
                }
            }
            result |= ((count[i] % 3) << i);
        }
        return result;
    }


int Solution::singleNumber(const vector<int> &A) {
    int ans, one=0; int two=0;
    int common_bit;
    for(int i=0;i<A.size();i++){
        two = two |(one & A[i]);
        one = one^A[i];
        common_bit= ~(one&two);
        one = one & common_bit;
        two = two & common_bit;
    }
    return one;
}

int Solution::singleNumber(const vector<int> &A) {
    int ones = 0, twos = 0;
    for(int i = 0; i < A.size(); i++){
        ones = (ones ^ A[i]) & ~twos;
        twos = (twos ^ A[i]) & ~ones;
    }
    return ones;
}

