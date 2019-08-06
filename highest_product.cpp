int Solution::maxp3(vector<int> &A) {
    // make an min_heap
    priority_queue<int, vector<int>, greater<int> > pq;
    int n = A.size();
    bool zero = false;
    for(int i=0; i<n; i++){
        if(A[i] == 0) zero = true;
        else if(pq.empty() || pq.size()<3){
            pq.push(A[i]);
        }
        else if(A[i] >= pq.top()){
            pq.pop();
            pq.push(A[i]);
        }
    }
    long long int ans = 1;
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        ans = ans* (long long int)(pq.top());
        pq.pop();
    }
    return ans;
}




// https://www.interviewbit.com/problems/highest-product/

int Solution::maxp3(vector<int> &A) {
    if(A.size() < 3){
        return 0;
    }
    
    long long int neg1 = INT_MAX, neg2 = INT_MAX;
    int neg1_count = 0;
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] < neg1 && A[i] < 0){
            neg1_count = 1;
            neg1 = A[i];
        }
        else if(A[i] == neg1 && A[i] < 0){
            neg1_count++;
        }
    }
    
    if(neg1_count > 1){
        neg2 = neg1;
    }
    else if(neg1_count == 1){
        for(int i = 0; i < A.size(); i++){
            if(A[i] < 0 && A[i] < neg2 && neg1 < A[i]){
                neg2 = A[i];
            }
        }
    }
    
    long long int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int max1_count = 0, max2_count = 0;
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] > max1){
            max1 = A[i];
            max1_count = 1;
        }
        else if(A[i] == max1){
            max1_count++;
        }
    }
    
    if(max1_count > 1){
        max1_count--;
        max2 = max1;
    }
    else{
        for(int i = 0; i < A.size(); i++){
            if(A[i] > max2 && max1 > A[i]){
                max2 = A[i];
                max2_count = 1;
            }
            else if(A[i] == max2 && max1 > A[i]){
                max2_count++;
            }
        }
    }
    
    if(max1_count > 1){
        max3 = max1;
    }
    else if(max2_count > 1){
        max3 = max2;
    }
    else{
        for(int i = 0; i < A.size(); i++){
            if(A[i] > max3 && max2 > A[i] && max1 > A[i]){
                max3 = A[i];
            }
        }
    }
    
    if(neg1 == INT_MIN || neg2 == INT_MIN){
        return (int)max1*max2*max3;
    }
    
    return (int)max(max1*max2*max3, max1*neg1*neg2);
}



















int Solution::maxp3(vector<int> &A) {
    // make an min_heap
    priority_queue<int, vector<int>, greater<int> > pq;
    int n = A.size();
    bool zero = false;
    for(int i=0; i<n; i++){
        if(A[i] == 0) zero = true;
        else if(pq.empty() || pq.size()<3){
            pq.push(A[i]);
        }
        else if(A[i] >= pq.top()){
            pq.pop();
            pq.push(A[i]);
        }
    }
    
    int neg1 = INT_MAX, neg2 = INT_MAX;    
    for(int i=0; i<n; i++){
        if(A[i]<0){
            // -3 -2 -1
            if(neg1 == INT_MAX) neg1 = A[i];
            else if(A[i] <= neg1){
                neg2 = neg1;
                neg1 = A[i];
            }
            else if(A[i] > neg1){
                if(neg2 == INT_MAX) neg2 = A[i];
                else if(neg2 > A[i]) neg2 = A[i];
            }
        }
    }
    
    long long int prod1 = 1;
    int temp;
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        temp = pq.top();
        prod1 = prod1* (long long int)(pq.top());
        pq.pop();
    }
    int temp = 1;
    int count = 0;
    if(neg1 != INT_MAX){
        temp *= neg1;
        count++;
    }
    if(neg2 != INT_MAX){
        temp *= neg2;
        count++;
    }
    
    long long int prod2 = neg1*neg2*
    cout<<neg1<<" "<<neg2<<endl;
    return ans;
}


// editorial
int Solution::maxp3(vector<int> &A) {
    sort (A.begin(), A.end());
    int n = A.size();
    return max(A[n - 1] * A[n - 2] * A[n - 3], A[n - 1] * A[0] * A[1])
}


// editorial
int Solution::maxp3(vector<int> &A) {
    sort(A.begin(), A.end(), greater<int>());
    
    int l = A.size();
    int p1 = A[0]*A[1]*A[2];
    
    if(A[0] <= 0 || A[l-1] >=0)
        return p1;
    
    int p2 = A[0]*A[l-1]*A[l-2];
    
    if(p2>p1)
        return p2;
    
    return p1;
}


// fastest
int Solution::maxp3(vector<int> &A) {
    if(A.size() == 0) return 0;
    if(A.size() == 1) return 1;
    if(A.size() == 2) return max(A[0] * A[1], max(A[0], A[1]));
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
    for(int i=0; i<A.size(); i++) {
        if(A[i] > max1){
            max3 = max2;
            max2 = max1;
            max1 = A[i];
        }
        else if(A[i] > max2) {
            max3 = max2;
            max2 = A[i];
        }
        else if(A[i] > max3) {
            max3 = A[i];
        }
        if(A[i] < min1) {
            min2 = min1;
            min1 = A[i];
        }
        else if(A[i] < min2) {
            min2 = A[i];
        }
    }
    //cout << max1 << " " << max2 << " " << max3 << " " << min1 << " " << min2 << endl;
    //cout << max1 * max2 * max3 << " " << min1 * min2 * max1 << endl;
    return max(max1 * max2 * max3, max1 * min1 * min2);
}






int Solution::maxp3(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int size=A.size();
    int i;
    int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN;
    int neg1=0,neg2=0;
    for(i=0;i<size;i++)
    {
        if(A[i]>=max1)
        {
            max3=max2;
            max2=max1;
            max1=A[i];
        }
        else if(A[i]>=max2)
        {
            max3=max2;
            max2=A[i];
        }
        else if(A[i]>=max3)
        max3=A[i];
       if(A[i]<0)
        {
            if(A[i]<=neg1)
            {
                neg2=neg1;
                neg1=A[i];
            }
            else if(A[i]<=neg2)
            {
                neg2=A[i];
            }
        }
    }
    if(neg1 && neg2)
    {
        return max(neg1*neg2*max1,max1*max2*max3);
    }
    else return max1*max2*max3;
}

