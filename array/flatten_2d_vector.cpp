#include <bits/stdc++.h>
using namespace std;

class solution{
public:
    vector<vector<int>> A;
    int ri; // row idx
    int idx; // idx in a row
    solution(vector<vector<int>> A_){
        A = A_;
        ri = 0;
        idx = -1;
        // print();
    }
    void print(){
        cout<<"----------------";
        for(auto v : A){
            for(auto el : v){
                cout<<el<<" ";
            }
            cout<<endl;
        }
        cout<<"----------------";
    }
    
    int get_next(){
        if(has_next()) return A[ri][idx];
        else return -1;
    }
    
    bool has_next(){
        // cout<<ri<<" -- "<<idx<<" "<<A[ri].size()<<endl;
        if(ri >= A.size()) return false;
        idx++;
        if(A[ri].size() == 0 || A[ri].size() <= idx){
            // cout<<" --entered-- ";
            while(A[ri].size() == 0 || idx >= A[ri].size()){
                ri++;
                if(ri >= A.size()) return false;
            }
            idx = 0;
        }
        
        return true;
    }
};

int main()
{
    vector<vector<int>> v = {{},{},{1},{2,3}};
    solution sol1(v);
    for(int i=0; i<10; i++){
        cout<<sol1.get_next()<<" ";
    }
    cout<<endl;
    vector<vector<int>> v2 = {{},{},{},{}};
    solution sol2(v2);
    for(int i=0; i<10; i++){
        cout<<sol2.get_next()<<" ";
    }
    cout<<endl;
    vector<vector<int>> v3 = {{1},{2,3},{4,5,6}};
    solution sol3(v3);
    for(int i=0; i<10; i++){
        cout<<sol3.get_next()<<" ";
    }
    
    return 0;
}