
int maximizingXor(int l, int r) {
    int i, b1, b2;
    for(i=31; i>=0; i--){
        b1 = l & (1 << i);
        b2 = r & (1 << i);
        if(b1 != b2) break;
    }
    return pow(2, i+1)-1;
}