/*
Insert Interval [Hard]

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary). You may assume that the intervals were initially sorted according to their start times.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/
class Solution {
public:
    // intervals --> A, newInterval --> B
    vector<vector<int>> insert(vector<vector<int>>& A, vector<int>& B) {
        int n = A.size();
        vector<vector<int> > ans;
        if(n == 0 && B.size()==0) return ans;
        if(B.size() == 0) return A;
        if(n == 0){
            ans.push_back(B);
            return ans;
        }
        priority_queue<int> pq;
        int count = 0;
        bool visit_b = false;

        if(B[0] < A[0][0]){
        	ans.push_back(B);
        	pq.push(B[1]);
        	for(int i=0; i<n; i++){
        		if(A[i][0] <= pq.top()){
        			ans[count][1] = max(A[i][1], ans[count][1]);
        			if(A[i][1] > pq.top()){
        				pq.pop();
        				pq.push(A[i][1]);
        			}
        		}
        		else{
        			ans.push_back(A[i]);
        			pq.push(A[i][1]);
        			count++;
        		}
	        }
        }
        else{
        	ans.push_back(A[0]);
        	pq.push(A[0][1]);
        	for(int i=1; i<n; i++){
                cout<<A[i][0]<<" "<<A[i][1]<<" : "<<B[0]<<" "<<B[1]<<endl;
        		if(visit_b==false && B[0] < A[i][0]){
	        		if(B[0] <= pq.top()){
        			    ans[count][1] = max(B[1], ans[count][1]);
	        			if(B[1] > pq.top()){
	        				pq.pop();
	        				pq.push(B[1]);
	        			}
	        		}
	        		else{
	        			ans.push_back(B);
	        			pq.push(B[1]);
	        			count++;
	        		}
	        		// most important step
	        		i--;
	        		visit_b = true;
        		}
        		else{
        			if(A[i][0] <= pq.top()){
        			    ans[count][1] = max(A[i][1], ans[count][1]);
	        			if(A[i][1] > pq.top()){
	        				pq.pop();
	        				pq.push(A[i][1]);
	        			}
	        		}
	        		else{
	        			ans.push_back(A[i]);
	        			pq.push(A[i][1]);
	        			count++;
	        		}
        		}
	        }
	        // if B comes at last interval, then follow next step.
	        if(visit_b == false){
        		if(B[0] <= pq.top()){
    			    ans[count][1] = max(B[1], ans[count][1]);
        		}
        		else{
        			ans.push_back(B);
        		}
    		}
        }
        return ans;    
    }
};
