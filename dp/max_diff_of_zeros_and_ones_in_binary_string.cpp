
// simple kadane algorithm
int get_length(string s){
    int max_sum = 0, sum = 0;
    int n= s.length();
    bool ones = true;
    for(int i=0; i<n; i++){
        if(s[i] == '0') ones = false;
        sum += (s[i] == '1') ? -1 : 1;
        max_sum = max(max_sum, sum);
        if(sum < 0) sum = 0;
    }
    return (ones) ? -1 : max_sum;
}
