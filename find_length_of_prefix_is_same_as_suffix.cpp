
#include <bits/stdc++.h>
using namespace std;

void prefix_suffix_length(string A){
	string str = A;
	reverse(str.begin(), str.end());
	str = A+'$'+str;
	// cout<<str<<endl;
	int arr[str.length()] = {0};
	int j=0, i=1;
	while(i<=str.length()-1){
		if(str[i] == str[j]){
			arr[i] = j+1;
			i++;
			j++;
		}
		else if(str[i-1] == str[j-1]){
			// if prev character are same and look back for the prefix
			j = arr[j-1];
		}
		else{
			i++;
		}
	}

	cout<<A.length()-arr[str.length()-1];
	// cout<<"\n ---- pattern matching array ----\n";
	// for(int i=0; i<str.length(); i++){
	// 	cout<<arr[i]<<" ";
	// }
	cout<<endl;
}

int main()
{
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
		string str;
		getline(cin, str);
		prefix_suffix_length(str);
	}
	return 0;
}