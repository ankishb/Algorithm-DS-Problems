
#include <bits/stdc++.h>
using namespace std;

void inefficient_length_of_last_word(string A){
	int index = 0;
	int count = 0;
	int prev_count = 0;
	int i;
	for(int i=0; i<A.length(); i++){
		if(A[i] != ' '){
			count++;
			cout<<count<<" ";
			// index = i;
		}
		else if(A[i]==' ' && A[i-1]!=' '){
			prev_count = count;
			count = 0;
		}
		else{
			count = 0;
		}
	}
	if(A[A.length()-1] != ' '){
		// count is not zero and was not stored in prev_count
		cout<<endl<<count<<endl;
	}
	else{
		cout<<endl<<prev_count<<endl;
	}
}

void length_of_last_word(string A){
	int count = 0;
	int prev_count = 0;
	for(int i=A.length()-1; i>=0; i--){
		if(A[i+1] != ' ' && A[i] == ' ' && i<A.length()-1){
			break;
		}
		if(A[i] == ' '){
			count = 0;
		}

		else if(A[i] != ' '){
			count++;
			cout<<count<<" ";
			// index = i;
		}
	}
	cout<<count<<endl;
}

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

int main()
{
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
		string str;
		// cin>>str;
		getline(cin, str);
		// amazing_subarrays(str);
		length_of_last_word(str);
	}
	return 0;
}