
#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

void solve(){
	int num;
	int den;
	cin>>num>>den;
	int ans = 0;
	ans = num/den;
	num = num%den;
	string ans_ = to_string(ans);
	bool break_flag = false;
	if(num == 0){
	    break_flag = true;
	}
	else{
	    ans_ = ans_ + '.';
	}
	while(!break_flag){
		if(num == num*10%den){
			ans_ = ans_+'('+to_string(int(num*10 /den))+')';
			break_flag = true;
		}
		else{
			ans_ = ans_ + to_string(int(num*10 / den));
			num = num*10 % den;
		}
	}
	cout<<ans_<<endl;
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