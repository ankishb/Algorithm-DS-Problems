
#include <bits/stdc++.h>
using namespace std;

void largest_seq_with_0_sum(vector<int> &A){
    unordered_map<int, int> my_map;
    int sum = 0;
    int max_len = 0;
    int max_idx = -1;
    int value;
    for(int i=0; i<A.size(); i++){
        sum = sum+A[i];
        if(sum == 0){
            max_len = i+1;
            max_idx = i;
            value = sum;
        }
        if(my_map.find(sum) != my_map.end()){
            if(i-my_map[sum] > max_len){
                max_len = i-my_map[sum];
                max_idx = i;
                value = sum;
            }
        }
        my_map.insert(make_pair(sum, i));
        // cout<<sum<<"--"<<i<<endl;
    }
    // cout<<"\n mapping element \n";
    // unordered_map<int, int>::iterator itr;
    // for(itr=my_map.begin(); itr!=my_map.end(); ++itr){
    //     cout<<itr->first<<" : "<<itr->second<<endl;
    // }
    // cout<<max_len<<"--"<<max_idx<<endl;
    
    vector<int> ans;
    if(max_idx == -1){
        return ans;
    }
    
    int ending = (value == 0)?max_len:max_len+1;
    for(int i=max_idx+1-max_len; i<ending; i++){
        ans.push_back(A[i]);
    }
    
    cout<<"\n final sequence \n";
    for(int i=0; i<ans.size(); i++){
    	cout<<ans[i]<<" ";
    }
    cout<<endl;
}


int main()
{
	int test;
	cin>>test;
	while(test--){
		int n, el;
		cin>>n;
		vector<int> vect;
		while(n--){
			cin>>el;
			vect.push_back(el);
		}
		largest_seq_with_0_sum(vect);
	}
	return 0;
}