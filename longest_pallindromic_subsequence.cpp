#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

void solve(){
	cin.ignore(1);
	string s;
    cin>>s;
    int n = s.length();
	int T[n][n];
	memset(T, 0, sizeof(T[0][0])*n*n);

	// run outer loop for [n, n-1, n-2, ..., 1]
	for(int i=0; i<n; i++){
		T[i][i] = 1;
	}
	for(int k=1; k<n; k++){
		int i=0;
		int j=0+k;
		while(j!=n){
			// cout<<i<<" "<<j<<endl;
			if(s[i] == s[j]){
				// look on the diagnol left-bottom
				T[i][j] = T[i+1][j-1] + 2;
			}
			else{
				// take maximum from left and bottom
				T[i][j] = max(T[i][j-1], T[i+1][j]);
			}
			i++;
			j++;
		}
		// cout<<"\n ----- \n";
	}
	// cout<<"\n print matrix elements\n";
	// for(int i=0; i<n; i++){
	// 	for(int j=0; j<n; j++){
	// 		cout<<"("<<s[i]<<","<<s[j]<<") "<<T[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	cout<<"Length of longest pallindrome: "<<T[0][n-1]<<endl;
	int i=0;
	int j=n-1;
	vector<char> ans(T[i][j]);
	int left = 0;
	int right = T[i][j]-1;
	bool break_flag = false;
	while(!break_flag){
		cout<<i<<" "<<j<<endl;
		if(T[i][j] == 0){
			break_flag = true;
		}
		else if(T[i][j] == T[i][j-1]){
			j--;
		}
		else if(T[i][j] == T[i+1][j]){
			i++;
		}
		else if(T[i][j] > T[i+1][j-1]){
			ans[left] = s[i];
			ans[right] = s[i];
			left++;
			right--;
			i++;
			j--;
		}
	}
	if(i==j){
		ans[i] = s[i];
	}
	cout<<"\nfinal answer\n";
	for(auto itr : ans){
		cout<<itr<<" ";
	}
	cout<<endl;
	// cout<<T[0][n]<<endl;	
}

int main()
{
	int test;
	cin>>test;
	while(test--){
	    solve();
	}
	return 0;
}