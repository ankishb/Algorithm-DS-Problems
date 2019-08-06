/*
56. Merge Intervals

Given a collection of intervals, merge all overlapping intervals.

Example 1:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
*/

/*
Approach:
1. sort by first element in each list
2. create heap, to store the second element and we start with index 1.
3. If starting time is less than or equal to end time (store at top of heap), we pop top and insert current end time
4. else we create a new list
*/

bool custom_sort(const vector<int> &v1, const vector<int> &v2){
    return (v1[0]<v2[0]) || ((v1[0]==v2[0])&&(v1[1]>v2[1]));
}

class Solution {
public:
	// A --> intervals
    vector<vector<int>> merge(vector<vector<int>>& A) {
        if(A.size() <= 1) return A;
        priority_queue<int> pq;
        sort(A.begin(), A.end(), custom_sort);
        // for(auto itr1 : A){
        //     for(auto itr2 : itr1){
        //         cout<<itr2<<" ";
        //     }
        //     cout<<"\n";
        // }
        vector<vector<int> > ans;
        ans.push_back(A[0]);
        pq.push(A[0][1]);
        int n = A.size();
        int ans_i = 0;

        for(int i=1; i<n; i++){
            cout<<pq.top()<<" : "<<A[i][0]<<endl;
        	if(pq.top() >= A[i][0]){
        		ans[ans_i][1] = max(A[i][1], pq.top());
                if(pq.top() < A[i][1]){
                    pq.pop();
        		    pq.push(A[i][1]);
                }
        	}
        	else{
        		ans.push_back(A[i]);
        		ans_i++;
                cout<<A[i][1]<<" ";
        		pq.push(A[i][1]);
        	}
        }
        return ans;
    }
};