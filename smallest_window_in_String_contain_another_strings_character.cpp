// Given a string S and text T. Output the smallest window in the string S having all characters of the text T. Both the string S and text T contains lowercase english alphabets. 

#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

struct temp{
	int start;
	int end;
	int length;
};

bool compare(temp const &A, temp const &B){
	return A.length < B.length;
}


void solve(){
	string inp, test;
	getline(cin, inp);
	getline(cin, test);

	cout<<"Input: "<<inp<<endl;
	cout<<"test:  "<<test<<endl;

	int n1 = inp.length();
	int n2 = test.length();
	int hash[26] = {0};
	for(int i=0; i<n2; i++){
		hash[test[i]-'a']++;
	}
	int i=0, j=0, count=0;
	// multimap<char, int> my_map;
	unordered_map<char, int> my_map;
	unordered_map<char, int>::iterator itr;
	bool first_el = false;
	while(!first_el){
		if((hash[inp[i]-'a']) > 0){
			my_map[inp[i]] = i;
			first_el = true;
			hash[inp[i]-'a']--;
			count++;
		}
		else{
			i++;
		}
	}
	j = i+1;

	priority_queue<temp, vector<temp>, compare> pq;

	while(i<n1){
		if(count == n2){
			pq.push(temp(i, j, j-i+1));
			itr = my_map.begin();
			char c_ = itr->first;
			hash[c_ - 'a']++;
			my_map.erase(itr);
			i++;
			count--;
		}
		else if(hash[inp[j]-'a'] > 0 && j<n1){
			my_map[inp[j]] = j;
			hash[inp[j]-'a']--;
			count++;
		}
		else if(j==n1){
			i++;
		}
		else{
			j++;
		}
	}
}

int main()
 {
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
	    solve();
	}
	return 0;
}

