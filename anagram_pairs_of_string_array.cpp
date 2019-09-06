vector<vector<int> > solAnagrams1(const vector<string> &A) {
    int n = A.size();
    vector<vector<int>> ans;
    if(n == 0) return ans;
    unordered_map<string, vector<int>> myMap;
    string s;
    for(int i=0; i<n; i++){
        s = A[i];
        sort(s.begin(), s.end());
        myMap[s].push_back(i+1);
    }
    for(int i=0; i<n; i++){
        s = A[i];
        sort(s.begin(), s.end());
        if(myMap.find(s) != myMap.end()){
            ans.push_back(myMap[s]);
            myMap.erase(s);
        }
    }
    return ans;
}

/*
it reduce the time complexity, look at for loop in above program
It use sorting a string twice, in the following program, we saved it.
*/
vector<vector<int> > solAnagrams2(const vector<string> &A) {
    int n = A.size();
    vector<vector<int>> ans;
    if(n == 0) return ans;
    vector<int> tempAns[n];
    unordered_map<string, int> myMap;
    string s;
    int idx, count=0;
    for(int i=0; i<n; i++){
        s = A[i];
        sort(s.begin(), s.end());
        if(myMap.find(s) != myMap.end()){
            idx = myMap[s];
            tempAns[idx].push_back(i+1);
        }
        else{
            tempAns[count].push_back({i+1});
            myMap[s] = count; count++;
        }
    }
    for(int i=0; i<count; i++) ans.push_back(tempAns[i]);
    return ans;
}

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    // return solAnagrams1(A);
    return solAnagrams2(A);
}





///////////////////////
///////////////////////
///////////////////////
vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    vector<vector<int> > sol;
    unordered_map<string, vector<int> > myMap;
    string temp;
    for(int i = 0; i < A.size(); i++){
        temp = A[i];
        sort(temp.begin(),temp.end());
        myMap[temp].push_back(i+1);
    }
    
    auto it = myMap.begin();
    
    while(it != myMap.end()){
        sol.push_back(it->second);
        it++;
    }

    return sol;
}




///////////////////////
///////////////////////
///////////////////////
///////////////////////
///////////////////////
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

void anagramic_pair(vector<string> &A){
	vector<vector<int> > ans;
	unordered_map<string, vector<int> > map_;
	for(int i=0; i<A.size(); i++){
		string temp = A[i];
		sort(temp.begin(), temp.end());
		map_[temp].push_back(i+1);
	}

	for(auto it=map_.begin(); it!=map_.end(); ++it){
		// cout<<endl<<(*it).first<<" -> ";
		cout<<endl<<it->first<<" -> ";
		for(auto it2 = ((*it).second).begin(); it2!=((*it).second).end+(); ++it2)
		cout<<*it2<<" ";
		// ans[it.second] = it.first;
		// ans.push_back(it->second);
	}
	// return ans;
}

int main()
{
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
		int n;
		cin>>n;
		string s;
		vector<string> vect;
		while(n--){
			cin>>s;
			vect.push_back(s);
		}
		anagramic_pair(vect);
	}
	return 0;
}