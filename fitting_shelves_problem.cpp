
#include <bits/stdc++.h>
using namespace std;

void fit_shelves(){
	int wall, shelf1, shelf2;
	cin>>wall>>shelf1>>shelf2;
	bool break_loop = false;

	int shelf1_c=0, shelf2_c=0, rem;
	while(!break_loop){
		if(shelf1_c == wall/shelf1){
			break_loop = true;
		}
		rem = wall - (shelf1_c*shelf1 + shelf2_c*shelf2);
		if(rem == 0){
			cout<<shelf1_c<<" "<<shelf2_c<<endl;
			break_loop = true;
		}
	}
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		fit_shelves();
	}
	return 0;
}