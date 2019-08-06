/*
86. Interval List Intersections

Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order. Return the intersection of these two interval lists. 

Example:
Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists
*/
/*
Approach:
Use merge sort O(m+n) or two pointer
1. Init at start i1=0, i2=0
2. if there is overlap, push that intersection in ans
3. Else, we increment the index of list (interval) with smallest end time
*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n1=A.size(), n2=B.size();
        if(n1==0 && n2==0) return A;
        if(n1==0 || n2==0) return (n1==0)?A:B;
        vector<vector<int> > ans;
        int i1=0, i2=0;
        int a, b;
        while(i1<n1 && i2<n2){
        	if(A[i1][1] >= B[i2][0]){
                a = max(A[i1][0], B[i2][0]);
                b = min(A[i1][1], B[i2][1]);
                if(a <= b) ans.push_back({a,b});
        	}
    		if(A[i1][1] <= B[i2][1]) i1++;
    		else i2++;
        }
        return ans;
    }
};