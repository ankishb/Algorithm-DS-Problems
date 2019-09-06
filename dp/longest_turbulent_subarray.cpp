
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        // return brute_force(A);
        return optimal1(A);
    }
    int brute_force(vector<int>& A) {
        int n = A.size(); if(n == 0) return 0;
        int max_turb = 1, count = 0;
        bool max_to_min;

        for(int i=0; i<n-1; i++){
            count = 1;
            max_to_min = (A[i] > A[i+1]) ? true : false;
            for(int j=i; j<n-1; j++){
                if(max_to_min && A[j] > A[j+1]){count++; max_to_min = false; }
                else if(!max_to_min && A[j] < A[j+1]){count++; max_to_min = true; }
                else break;
            }
            max_turb = max(max_turb, count);
        }
        return max_turb;
    }
    int optimal1(vector<int>& A) {
        int n = A.size(); if(n == 0) return 0;
        if(n == 1) return 1; //don't need this condition too
        int i=0, j=0;
        int max_turb = 1, count = 0;
        bool max_to_min;
        while(i<n-1){ 
            count = 1;
            max_to_min = (A[i] > A[i+1]) ? true : false;
            for(j=i; j<n-1; j++){
                if(max_to_min && A[j] > A[j+1]){count++; max_to_min = false; }
                else if(!max_to_min && A[j] < A[j+1]){count++; max_to_min = true; }
                else break;
            }
            max_turb = max(max_turb, count);
            if(i == j) i++;
            else i = j;
        }
        return max_turb;
    }
};