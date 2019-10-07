
vector<int> Solution::twoSum(const vector<int> &A, int t) {
    int n = A.size(), sum;
    unordered_map<int,int> map;
    for(int i=0; i<n; i++){
        sum = t - A[i];
        if((map.find(sum) != map.end()) && (map[sum] != i)){
            return {map[sum]+1, i+1};
        }
        if(map.find(A[i]) == map.end()) map[A[i]] = i;
    }
    return {};
}



vector<int> Solution::twoSum(const vector<int> &A, int B) {
// void find_pairs_with_sum(vector<int> &A, int B){
    unordered_map<int, int> my_map;
    unordered_map<int, int>::iterator itr;
    int sum = 0;

    vector<int> ans;
    for(int i=0; i<A.size(); i++){
        sum = B - A[i];
        // cout<<sum<<"----";
        itr = my_map.find(sum);

        if(itr!=my_map.end()){
            // cout<<"found element"<<endl;
            // cout<<itr->first<<"---"<<itr->second<<"=="<<i+1<<endl;
            ans.push_back(itr->second);
            ans.push_back(i+1);
            return ans;
        }
        else if(itr == my_map.end()){
            // cout<<itr->first<<" "<<itr->second<<" "<<i<<endl;
            // my_map[A[i]] = i+1;
            my_map.insert(make_pair(A[i], i+1));
        }
    }
    return ans;
}

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