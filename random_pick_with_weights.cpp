
class Solution {
public:
    vector<int> w;
    Solution(vector<int>& w_) {
        w.push_back(w_[0]);
        for(int i=1; i<w_.size(); i++){
            w.push_back(w_[i] + w[i-1]);
        }
    }
    
    int pickIndex() {
        // int left = 0, right = w.size()-1, mid;
        // int random = w[left] + rand()%(w[right]-w[left]+1);
        // // binary search for the next greater or equal in w
        // while(left <= right){
        //     mid = left + (right-left)/2;
        //     cout<< left <<" "<< right <<" "<< mid << endl;
        //     if(left == right) return left;
        //     if(mid-1>= 0 && w[mid-1] < random && w[mid] >= random) return mid;
        //     else if(w[mid] < random) left = mid;
        //     else right = mid-1;
        // }
        // return -1;
        int r = rand() % (w.back());
        auto itor = upper_bound(w.begin(), w.end(), r);
        return itor - w.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */