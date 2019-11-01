/*
We have a formula to that,
    Area = inside_pts - pts_on_edges/2 + 1

    To find integral points on edges, we have three cases to consider
    1. when line is ||el to x-axis, ans would be abs(y1 - y2)-1
    2. when line is ||el to y-axis, ans would be abs(x1 - x2)-1
    3. otherwise, ans would be gcd(abs(x1-x2), abs(y1-y2))-1

    Area: abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2
*/
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vii vector<vector<int>>
#define f first
#define s second
#define ll long long int 

// creat a signature function here
int gcd(int x, int y){
    if(x > y) swap(x, y);
    if(x == 0) return y;
    return gcd(x, y%x);
}
// integral_pt_on_edges
int helper(int x1, int y1, int x2, int y2){
    if(x1 == x2) return abs(y1 - y2)-1;
    if(y1 == y2) return abs(x1 - x2)-1;
    return gcd(abs(x1-x2), abs(y1-y2))-1;
}

// area = inside + on-edge/2 - 1
int get_integral_point(int x1, int y1, int x2, int y2, int x3, int y3){
    int area, ed;
    area = abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2;
    ed = 3+helper(x1,y1,x2,y2) + helper(x2,y2,x3,y3) + helper(x1,y1,x3,y3);
    
    return (area - ed/2 + 1);
}

int main()
 {
	int test;
	cin>>test;
	while(test--){
	    // input and call signature function
	    int x1, y1, x2, y2, x3, y3;
	    cin>>x1>>y1>>x2>>y2>>x3>>y3;
	    cout<<get_integral_point(x1, y1, x2, y2, x3, y3)<<endl;
	}
	return 0;
}