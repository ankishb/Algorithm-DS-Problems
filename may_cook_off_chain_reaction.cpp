// https://www.codechef.com/COOK106B/problems/REACTION

#include <bits/stdc++.h>
using namespace std;
int T[11][11];



bool check_if_stable(int m, int n){
	// cout<<endl<<"================="<<endl;
	// for(int i=0; i<m; i++){
	// 	for(int j=0; j<n; j++){
	// 		cout<<T[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<"================="<<endl;
	// cout<<m<<" "<<n<<endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(i==0 && j==0){
				if(T[i][j] > 1){
					// cout<<i<<" "<<j<<" "<<T[i][j]<<" Eliminated by 1 Ist \n";
					return false;
				}
			}
			else if(i==0 && j==n-1){
				if(T[i][j] > 1){
					// cout<<i<<" "<<j<<" "<<T[i][j]<<" Eliminated by 2 Ist \n";
					return false;
				}
			}
			else if(i==m-1 && j==0){
				if(T[i][j] > 1){
					// cout<<i<<" "<<j<<" "<<T[i][j]<<" Eliminated by 3 Ist \n";
					return false;
				}
			}
			else if(i==m-1 && j==n-1){
				if(T[i][j] > 1){
					// cout<<i<<" "<<j<<" "<<T[i][j]<<" Eliminated by 4 Ist \n";
					return false;
				}
			}
			else if(i==0 || j==0 || i==m-1 || j==n-1){
				if(T[i][j] > 2){
					// cout<<i<<" "<<j<<" "<<T[i][j]<<" Eliminated by 2nd \n";
					return false;
				}
			}
			else {
				if(T[i][j] > 3){
					// cout<<i<<" "<<j<<" "<<T[i][j]<<" Eliminated by 3rd \n";
					return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	int test;
	cin>>test;

	while(test--){
		int m, n;
		cin>>m>>n;

		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				cin>>T[i][j];
			}
		}
		if(check_if_stable(m, n)){
			cout<<"Stable\n";
		}
		else{
			cout<<"Unstable\n";
		}
	}
	return 0;
}