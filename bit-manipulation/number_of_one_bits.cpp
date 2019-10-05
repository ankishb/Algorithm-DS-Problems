/*
At each step, we remove one set bit
Here is the intution,
    if we take ans of n and n-1, which will remove one set bit from right
    exp1: 110(6) ==> 110(6) & 101(5) == 100(4)
    exp2: 111(7) ==> 111(7) & 110(6) == 110(6)
*/
int fastest1(unsigned int n){
    int count = 0;
    while(n != 0){
        n = (n & (n-1));
        count++;
    }
    return count;
}
int fastest2(unsigned int n){
    int fb = 0xff000000;
    int sb = 0x00ff0000;
    int tb = 0x0000ff00;
    int fb_= 0x000000ff;
    return fastest1(n&fb) + fastest1(n&sb)+
            fastest1(n&tb) + fastest1(n&fb_);
}

int naive2(unsigned int n){
    int count = 0;
    for(int i=0; i<32; i++){
        count += ((n & (1<<i)) != 0);
    }
    return count;
}

int naive1(unsigned int n){
    int count = 0;
    while(n != 0){
        if(n&1) count++;
        n = n>>1;
    }
    return count;
}
int Solution::numSetBits(unsigned int A) {
    return naive1(A);
    // return naive2(A);
    // return fastest1(A);
    // return fastest2(A);
}
