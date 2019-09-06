
class Solution {
public:
    bool hasAlternatingBits(int n) {
        if(n <= 2) return true;
        bool one = (n & 1) ? true : false;
        n = n>>1;
        while(n > 0){
            if(one && (n&1)==0) one = false;
            else if(!one && (n&1)==1) one = true;
            else return false;
            n = n>>1;
        }
        return true;
    }
};