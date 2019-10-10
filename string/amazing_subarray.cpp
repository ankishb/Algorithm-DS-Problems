
// new try
#define mod 10003;

bool is_vowel(char ch){
    char v[10] = {'a','e','i','o','u','A','E','I','O','U'};
    for(int i=0; i<10; i++){
        if(ch == v[i]) return true;
    }
    return false;
}
int Solution::solve(string s) {
    int ans = 0, n = s.length();
    for(int i=0; i<n; i++){
        if(is_vowel(s[i])){
            ans += (n-i);
            ans = ans%mod;
        }
    }
    return ans;
}




// old one
void amazing_subarrays(string A){
	long long ans=0;
	for(int i=0; i<A.length(); i++){
		if(A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u'||A[i]=='A'||A[i]=='E'||A[i]=='I'||A[i]=='O'||A[i]=='U'){
			ans = ans + (A.length() - i);
		}
	}
	// ans = count*fact(A.length()-1);
	ans = ans%10003;
	cout<<ans<<endl;
}

