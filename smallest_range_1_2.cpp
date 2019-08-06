class Solution {
public:
    int smallestRangeI(vector<int>& A, int k) {
        int temp = (*max_element(A.begin(), A.end()) - *min_element(A.begin(),A.end())) - 2*k;
        return (temp <= 0) ? 0 : temp;
    }
    int smallestRangeI_1(vector<int>& A, int k) {
		int temp=0, n=A.size();
		int min_el = INT_MAX;
		int max_el = INT_MIN;
		for(int i=0; i<n; i++){
			min_el = min(min_el, A[i]);
			max_el = max(max_el, A[i]);
		}
        temp = (max_el - min_el) - 2*k;
        return (temp <= 0) ? 0 : temp;
    }
};