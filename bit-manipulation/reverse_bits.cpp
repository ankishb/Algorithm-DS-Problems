class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0, bit;
        bool firstSet = false;
        for(int i=0; i<32; i++){
            if(n&1 == 1 && firstSet == false){
                firstSet = true;
            }
            bit = n&1;
            ans = ans<<1;
            if(bit == 1 && firstSet == true) ans++;
            n = n>>1;
            
        }
        return ans;
    }
    uint32_t reverseBits_easy(uint32_t n) {
        uint32_t ans = 0, bit;
        bool firstSet = false;
        for(int i=0; i<32; i++){
            ans = (ans<<1) + (n>>i &1);
        }
        return ansl;
    }
    
/*
this algorithm swaps the bits in the following steps:

    16 bits left and right swapped
    every couple of 8 bits swapped (every other 8 bits are picked by AND operation and 00ff and ff00 as masks equivalent to 0000000011111111 and 1111111100000000)
    every couple of 4 bits are swapped like above using 0f0f and f0f0 as masks.
    every couple of 2 bits are swapped using cc and 33 corresponding to 11001100 and 0011011
    every couple of 1 bit are swapped using aa and 55 corresponding to 10101010 and 01010101
    This results in log(D) time complexity in which D is the number of bits.
*/
    uint32_t reverseBits_Nice(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};