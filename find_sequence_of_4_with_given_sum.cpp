

#include <bits/stdc++.h>
using namespace std;

void find_seq_of_4(vector<int> &A, int B){
	unordered_multimap<int, pair<int, int> > my_map;
	int n = A.size();
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			// cout<<A[i]+A[j]<<" ";
			my_map.insert({A[i]+A[j], make_pair(i, j)});
		}
	}
	// cout<<"\n check all value with key=0 \n";
	// for(auto itr=my_map.begin(); itr!=my_map.end(); ++itr){
	// 	if(itr->first == 0){
	// 		cout<<itr->first<<" : "<<(itr->second).first<<" "<<(itr->second).second<<endl;
	// 	}
	// }
		
	set<vector<int> > ans;
	vector<int> temp;
	int sum1, sum2;
	bool check;
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			sum1 = A[i]+A[j];
			sum2 = B-sum1;
			
			check = false;
			for(auto itr=my_map.begin(); itr!=my_map.end(); ++itr){
				if(itr->first == sum2){
					if(((itr->second).first != i && (itr->second).first != j) && ((itr->second).second != i && (itr->second).second != j)){
						vector<int> temp{A[i], A[j], A[(itr->second).first], A[(itr->second).second]};
						sort(temp.begin(), temp.end());
						ans.insert(temp);
						check = true;
					}
				}
			}
			if(check == false){
				my_map.insert({sum1, make_pair(i, j)});
			}
		}
	}
	vector<vector<int> > sol;
	// set<vector<int> >::iterator itr;
	// vector<int>::iterator itr2;
	
	cout<<"\n final solution \n";
	// for(itr=ans.begin(); itr!=ans.end(); ++itr){
	// 	// sol.push_back(itr);
	// 	for(itr2=*itr.begin(); itr2!=*itr.end(); ++itr2){
	// 		cout<<*itr2<<" ";
	// 	}
	// 	cout<<endl;
	// }
	for(auto itr : ans){
		sol.push_back(itr);
		for(auto itr2 : itr){
			cout<<itr2<<" ";
		}
		cout<<endl;
	}
}

// // vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
// void find_seq_of_4(vector<int> &A, int B){
//     unordered_map<int, pair<int, int> > my_map;
//     unordered_map<int, pair<int, int> >::iterator itr;
//     // set<vector<int> > ans;
//     vector<vector<int> > ans;
//     int sum = 0;
//     for(int i=0; i<A.size(); i++){
//         for(int j=i+1; j<A.size(); j++){
//             sum = A[i]+A[j];
//             int tp_ = B-sum;
//             itr = my_map.find(tp_);
//             if(itr != my_map.end()){
//             	pair<int, int> p = itr->second;
//                 if(((p.first != i) && (p.first != j)) && 
//                     ((p.second != i) && (p.second != j))){
//                     vector<int> tup{i, j, p.first, p.second};
//                     ans.push_back(tup);
//                 }
//             }
//             else{
//                 my_map.insert({sum, make_pair(i, j)});
//             }
//         }
//     }

//     for(int i=0; i<ans.size(); i++){
//         for(int j=0; j<ans[i].size(); j++){
//             ans[i][j] = A[ans[i][j]];
//         }
//     }

//     for(int i=0; i<ans.size(); i++){
//         sort(ans[i].begin(), ans[i].end());
//     }
//     sort(ans.begin(), ans.end());
//     ans.erase(unique(ans.begin(), ans.end()), ans.end());

//     cout<<"\n seq of 4 \n";
//     for(int i=0; i<ans.size(); i++){
//         for(int j=0; j<ans[i].size(); j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     // return ans;
// }


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
		int sum;
		cin>>sum;
		find_seq_of_4(vect, sum);
	}
	return 0;
}





//editorial
vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    int i,j,k,l;
    int n=A.size();
    sort(A.begin(),A.end());
    
    vector<vector<int>> ans;
    for(i=0;i<n;i++){
        if(i>0&&A[i-1]==A[i])continue;
        vector<int> temp;
        temp.push_back(A[i]);
        for(j=i+1;j<n;j++){
            if(j>i+1&&A[j-1]==A[j])continue;
            temp.push_back(A[j]);
            k=j+1;
            l=n-1;
            int tar=B-A[i]-A[j];
            while(k<l){
                int sum=A[k]+A[l];
                if(sum==tar){
                    temp.push_back(A[k]);
                    temp.push_back(A[l]);
                    ans.push_back(temp);
                    temp.pop_back();
                    temp.pop_back();
                    //break;
                }
                if(sum<tar){
                    do{
                        k++;
                    }while(A[k]==A[k-1]&&k<l);
                }
                else{
                    do{
                        l--;
                    }while(A[l]==A[l+1]&&k<l);
                } 
            }
            temp.pop_back();
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
    
}



// fastest
vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    vector<vector <int>> res;
    vector<int>p;
    p.resize(4);
    for(int i=0;i<A.size()-3;i++){
        if(i>0 && A[i]==A[i-1]) continue;
        for(int j=i+1;j<A.size()-2;j++){
            if(j>i+1 && A[j]==A[j-1]) continue;
           // if(A[j]==A[j+1]) continue;
            int target=B-A[i]-A[j];
            p[0]=A[i];
            p[1]=A[j];
            
            int k=j+1;
            int q=A.size()-1;
            while(k<q){
                
                int sum=A[k]+A[q];
                if(sum==target){
                    p[2]=A[k];
                    p[3]=A[q];
                    res.push_back(p);
                    while(p[2]==A[k] && k<q) k++;
                   // while(p[3]==A[q] && q>k) q--;
                }
                else if(sum<target) k++;
                else     q--;
                
            }
        }
    }
    return res;
}