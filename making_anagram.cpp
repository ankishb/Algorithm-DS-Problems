
// find how many delete operation needed to make both string as anagram of each other.
// anagram: abc --> acb, bac, etc.

#include <bits/stdc++.h>
using namespace std;

void making_anagram(){
	string s1, s2;
	cin>>s1>>s2;

	int hash1[27] = {0};
	int hash2[27] = {0};
	for(int i=0; i<s1.length(); i++){
		hash1[s1[i] - 'a']++;
	}
	for(int i=0; i<s2.length(); i++){
		hash2[s2[i] - 'a']++;
	}

	int delete_op = 0;
	for(int i=0; i<27; i++){
		delete_op += abs(hash1[i] - hash2[i]);
	}
	cout<<delete_op<<endl;
}

void game_of_throne(){
	string s1;
	cin>>s1;

	int hash1[27] = {0};
	for(int i=0; i<s1.length(); i++){
		hash1[s1[i] - 'a']++;
	}

	for(int i=0; i<27; i++){
        if(hash1[i]%2 != 0){
            count++;
            if(count > 1){
                cout<<"NO \n";
            }
        }
    }
	cout<<"YES \n";
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		making_anagram();
	}
	return 0;
}