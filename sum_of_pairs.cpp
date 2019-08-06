
#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

void find_pairs_with_sum(vector<int> &A, int B){
    unordered_map<int, int> my_map;
    unordered_map<int, int>::iterator itr;
    int sum = 0;

    vector<int> ans;
    for(int i=0; i<A.size(); i++){
        sum = B - A[i];
        cout<<sum<<"----";
        itr = my_map.find(sum);

        if(sum>0 && itr!=my_map.end()){
            cout<<"found element"<<endl;
            // cout<<itr->first<<"---"<<itr->second<<"=="<<i+1<<endl;
            ans.push_back(itr->second);
            ans.push_back(i+1);
            break;
        }
        else if(itr == my_map.end()){
            // cout<<itr->first<<" "<<itr->second<<" "<<i<<endl;
            my_map[A[i]] = i+1;
        }
    }
}

int main()
 {
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
	    int n;
	    cin>>n;
        int el;
        vector<int> vect;
        for(int i=0; i<n; i++){
            cin>>el;
            vect.push_back(el);
        }
        int sum;
        cin>>sum;
	    find_pairs_with_sum(vect, sum);
	}
	return 0;
}
