#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s1, s2;
	cin>>s1>>s2;

	int n1 = s1.length();
	int n2 = s2.length();
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	int carry=0, sum;
	string ans = "";
	int i;
	for(i=0; i<min(n1, n2); i++){
		sum = (s1[i]-'0')+(s2[i]-'0')+carry;
		ans += (sum%10 + '0');
		carry = sum/10;
	}
	for(int j=i; j<n1; j++){
		sum = (s1[j]-'0') + carry;
		ans += (sum%10 + '0');
		carry = sum/10;
	}
	for(int j=i; j<n2; j++){
		sum = (s2[j]-'0') + carry;
		ans += (sum%10 + '0');
		carry = sum/10;
	}
	if(carry != 0){
		ans += (carry+'0');
	}
	
	if(ans.length() == n1){
		reverse(ans.begin(), ans.end());
		cout<<ans<<endl;
	}
	else{
		reverse(s1.begin(), s1.end());
		cout<<s1<<endl;
	}
}

int main()
 {
	int test;
	cin>>test;
	// cin.ignore(1);
	while(test--){
	    solve();
	}
	return 0;
}