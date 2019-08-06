class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    	int count = 0;
    	int n = dominoes.size();
    	if(n<2) return 0;
        sort(dominoes.begin(), dominoes.end());
        
        for(int i=0; i<n; i++){
            if(dominoes[i][0] > dominoes[i][1]){
            	swap(dominoes[i][0], dominoes[i][1]);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
        	    if(((dominoes[i][0] == dominoes[j][0]) && (dominoes[i][1] == dominoes[j][1])) 
                   || ((dominoes[i][0] == dominoes[j][1]) && (dominoes[i][1] == dominoes[j][0]))){
        		    count++;
        		}
                else if((dominoes[i][0] < dominoes[j][0]) && (dominoes[i][1] < dominoes[j][0])) break;
        	}
        }
        return count;
    }
};




bool sort_by_sec(const vector<int> &v1, const vector<int> &v2){
	return (v1[1] < v2[1]);
}

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
    	int n = arr2.size();
        vector<vector<int>> vect;
        for(int i=0; i<n; i++){
        	vect.push_back({arr1[i], arr2[i], i});
        }
        sort(vect.begin(), vect.end());
        int cur_sum=0, max_sum=INT_MIN;
        int left=0, right=n-1;
        cur_sum = abs(vect[left][0] - vect[right][0]);
        cur_sum +=abs(vect[left][1] - vect[right][1]);
        cur_sum +=abs(vect[left][2] - vect[right][2]);

        max_sum = max(max_sum, cur_sum);

        sort(vect.begin(), vect.end(), sort_by_sec);
        cur_sum = abs(vect[left][0] - vect[right][0]);
        cur_sum +=abs(vect[left][1] - vect[right][1]);
        cur_sum +=abs(vect[left][2] - vect[right][2]);

        max_sum = max(max_sum, cur_sum);


    }
};




