/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    unordered_map<int, int> map;
    unordered_set<int> vis;
    
    int getImportance(vector<Employee*> emp, int id) {
        for(int i=0; i<emp.size(); i++){
            map[emp[i]->id] = i;
        }
        queue<int> q;
        q.push(id);
        int imp = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            if(vis.find(front) != vis.end()) continue;
            vis.insert(front);
            int idx = map[front];
            imp += emp[idx]->importance;
            
            for(auto sub_e : emp[idx]->subordinates){
                if(vis.find(sub_e) == vis.end()){
                    q.push(sub_e);
                }
            }
        }
        return imp;
    }
};