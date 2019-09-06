class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        /* there are 3 possible cass:
        1. x is less than arr[0], then ans is [0-k)
        2. x is greater than arr[n-1], then ans is [(n-k-1)-n)
        else: find location(l) of x if present, ans will be [(l-k/2)-(l+k/2-1)]
              else find the loc l, which it should inserted(lower bound), ans
                    will be [(l-k/2 - 1) - (l+k/2)]
        */
        int n = arr.size();
        vector<int> ans;
        if(n == 0) return ans;
        if(x < arr[0]){ copy(arr.begin(), arr.begin()+k, ans); return ans; }
        if(x > arr.back()) return copy(arr.end()-k, arr.end(), ans);
        
        int l = 0, r = n-1, m;
        while(l < r){
            m = l + (r - l)/2;
            if(arr[m] >= x) r = m;
            else l = m+1;
        }
        if(arr[l] == x){
            int low  = max(0, l-(k/2));
            int high = min(n-1, l+(k/2)+1);
            copy(arr.begin()+low, arr.begin()+high, ans);
        }
        else{
            int low  = max(0, l-(k/2)-1);
            int high = min(n-1, l+(k/2));
            copy(arr.begin()+low, arr.begin()+high, ans);
        }
        return ans;
    }
};