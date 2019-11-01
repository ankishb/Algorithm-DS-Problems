// new one
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vii vector<vector<int>>
#define f first
#define s second
#define ll long long int 

// creat a signature function here

bool is_op(char ch){
    return (ch=='+' || ch=='-' || ch=='('
    || ch=='*' || ch=='/' || ch=='^');
}
bool is_digit(char ch){
    return (ch >= '0' && ch <= '9');
}

string postfix_expression(string s){
    int n = s.length(), i = 0;
    unordered_map<char, int> map;
    map['('] = 6;
    map['^'] = 5;
    map['*'] = 4;
    map['/'] = 4;
    map['+'] = 2;
    map['-'] = 2;
    stack<char> ops;
    string ans = "";
    while(i < n){
        if(s[i] == ' '){ }
        else if(s[i] == ')'){
            while(!ops.empty() && ops.top() != '('){
                ans += ops.top();
                ops.pop();
            }
            if(!ops.empty() && ops.top() == '(') ops.pop();
        }
        else if(is_op(s[i])){
            while(!ops.empty() && ops.top() != '(' 
            && map[ops.top()] >= map[s[i]]){
                ans += ops.top();
                ops.pop();
            }
            ops.push(s[i]);
        }
        else{
            ans += s[i];
        }
        i++;
    }
    while(!ops.empty()){
        ans += ops.top();
        ops.pop();
    }
    return ans;
}


int main()
 {
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
	    // input and call signature function
    	string s;
    	getline(cin, s);
    	cout<<postfix_expression(s)<<endl;
	}
	return 0;
}







// old one
#include <bits/stdc++.h>
using namespace std;


string get_postfix(string s){
    unordered_map<char,int> map;
    map['('] = 6;
    map['^'] = 5;
    map['*'] = 4;
    map['/'] = 4;
    map['+'] = 2;
    map['-'] = 2;
    int n = s.length(), i = 0;
    stack<char> chars, ops;
    while(i < n){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            chars.push(s[i]);
        }
        else if(s[i] == '(') ops.push('(');
        else if(s[i] == ')'){
            while(!ops.empty() && ops.top() != '('){
                chars.push(ops.top());
                ops.pop();
            }
            if(!ops.empty() && ops.top() == '(') ops.pop();
            
        }
        else if(!ops.empty() && ops.top() != '('){
            if(map[s[i]] > map[ops.top()]) ops.push(s[i]);
            else{
                while(!ops.empty() && ops.top() != '(' 
                && map[s[i]] <= map[ops.top()]){
                    chars.push(ops.top());
                    ops.pop();
                }
                ops.push(s[i]);
            }
        }
        else ops.push(s[i]);
        i++;
    }
    while(!ops.empty()){
        chars.push(ops.top());
        ops.pop();
    }
    string ans = "";
    while(!chars.empty()){
        ans += chars.top();
        chars.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
 {
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
	    string s;
	    getline(cin,s);
	    cout<<get_postfix(s)<<endl;
	}
	return 0;
}
