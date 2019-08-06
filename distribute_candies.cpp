// https://www.interviewbit.com/problems/distribute-candy/

int Solution::candy(vector<int> &ratings) {
    vector<int> val(ratings.size(), 1);
    
    int i = 0;
    
    while(i < ratings.size()){
        if(i == 0){
            if(ratings[i] > ratings[i+1]){
                val[i] = val[i+1] + 1;
            }
        }
        else if(i == ratings.size()-1){
            if(ratings[i] > ratings[i-1]){
                val[i] = val[i-1] + 1;
            }
        }
        else{
            if(ratings[i] > ratings[i+1] && ratings[i] > ratings[i-1]){
                val[i] = max(val[i+1], val[i-1]) + 1;
            }
            else if(ratings[i] > ratings[i+1]){
                val[i] = val[i+1] + 1;
            }
            else if(ratings[i] > ratings[i-1]){
                val[i] = val[i-1] + 1;
            }
        }
        i++;
    }
    
    i = ratings.size()-1;
    
    while(i >= 0){
        if(i == 0){
            if(ratings[i] > ratings[i+1]){
                val[i] = val[i+1] + 1;
            }
        }
        else if(i == ratings.size()-1){
            if(ratings[i] > ratings[i-1]){
                val[i] = val[i-1] + 1;
            }
        }
        else{
            if(ratings[i] > ratings[i+1] && ratings[i] > ratings[i-1]){
                val[i] = max(val[i+1], val[i-1]) + 1;
            }
            else if(ratings[i] > ratings[i+1]){
                val[i] = val[i+1] + 1;
            }
            else if(ratings[i] > ratings[i-1]){
                val[i] = val[i-1] + 1;
            }
        }
        i--;
    }
    
    int sol = 0;
    
    for(int i = 0; i < val.size(); i++){
        sol = sol + val[i];
    }
    
    return sol;
    
}



void print_candies(vector<int> vect){
    for(int i=0; i<vect.size(); i++){
        cout<<vect[i]<<", ";
    }
    cout<<endl;
}
int Solution::candy(vector<int> &A) {
    int n = A.size();
    vector<int> candies(n, 0);
    candies[0] = 1;
    for(int i=1; i<n; i++){
        if(A[i] > A[i-1]){
            candies[i] = candies[i-1] + 1;
        }
        else{
            // cout<<A[i]<<endl;
            candies[i] = 1;
            int j = i-1;
            while(j>=0){
                if(j==0 && A[j]>A[j+1]) candies[j]++;
                else if(j>0 && A[j]>=A[j-1]) break;
                else candies[j]++;
                j--;
            }
        }
        // print_candies(candies);
    }
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += candies[i];
        // cout<<candies[i]<<", ";
    }
    // cout<<endl;
    return sum;
}





int candy(vector<int> &ratings) {
    int candiesCnt = 0, curCandy, pos;
    vector<pair<int, int> > valueWithPos; 
    for (int i = 0; i < ratings.size(); i++) {
        valueWithPos.push_back(make_pair(ratings[i], i));
    }
    sort(valueWithPos.begin(), valueWithPos.end());
    vector<int> candies (ratings.size(), 0);
    for (int i = 0; i < valueWithPos.size(); i++) {
        pos = valueWithPos[i].second;
        curCandy = 0;
        if (pos > 0 && ratings[pos - 1] < ratings[pos]) {
            curCandy = candies[pos - 1];
        } 
        if (pos < ratings.size() - 1 && ratings[pos + 1] < ratings[pos]) {
            curCandy = max(curCandy, candies[pos + 1]);
        }
        candies[pos] = curCandy + 1;
        candiesCnt += candies[pos];
    }
    return candiesCnt;
}



int Solution::candy(vector<int> &ratings) {
    
    int sum=0;
    int *arr=new int[ratings.size()];
    for(int i=0; i<ratings.size(); i++){
        if(i>0 && ratings[i]>ratings[i-1])
            arr[i] = arr[i-1]+1;
        else
            arr[i] = 1;
        int j = i;
        while(j>0 && arr[j]>=arr[j-1] && ratings[j]<ratings[j-1]){
            arr[j-1]++;j--;
        }
    }
    for(int i=0;i<ratings.size();i++){
        sum+=arr[i];
    }
    return sum;
}