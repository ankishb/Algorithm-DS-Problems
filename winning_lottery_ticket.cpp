/*
Approach:
To find pair, we need some strategy, to avoid runtime error, which is as follows:
1. Create a vector of frequency of bits_mask vector, then compute pair relation, it will be 1024*1024, which is significantly smaller than n^2
2. handle special case, of 1023, because, this can also make pair with itself.
*/

#include <bits/stdc++.h>
using namespace std;


int get_num(vector<int> hash){
    int ans = 0;
    int twos = 1;
    for(int i=9; i>=0; i--){
        ans += hash[i]*twos;
        twos *= 2;
    }
    return ans;
}

long winningLotteryTicket(vector<int> bits_mask) {
    int n = bits_mask.size();
    
    long count = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if((bits_mask[i]|bits_mask[j]) == 1023){
                // cout<<bits_mask[i]<<" : "<<bits_mask[j]<<" "<<(bits_mask[i]|bits_mask[j])<<endl;
                count++;
            }
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> bits_mask(n);
    long no;

    for (int i = 0; i < n; i++) {
        string tickets_item;
        getline(cin, tickets_item);
        vector<int> hash(10, 0);
        for(int j=0; j<tickets_item.length(); j++){
            hash[(tickets_item[j]-'0')] = 1;
        }
        no = get_num(hash);
        bits_mask[i] = no;
    }

    long result = winningLotteryTicket(bits_mask);
    fout << result << "\n";
    fout.close();
    return 0;
}




int sansaXor(vector<int> arr) {
	int ans = 0;
	int n = arr.size();
	for(int i=0; i<n; i++){
		if((n-i)%2 == 1){
			ans = ans^arr[i];
		}
	}
	return ans;
}