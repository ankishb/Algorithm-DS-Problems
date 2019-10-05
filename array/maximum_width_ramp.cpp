class Solution {
public:
    int naive_sol(vector<int>& A) {
        int n = A.size();
        if(n <= 1) return 0;
        int min_id = n-1, max_id = n-1, ans = 0;
        // stack<int> s;
        for(int i=n-2; i>=0; i--){
            if(A[i] > A[max_id]){
                max_id = i;
                continue;
            }
            for(int j=n-1; j>i; j--){
                if(A[j] >= A[i]){
                    ans = max(ans, j-i);
                }
            }
        }
        return ans;
    }
    /*
    1. maintain a decreasing sequence. For exp [9,5,6,3,0,8] => [9,5,3,0]
    2. For each element in stack, find the right edge in array, start from last
        1. opti: Once we find a boundry of 4, we will not check
            for element less than index 4, as they will not be added in answer.
        2. opti: If last element is not greater than top element in stack, we 
            don't need to check for other element in stack as well(stack-> decr...)
    Note that: in step 1. while including 5, adding 6 doesn't make sense, 
        as [5 < 6], so solution for 6 is also valid and even better for 5.
    */
    int optimal_sol1(vector<int>& A){
        int n = A.size();
        stack<int> s;
        // step 1.
        for(int i=0; i<n; i++){
            if(s.empty() || A[s.top()] > A[i]){
                s.push(i);
            }
        }
        int ans = 0;
        // step 2. and 3.
        // we can even remove = sign in i>=ans, as 
        // we don't need to check for same length
        for(int i=n-1; i>=ans; i--){
            while(!s.empty() && A[s.top()] <= A[i]){
                ans = max(ans, i - s.top());
                s.pop();
            }
        }
        return ans;
    }
    int maxWidthRamp(vector<int>& A) {
        // return naive_sol(A);
        return optimal_sol1(A);
        // return optimal_sol2(A);
        // return optimal_sol3(A);
    }
};
/*
Intuition:
Keep a decraesing stack.
For each number,
binary search the first smaller number in the stack.

When the number is smaller the the last,
push it into the stack.

Time Complexity:
O(NlogN)

Java

    public int maxWidthRamp(int[] A) {
        List<Integer> s = new ArrayList<>();
        int res = 0, n = A.length;
        for (int i = 0; i < n; ++i) {
            if (s.size() == 0 || A[i] < A[s.get(s.size() - 1)]) {
                s.add(i);
            } else {
                int left = 0, right = s.size() - 1, mid = 0;
                while (left < right) {
                    mid = (left + right) / 2;
                    if (A[s.get(mid)] > A[i]) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                res = Math.max(res, i - s.get(left));
            }
        }
        return res;
    }
*/


/*
The idea is that for a tuple (i, j) such that j > i and A[i] <= A[j], if we can find an element A[k] on the right of A[j] (in other words k > j) such that A[k] >= A[i], we can then consider the tuple (i, k) since it increases our width.
Similarily for A[i], if we can find an element A[k] on the left of A[i] (k < i) such A[k] <= A[j], we can then consider the tuple (k, j) since it increases our width.

Based on this idea, we maintain 2 arrays: leftMin and rightMax
leftMin[i]: smallest element on the left of ith index (from index 0 to i including A[i])
rightMax[i]: largest element on the right of ith index (from i to n-1 including A[i])

 int maxWidthRamp(vector<int>& A) {
        if (A.empty()) return 0;
        
        int n = A.size();
        vector<int> leftMin(n), rightMax(n);
        
        leftMin[0] = A[0];
        for (int i = 1; i < n; i++)
            leftMin[i] = min(A[i], leftMin[i-1]);
        
        rightMax[n-1] = A

[n-1];
        for (int i = n-2; i >= 0; i--)
            rightMax[i] = max(A[i], rightMax[i+1]);
        
        int i = 0, j = 1, ans = 0;
        while (i < n && j < n) {
            if (leftMin[i] <= rightMax[j]) {
                ans = max(ans, j-i);
                j++;  // there can be more elements on right satisfying the constraint, thus move to right
            }
            else i++;  // all elements on left of A[i] are bigger, thus move to right 
        }
        return ans;
    }
*/