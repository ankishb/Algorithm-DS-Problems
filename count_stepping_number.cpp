
class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> ans;
        for(int i=low; i<=high; i++){
            string s = to_string(i);
            int n = s.length();
            if(n == 1) ans.push_back(i);
            else{
                bool passed = true;
                for(int i=1; i<n; i++){
                    if(abs(s[i] - s[i-1]) != 1){
                        passed = false; break;
                    }
                }
                if(passed) ans.push_back(i);
            }
        }
        return ans;
    }
};