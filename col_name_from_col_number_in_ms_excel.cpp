// Given a positive integer, return its corresponding column title as appear in an Excel sheet.
// MS Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB ….. etc. In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA”.


#include <bits/stdc++.h>
using namespace std;

void ms_excel(){
	long long int n;
	cin>>n;
	
	vector<int> vect;
	while(n != 0){
	    if(n%26 == 0){
	    	cout<<"-1-";
	        vect.push_back('Z');
	    }
	    else{
	    	cout<<"-2-";
	        vect.push_back((n%26)-1+'A');
	    }
	    if(n==26){
	    	n = 0;
	    }
		n = n/26;
	}
	
	for(int i=vect.size()-1; i>=0; i--){
		cout<<char(vect[i]);
	}
	cout<<endl;
}

void titleTONumber(){
	string A;
	// cin.ignore(1);
	getline(cin, A);
	cout<<A.length()<<"==="<<endl;
	int result = A[A.length()-1]-'A'+1;
	int j=1;
	for(int i=A.length()-2; i>=0; i--){
		// cout<<i<<"--";
		int hash = A[i]-'A';
		// cout<<hash+1<<endl;
		result = result + pow(26, j)*(hash+1);
		j++;
	}
	cout<<result<<endl;
}

int Solution::titleToNumber(string A) {
	long long int count = 0;
	for(int i = 0;i<A.size();i++){
		count+= (((int)(A[i]-‘A’)+1)*pow(26,A.size()-1-i));
	}
	return count;
}


int main()
{
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
		// ms_excel();
		titleTONumber();
	}
	return 0;
}




// ////////////////
// #include<iostream>
// #include<algorithm>
// #include<vector>
// typedef long long int lli;
// using namespace std;
// void col_name(lli n){
//     vector<char> col;
//     while(n){
//         int temp = n % 26;
//         if(temp == 0){
//             col.push_back('Z');
//             n = (n/26)-1;
//         }
//         else{
//             col.push_back((char)(temp-1) + 'A');
//             n /= 26;
//         }
//     }
//     reverse(col.begin(), col.end());
//     for(int i = 0; i < col.size(); i++){
//         cout << col[i];
//     }
//     cout << endl;
// }

// int main(){
//     int t; cin >> t;
//     while(t--){
//         lli n; cin >> n;
//         col_name(n);
//     }
// }