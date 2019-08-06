
#include <bits/stdc++.h>
using namespace std;



int solve(vector<int> &A, int B, int C) {
	int dup = C;
	vector<int> digits;
	int n = 0;
	while(dup!=0){
		digits.push_back(dup%10);
		dup = dup/10;
		n++;
	}

	// when digit_length is < sum, then include every possible digit, lets len = 1, sum =21, then include all digit
	// when len>1, then exclude 0 as the front digit, for exp, len=2, _ _, digits are {0,1,2}, sum 31, so ans : {20, 23, 30, 31}, with o at front, it will be {01, 02}, which is single digit number.
	if(n > B){
		all_possible_digit();
	}
	else if(n < B){
		for(int i=0; i<n-B; i++){
			digit[i] = 0;
		}
		find_ans();
	}


	for(int i=n-1; i>=0; i--){


	}


	int arr[A.size()] = {0};

}


int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> vect(n);
		for(int i=0; i<n; i++){
			cin>>vect[i];
		}
		int digit_len, sum;
		cin>>digit_len>>sum;
		cout<<solve(vect, digit_len, sum)<<endl;
	}
	return 0;
}








int solve_b(vector<int> &A, int B, int C, bool first_digit=false) {
    
    if (C <= 0 || B <= 0 || A.size() == 0)
        return 0;
    
    string rep = to_string(C);
    int max_number = rep.at(0) - '0';
    
    if(B < rep.size()){
        if(A.front() == 0 && B > 1)
            return (A.size() - 1) * pow( A.size(), B-1 );
        else
            return pow( A.size() , B);
    }
    else if (B > rep.size())
        return 0;
    else{
        int count = 0;
        
        for(auto a : A){
            
            if(a == 0 && first_digit && rep.size() > 1) continue;
            
            if(a < max_number){
                count += pow( A.size(), rep.size() - 1);
            }
            else if(a == max_number){
                if(rep.size() == 1) continue;
                
                int new_c = stoi(rep.substr(1));
                
                if(A.front() != 0){
                    count += solve_b(A, B-1, new_c, false);
                }else{
                    count += solve_b(A, to_string(new_c).size(), new_c, false);
                }
                
            }
        }
        
        return count;
    }
}

int Solution::solve(vector<int> &A, int B, int C) {
    return solve_b(A, B, C, true);
}