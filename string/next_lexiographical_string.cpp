
/*
Approach:
1. first find the pivot, the current element is lesser than next element
2. Now pick the character which is next greater than this pivot and replace it
3. sort the character after the pivot index.
*/
// Complete the biggerIsGreater function below.
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