
class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(true){
            if(n == 1) return true;
            else if(n < 1) return false;
            else{
                if((n>>1)*2 != n) return false;
                n = n>>1;
            }
        }
        return true;
    }
    bool isPowerOfThree(int n) {
        while(true){
            if(n == 1) return true;
            else if(n < 3) return false;
            else{
                if((n/3)*3 != n) return false;
                n = n/3;
            }
        }
        return true;
    }
    bool isPowerOfFour(int n) {
        while(true){
            if(n == 1) return true;
            else if(n < 4) return false;
            else{
                if((n>>2)*4 != n) return false;
                n = n>>2;
            }
        }
        return true;
    }
};