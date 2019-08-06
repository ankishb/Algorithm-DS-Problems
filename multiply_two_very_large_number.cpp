#include <bits/stdc++.h>
using namespace std;

string add_two_String(string s1, string s2){
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
	
	reverse(ans.begin(), ans.end());
	return ans;
}

string multiply_two_strings(string s1, string s2){
	int n1 = s1.length();
	int n2 = s2.length();
	// vector<string> store;
	string current = "";
	int multi, carry=0;
	int zeros = 0;
	string s11 = s1;
	string ans = "";
	reverse(s11.begin(), s11.end());
	reverse(s2.begin(), s2.end());
	for(int i=0; i<n2; i++){
		current = "";
		// cout<<s11<<" * "<<s2[i]<<endl;
		for(int j=0; j<n1; j++){
			multi = ((s11[j]-'0')*(s2[i]-'0')) + carry;
			current += (multi%10 + '0');
			carry = multi/10;
		}
		while(carry!=0){
			current += (carry%10 + '0');
			carry = carry/10;
		}
		reverse(current.begin(), current.end());
		for(int k=0; k<zeros; k++){
			current += '0';
		}
		// cout<<current<<endl;
		if(i==0){
			ans = current;
		}
		else{
			ans = add_two_String(ans, current);
		}
		// store.push_back(current);
		zeros++;
	}

	// if(store.size() == 1) return store[0];
	// string ans = "";
	// string prev = store[0];
	// for(int i=1; i<store.size(); i++){
	// 	ans = add_two_String(prev, store[i]);
	// 	prev = ans;
	// }
	return ans;
}

int main()
 {
	int test;
	cin>>test;
	// cin.ignore(1);
	while(test--){
	    string s1, s2;
		cin>>s1>>s2;
		cout<<multiply_two_strings(s1, s2)<<endl;
	}
	return 0;
}