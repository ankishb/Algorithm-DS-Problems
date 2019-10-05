
// new one
string Solution::convert(string s, int k) {
    int n = s.length();
    if(k == 1 || n <= 1) return s; 
    vector<string> store;
    store.resize(k);
    store[0].push_back(s[0]);
    int i = 1;
    while(i < n){
        for(int ii=1; ii<k && i<n; ii++){
            store[ii].push_back(s[i]);
            i++;
        }
        for(int ii=k-2; ii>=0 && i<n; ii--){
            store[ii].push_back(s[i]);
            i++;
        }
    }
    string ans = "";
    for(auto v : store){
        ans += v;
    }
    return ans;
}



// old one
string Solution::convert(string s, int k) {

// void get_zigzag_arrangement(string s, int k){
    if(k==1 || k>=s.length()){
        return s;
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
        return ans;
    }
}






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