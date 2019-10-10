
/*
Repeat for each character
1. find number of character smaller than the current character, on the right hand side
2. Find the permutation of substring of length (n-i-1)
3. number of poss for current index will be multiplier(1.)*permutation(2.)

Note: to save some time, we can maintain aa array of factorial of length upto 26, 
	as none of character(lower letter) is not repeated in the given string.
*/

typedef long long int ll;

ll get_per(int n){
    ll ans = 1;
    while(n > 1){
        ans *= n;
        n--;
        ans = ans%1000003;
    }
    return ans;
}

int Solution::findRank(string s){
    int n = s.length();
    int mul, per;
    ll count = 0;
    for(int i=0; i<n; i++){
        mul = 0;
        for(int j=i+1; j<n; j++){
            if(s[i] > s[j]) mul++;
        }
        per = n-i-1;
        count += get_per(per)*mul;
        count = count%1000003;
    }
    count = (count+1)%1000003;
    return (int)count;
}
