/*
Solution with while loop causes some problem, as this will not
completely shift the bits, For exp: lets say we have 4 bit number as
0001(1) its reverse should be 1000(8), but with while loop we tranverse
 till n != 0 which is one one iteration, which mess-up with our intention
*/
class Solution {
public:
    // why sol1 is not working?
    uint32_t sol1(uint32_t n) {
        uint32_t ans = 0;
        for(int i=0; i<32; i++){
            cout<<(n & (1<<(31-i)))<<" ";
            ans = ans | ((n & (1<<(31-i))) << i);
        }
        return ans;
    }

    // get last bit bit and shift it in left side
    uint32_t sol2(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result = (result<<1) | (n & 1);
            n >>= 1;
            // result = (result<<1) + (n>>i &1);
        }
        return result;  
    }
    
    uint32_t sol3(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
    
    uint32_t sol4(uint32_t n) {
        uint32_t ans = 0, bit;
        for(int i=0; i<32; i++){
            bit = n&1;
            ans = ans<<1;
            if(bit == 1) ans++;
            n = n>>1;
            
        }
        return ans;
    }
    
    uint32_t reverseBits(uint32_t n) {
        // return sol1(n);
        // return sol2(n);
        // return sol3(n);
        return sol4(n);
    }
    
};
