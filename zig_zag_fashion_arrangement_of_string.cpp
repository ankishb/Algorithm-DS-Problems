// Given a string and number of rows ‘n’. Print the string formed by concatenating n rows when input string is written in row-wise Zig-Zag fashion.

#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

void get_zigzag_arrangement(string s, int k){
	if(k==1 || k>=s.length()){
		cout<<s<<endl;
	}
	else{
		vector<string> vect;
		for(int i=0; i<k; i++){
			vect.push_back("");
		}
		vect[0] = s[0];
		int s_idx = 1;
		int v_idx = 0;


		for(int i=0; i<ceil((s.length())/k); i++){
			for(int ii=0; (ii<k-1)&&(s_idx<s.length()); ii++){
				v_idx++;
				vect[v_idx].push_back(s[s_idx]);
				s_idx++;
			}
			for(int ii=0; (ii<k-1)&&(s_idx<s.length()); ii++){
				v_idx--;
				vect[v_idx].push_back(s[s_idx]);
				s_idx++;
			}
		}
		string ans = "";
		for(int i=0; i<k; i++){
			ans = ans+vect[i];
		}
		cout<<ans<<endl;
	}
}

int main()
 {
	int test;
	cin>>test;
	while(test--){
		string s;
		cin>>s;
		int k;
		cin>>k;
		get_zigzag_arrangement(s, k);
	}
	return 0;
}