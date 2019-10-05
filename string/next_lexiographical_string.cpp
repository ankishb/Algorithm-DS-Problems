
/*
Approach:
1. first find the pivot, the current element is lesser than next element
2. Now pick the character which is next greater than this pivot and replace it
3. sort the character after the pivot index.
*/

// new one
string biggerIsGreater(string w) {
    int n = w.length();
    string ws = w;
    if(n < 2) return "no answer";
    int mid = n-1;
    for(int i=n-2; i>=0; i--){
        if(w[i] < w[mid]){
            // find next smaller character in the right hand side
            int min_t = i+1;
            for(int j = i+2; j<n; j++){
                if(w[j] > w[i] && w[j] < w[min_t]){
                    min_t = j;
                }
            }
            swap(w[i], w[min_t]);
            sort(w.begin()+i+1, w.end());
            return w;
        }
        if(w[i] >= w[mid]){
            mid = i;
        }
    }
    return (w == ws) ? "no answer" : w;
}

// older one
string biggerIsGreater(string w) {
    int n = w.length();
    int i = n-2;
    while(i>=0){
        if((w[i]-'a') >= (w[i+1]-'a')) i--;
        else break;
    }
    if(i == -1) return "no answer";
    int smaller = INT_MAX, idx;
    for(int j=i+1; j<n; j++){
        if((w[j]-'a') < smaller && (w[j]-'a')>(w[i]-'a')){
            smaller = (w[j]-'a');
            idx = j;
        }
    }
    swap(w[i], w[idx]);
    sort(w.begin()+i+1, w.end());
    return w;
}  