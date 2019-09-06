
class Solution {
public:
    vector<int> twoSum(vector<int>& A, int t) {
        // return usingMemory(A, t);
        return twoPointer(A, t);
    }
    vector<int> usingMemory(vector<int> A, int t){
        unordered_map<int, int> myMap;
        int n = A.size();
        for(int i=0; i<n; i++){
            if(myMap.find(t - A[i]) != myMap.end()){
                return vector<int> ({myMap[t - A[i]], i+1});
                
            }
            myMap[A[i]] = i+1;
        }
        return vector<int> ({-1, -1});
    }
    vector<int> twoPointer(vector<int> A, int t){
        int n = A.size();
        int l = 0, r = n-1;
        while(l < r){
            if(A[l] + A[r] == t) return {l+1, r+1};
            else if(A[l] + A[r] > t) r--;
            else l++;
        }
        return {-1,-1};
    }
};