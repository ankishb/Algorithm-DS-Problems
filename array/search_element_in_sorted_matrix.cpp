
// new try
#include <bits/stdc++.h>
using namespace std;
int T[30][30];

bool is_present(int n, int m, int k){
    int i = 0, j = m-1;
    while(i <= n-1 && j >= 0){
        if(T[i][j] == k) return true;
        else if(k < T[i][j]) j--;
        else if(k > T[i][j]) i++;
        else return false;
    }
    return false;
}

int main()
 {
	int test;
	cin>>test;
	while(test--){
	    int n, m;
	    cin>>n>>m;
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            cin>>T[i][j];
	        }
	    }
	    int target;
	    cin>>target;
	    cout<<is_present(n, m, target)<<endl;
	}
	return 0;
}



// old one
// Expected Time Complexity : O(m + n)

#include <bits/stdc++.h>
using namespace std;
#define max_ 105
int T[max_][max_];

void search_element(){
	int n, m;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>T[i][j];
		}
	}
	int ele;
	cin>>ele;

	// start with top right element, we can also start with bottom left corner.
	int i=0, j=m-1;
	bool found_flag = false;
	while(i<n && j>=0){
		if(T[i][j] == ele){
			cout<<"Found element"<<endl;
			found_flag = true;
			break;
		}
		if(T[i][j] < ele){
			i++;
			// i = min(i, n-1);
		}
		else if(T[i][j] > ele){
			j--;
			// j = max(0, j);
		}
		// else{
		// 	break;
		// }
	}
	if(!found_flag){
		cout<<"Not found"<<endl;
	}
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		search_element();
	}
	return 0;
}

