
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, query, value;
    cin>>n;
    stack<long> s, m;
    for(int i=0; i<n; i++){
        cin>>query;
        if(query == 1){
            cin>>value;
            s.push(value);
            if(m.empty() || m.top() <= value){
                m.push(value);
            }
        }
        else if(query == 2){
            if(s.top() == m.top()) m.pop();
            s.pop();
        }
        else{
            cout<<m.top()<<endl;
        }
    }
    return 0;
}