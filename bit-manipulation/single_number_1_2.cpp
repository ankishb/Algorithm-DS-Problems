
/* generalization to this question, every element repeat k times and only one element apeared 1 time
Use first method with:
	result |= ((count[i]%k) << i);
*/
// https://www.interviewbit.com/problems/single-number-i/
int Solution::singleNumber(const vector<int> &A) {
        int n = A.size();
        int count[32] = {0};
        int result = 0;
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < n; j++) {
                if ((A[j] >> i) & 1) {
                    count[i]++;
                }
            }
            result |= ((count[i]%2) << i);
        }
        return result;
    }
    
    
int Solution::singleNumber(const vector<int> &A) {
    int n = A.size();
    if(n == 0) return 0;
    int ans = 0;
    for(auto a : A) ans = ans ^ a;
    return ans;
}




// https://www.interviewbit.com/problems/single-number-ii/
int Solution::singleNumber(const vector<int> &A) {
    int result = 0, n = A.size();
    int bit_count[32] = {0};
    for(int i=0; i<32; i++){
        for(int j=0; j<n; j++){
            if(A[j] & (1<<i)){
                bit_count[i]++;
            }
        }
        result = result | ((bit_count[i]%3) << i);
    }
    return result;
}

/*
Let's see how following idea works, Suppose we have array [1,1,1] and we create
two empty buckets filled with zero [0] & [0]

At each iteration, we fill buckets acc to: [(first ^ a) & (~other)]
In concise, this logic checks for:
    whether element is present in bucket or not, 
    is yes, which bucket is it?

Itr1. [0^1 & ~0]=[1]      [0^1 & -1] = [0]
Itr2. [1^1 & ~0]=[0]      [0^1 & -0] = [1]
Itr3. [0^1 & ~1]=[0]      [1^1 & -0] = [0]

For three occurance of element , we get final states as: [0] & [0]

*/

int Solution::singleNumber(const vector<int> &A) {
    int n = A.size();
    if(n == 0) return 0;
    int firstSet = 0, secSet = 0;
    for(auto a : A){
        firstSet = (firstSet ^ a) & (~secSet);
        secSet   = (secSet ^ a) & (~firstSet);
    }
    return firstSet;
}
