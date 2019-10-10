// new try
/* 
As we need to find longest pallindrome possible, including first char
1. collect all indices of s[0] except 0 in a stack
2. now check if s[0-top] is pallindrome
    1. if yes, ans is (n-top-1)
    2. pop an element and check for next index in stack
3. If we didn't get ans yet, it will be (n-1)

Note: worst case is O(n^2). For example: "aaaaa"
*/
int Solution::solve(string s){
    int n = s.length();
    if(n < 2) return 0;
    stack<int> st;
    for(int i=1; i<n; i++){
        if(s[i] == s[0]) st.push(i);
    }
    int i, j;
    while(!st.empty()){
        i = 0, j = st.top();
        while(i<j && s[i] == s[j]){
            i++; j--;
        }
        
        if(i >= j) return (n-st.top()-1);
        st.pop();
    }
    return n-1;
}




// old one
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