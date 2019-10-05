#include <bits/stdc++.h>
string Solution::fractionToDecimal(int num_, int den_) {
// string get_fraction(int num, int den){
    map<int, int> my_map;
    int rem;
    long long num = num_;
    long long den = den_;
    long long int temp;
    if(den == 0){
        return "";
    }
    
    if( num == -2147483648 && den == -1){
        return "2147483648";
    }

    int sign;
    if(num<0 && den<0){
        sign = 1;
    }
    else if(num<0 || den<0){
        sign = -1;
    }
    
    if(num==0){
        sign = 1;
    }

    // cout<<sign<<"--"<<endl;
    num = abs(num); 
    den = abs(den); 

    temp = num/den;
    rem = num%den;
    // cout<<temp<<"--"<<endl;
    string ans = "";
    if(sign == -1){
        ans = ans+"-";
    }
    ans = ans + to_string(temp);
    if(rem == 0){
        return ans;
    }
    
    ans += ".";
    string ans2 = "";
    bool break_flag = false;
    int cur_dec = 0;
    int decimal = 0;
    my_map[rem] = ans2.length();
    while(rem != 0 && break_flag==false){
        rem = rem*10;
        cur_dec = rem/den;
        ans2 = ans2 + to_string(cur_dec);
        rem = rem%den;
        if(my_map.find(rem) != my_map.end()){
            break_flag = true;
            break;
        }
        // decimal = decimal*10 + cur_dec;
        my_map[rem] = ans2.length();
    }
    
    if(break_flag){
        ans = ans + "(" + ans2 + ")";
    }
    else{
        ans = ans + ans2;
    }
    return ans;
}







#include <bits/stdc++.h>
using namespace std;

// Worst case:
// 	-1
// 	-2147483648
// ans:  0.0000000004656612873077392578125

string get_fraction(int num_, int den_){
	map<int, int> my_map;
	long long int rem;
	long long int num = num_;
	long long int den = den_;
	if(den == 0){
		return "NOT_POSSIBLE";
	}
	int sign;
	if((den<0 && num<0) || (num==0)){
		sign = 1;
	}
	else if(den<0 || num<0){
		sign = -1;
	}
	
    num = abs(num); 
    den = abs(den); 

	rem = num%den;
	num = num/den;
	
	string ans = "";
	if(sign == -1){
		ans = ans+"-";
	}
	ans = ans + to_string(num);
	if(rem == 0){
		return ans;
	}

	ans += ".";
	string ans2 = "";
	bool break_flag = false;
	int cur_dec = 0;
	my_map[rem] = ans2.length();
	while(rem != 0 && break_flag==false){
		rem = rem*10;
		cur_dec = rem/den;
		ans2 = ans2 + to_string(cur_dec);
		rem = rem%den;
		if(my_map.find(rem) != my_map.end()){
			break_flag = true;
			break;
		}
		my_map[rem] = ans2.length();
	}
	
	if(break_flag){
		ans = ans + "(" + ans2 + ")";
	}
	else{
		ans = ans + ans2;
	}
	return ans;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int num, den;
		cin>>num>>den;
		cout<<get_fraction(num, den)<<endl;
	}
	return 0;
}




int Solution::lengthOfLongestSubstring(string A) {
	unordered_map<char,int> m;
	int start=0,end=0,len=0;
	while(end<A.size()){
		// Repeating character found at index end. Move start of window ahead
		if(m.count(A[end])&&m[A[end]]>=start){
			start=m[A[end]]+1;
		}
		// Current window length
		if(len<end-start+1){
			len=end-start+1;
		}
		m[A[end]]=end;
		end++;
	}
	return len;
}





int max(int a,int b)
{
    return a>b?a:b;
}
int Solution::lengthOfLongestSubstring(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    bool exist[256] = {false};
    int i=0,j=0;
    int maxlen=0;
    while(j<A.size())
    {
        if(exist[A[j]])
        {
            maxlen = max(maxlen,j-i);
            while(A[i]!=A[j])
            {
                exist[A[i]]=false;
                i++;
            }
            i++;
            j++;
        }
        else
        {
            exist[A[j]] = true;
            j++;
        }
    }
    maxlen = max(maxlen,A.size()-i);
    return maxlen;
}

