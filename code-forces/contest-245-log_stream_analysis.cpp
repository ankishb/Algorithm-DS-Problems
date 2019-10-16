#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll get_diff(string s1, string s2){
    int m_days[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    ll add, m1, m2, d1, d2, h1, h2, mn1, mn2, se1, se2;
    
    m1 = stoi(s1.substr(0,2));
    m2 = stoi(s2.substr(0,2));
    add = 0;
    for(int i=m1; i<m2; i++){
        add += m_days[i];
    }
    d1 = stoi(s1.substr(3,2));
    d2 = stoi(s2.substr(3,2)) + add;
    
    h1 = stoi(s1.substr(6,2));
    h2 = stoi(s2.substr(6,2));
    h2 += (d2 - d1)*24;
    
    mn1 = stoi(s1.substr(9,2));
    mn2 = stoi(s2.substr(9,2));
    mn2 += (h2 - h1)*60;
    
    se1 = stoi(s1.substr(12,2));
    se2 = stoi(s2.substr(12,2));
    se2 += (mn2 - mn1)*60;
    
    return (se2 - se1);
}

string find_lag(vector<string> A, int n, int m){
    int nn = A.size();
    deque<ll> dq;
    int count = 1;
    for(int i=0; i<nn; i++){
        if(i == 0){
            dq.push_back(0);
            continue;
        }
        ll s = get_diff(A[i-1], A[i]);
        if(!dq.empty()) s += dq.back();
        while(!dq.empty() && dq.back()-dq.front() >= n){
            dq.pop_front();
            count--;
        }
        dq.push_back(s);
        count++;
        // cout<<i<<" "<<dq.back()<<" "<<count<<" "<<A[i]<<endl;
        if(dq.size() == m) return "2012-"+A[i];
    }
    // while(!dq.empty()){
    //     cout<<dq.front()<<" ";
    //     dq.pop_front();
    // }
    return "-1";
}

int main() {
    int n, m;
    cin>>n>>m;
    cin.ignore(1);
    string s;
    vector<string> A;
    for(int i=0; i<1000000; i++){
        s = "";
        getline(cin, s);
        if(s.length() == 0) break;
        string sub = s.substr(5,14);
        A.push_back(sub);
    }
    // for(auto s : A){
    //     cout<<s<<endl;
    // }
    cout<<find_lag(A, n, m)<<endl;
    // for(int i=1; i<A.size(); i++){
    //     cout<<diff(A[i-1], A[i])<<endl;
    // }
    return 0;
}

/*
2 2
2012-03-16 23:59:59:Disk size is too sm
2012-03-17 00:00:00:Network failute dete
2012-03-17 00:00:01:Cant write varlogmysq

2012-03-17 00:00:00

1 2
2012-03-16 23:59:59:Disk size
2012-03-17 00:00:00: Network
2012-03-17 00:00:01:Cant write varlog

-1

60 3
2012-03-16 16:15:25: Disk size is
2012-03-16 16:15:25: Network failute
2012-03-16 16:16:29: Cant write varlog
2012-03-16 16:16:42: Unable to start process
2012-03-16 16:16:43: Disk size is too small
2012-03-16 16:16:53: Timeout detected

2012-03-16 16:16:43

*/