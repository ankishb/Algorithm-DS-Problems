
class Solution {
public:
    int getPossibleHour(vector<int> piles, int no){
        // cout<<no<<" :: ";
        int count = 0;
        for(auto p : piles){
            // cout<<ceil(p / (double)no)<<" ";
            count += ceil(p / (double)no);
        }
        // cout<<count<<endl;
        return count;
    }
    
    int minEatingSpeed(vector<int>& piles, int H) {
        int minEl = INT_MAX, maxEl = INT_MIN;
        int n = piles.size();
        for(auto p : piles){
            minEl = min(minEl, p);
            maxEl = max(maxEl, p);
        }
        
        int l = 1, r = maxEl, m, noHour;
        while(l < r){
            m = l + (r - l)/2;
            noHour = getPossibleHour(piles, m);
            // if(noHour == H) r = m;
            if(noHour <= H) r = m;
            else l = m+1;
        }
        return l;
    }
};