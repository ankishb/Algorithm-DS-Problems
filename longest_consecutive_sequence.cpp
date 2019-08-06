
// My solution

#include <unordered_set>
int Solution::longestConsecutive(const vector<int> &A) {
    unordered_set<int> my_set;
    int max_len = 0;
    
    for(int i=0; i<A.size(); i++){
        my_set.insert(A[i]);   
    }
    
    for(int i=0; i<A.size(); i++){
        // run the following loop, if the current element is
        // first element in the consecutive. For example: 
        // [100, 1, 2, 3], it will run for 100 and 1 only.
        if(my_set.find(A[i]-1) == my_set.end()){
            int cur_el = A[i];
            while(my_set.find(cur_el) != my_set.end()){
                cur_el++;
            }
            max_len = max(max_len, cur_el-A[i]);
        }
    }
    
    return max_len;
}





// editorial
int Solution::longestConsecutive(const vector<int> &A) {
    unordered_set<int> hash;
    for(int i=0;i<A.size();i++){
        hash.insert(A[i]);
    }
    int l=1;
    int maxl=1;
    for(int i=0;i<A.size();i++){
        int j=1;
        l=1;
        if(hash.find(A[i]-1)==hash.end()){
            while(hash.find(A[i]+j)!=hash.end()){
                j++;
                l++;
            }
            if(l>maxl){
                maxl=l;
            }
        }
    }
    return maxl;
}



// fastest
int Solution::longestConsecutive(const vector<int> &a) {
    int max=a[0],min=a[0],n=a.size();
    long long int i;
    for(i=1;i<n;i++){
        if(max<a[i]){
            max=a[i];
        }
        if(min>a[i]){
            min=a[i];
        }
    }
    long long int size=max-min+1;
    vector<bool> v(size);
    for(i=0;i<n;i++){
        v[a[i]-min]=true;
    }
    int maxl=1;max=1;
    for(i=0;i<size-1;i++){
        maxl=1;
        while(i<size-1 && v[i]==true &&v[i+1]==true){
            maxl++;i++;
        }
        if(maxl>max){
            max=maxl;
        }
    }
    return max;
    
}