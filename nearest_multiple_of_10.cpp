
#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

void nearest_multiple_of_10(){
	string s;
	getline(cin, s);
// 	cout<<s<<endl;
	int i=0;
	bool break_flag = false;
	bool carry_flag = false;
	int n = s.length();
	if(s[n-1] >= '6'){
		carry_flag = true;
		s[n-1] = '0';
		i--;
// 		cout<<"found carry---\n";
	}
	else{
		s[n-1] = '0';
		break_flag = true;
	}
	while((i>=0 || carry_flag==true) && (break_flag==false)){
		if(s[i] == '9'){
			s[i] = '0';
			i--;
		}
		else{
			// int tp = s[i];
			// s[i] = tp+1;
			// s[i] = static_cast<char>(s[i] + 1);
			
// 			cout<<s[i]<<" ";
			s[i] = s[i]++;
// 			cout<<s[i]<<endl;
			carry_flag = false;
		}

	}
	cout<<carry_flag<<endl;
	if(carry_flag == true){
		cout<<'1'<<s<<endl;
	}
	else{
		cout<<s<<endl;
	}
}

int main()
 {
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
		nearest_multiple_of_10();
	}
	return 0;
}