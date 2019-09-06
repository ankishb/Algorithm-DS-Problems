class Solution {
public:
    int get_comp(int num){
        vector<int> bin;
        while(num > 0){
            bin.push_back(num&1);
            num = num>>1;
        }
        int comp = 0, mul = 1;
        for(int i=0; i<bin.size(); i++){
            comp += mul*(1 - bin[i]);
            mul = mul*2;
        }
        return comp;
    }
    int getComplement(int num) {
        int n = 0;
        while (n < num) {
            n = (n << 1) | 1;
        }
        return n - num;
    }
    int fascinating_sol(int num){
        int mask = num;
        mask |= mask >> 1;
        mask |= mask >> 2;
        mask |= mask >> 4;
        mask |= mask >> 8;
        mask |= mask >> 16;
        return num ^ mask;
    }
    int findComplement(int num) {
        // return get_comp(num);
        // return getComplement(num);
        return fascinating_sol(num);
    }
};
