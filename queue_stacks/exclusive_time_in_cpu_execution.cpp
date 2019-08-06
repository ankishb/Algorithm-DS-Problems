/*
The idea is simple everytime we see a start, we just push it to the stack. Now when we reach an end, we are guaranteed that the top of the stack is a start with the same id as the current item because all completed start/ends in between this start and end has been removed already. We just add current item timestamp - stack top timestamp + 1 to times[i].

So for example
[..., {0:start:3}] and item = {0:end:6} we add 6 - 3 + 1

However, what if there are function calls in between the start and end of the function of id 0? We can account for this by subtracting the length of the function calls in between the function id 0 whenever we complete an inner function marked by an end.

[..., {0:start:3}, {2:start:4}] and item = {2:end:5} so we increment times[2] by curr_length = 5 - 4 + 1 = 2 and then we subtract times[0] by curr_length as it takes up that amount of time out of the total time

So whenever we see an end, we have to make sure to subtract our curr_length to whatever function is enclosing it if it exists.

The idea is simple everytime we see a start, we just push it to the stack. Now when we reach an end, we are guaranteed that the top of the stack is a start with the same id as the current item because all completed start/ends in between this start and end has been removed already. We just add current item timestamp - stack top timestamp + 1 to times[i].

So for example
[..., {0:start:3}] and item = {0:end:6} we add 6 - 3 + 1

However, what if there are function calls in between the start and end of the function of id 0? We can account for this by subtracting the length of the function calls in between the function id 0 whenever we complete an inner function marked by an end.

[..., {0:start:3}, {2:start:4}] and item = {2:end:5} so we increment times[2] by curr_length = 5 - 4 + 1 = 2 and then we subtract times[0] by curr_length as it takes up that amount of time out of the total time

So whenever we see an end, we have to make sure to subtract our curr_length to whatever function is enclosing it if it exists.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cassert>

using namespace std;

struct Log {
    int id;
    string status;
    int timestamp;
};

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> times(n, 0);
        stack<Log> st;
        for(string log: logs) {
            stringstream ss(log);
            string temp, temp2, temp3;
            getline(ss, temp, ':');
            getline(ss, temp2, ':');
            getline(ss, temp3, ':');

            Log item = {stoi(temp), temp2, stoi(temp3)};
            if(item.status == "start") {
                st.push(item);
            } else {
                assert(st.top().id == item.id);

                int time_added = item.timestamp - st.top().timestamp + 1;
                times[item.id] += time_added;
                st.pop();

                if(!st.empty()) {
                    assert(st.top().status == "start");
                    times[st.top().id] -= time_added;
                }
            }
        }

        return times;
    }
};








// mine
int get_integer(string s){
    int ans = 0;
    for(int i=0; i<s.length(); i++){
        ans = ans*10 + (s[i]-'0');
    }
    return ans;
}

class custom{
public:
    int id;
    string log_name;
    int time;
    custom(string log){
        vector<string> str;
        string temp = "";
        for(int i=0; i<=log.length(); i++){
            if(i== log.length() || log[i] == ':'){
                str.push_back(temp);
                temp = "";
            }
            else{ temp += log[i]; }
        }
        log_name = str[1];
        id = get_integer(str[0]);
        time = get_integer(str[2]);
    }
};


class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<custom> log_file;
        vector<int> ans(101, 0);
        int max_id = INT_MIN;
        int last = 0;
        for(int i=0; i<logs.size(); i++){
            custom cur(logs[i]);
            max_id = max(max_id, cur.id);
            int time_added;
            if(cur.log_name == "start"){
                log_file.push(cur);
            }
            else{                
                custom prev = log_file.top();
                if(prev.log_name == "start" && cur.log_name == "end"){
                    log_file.pop();
                    cout<<cur.time<<" "<<prev.time<<endl;
                    time_added = (cur.time - prev.time) + 1 ;
                    ans[cur.id] += time_added;
                }
                if(!log_file.empty()) {
                    custom prev = log_file.top();
                    assert(prev.log_name == "start");
                    ans[prev.id] -= time_added;
                }
            }
        }
        vector<int> final_ans;
        for(int i=0; i<=max_id; i++){
            final_ans.push_back(ans[i]);
        }
        ans.clear();
        for(auto itr : final_ans){
            cout<<itr<<" ";
        }
        return final_ans;
    }
};