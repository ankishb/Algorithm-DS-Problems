
bool custom_sort(const int &a, const int &b){
	return a > b;
}

class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        int n = tasks.size();
        if(k==0) return n;
        vector<int> count(26, 0);
        for(int i=0; i<n; i++){
        	count[tasks[i]-'A']++;
        }
        sort(count.begin(), count.end(), custom_sort);
        int end;
        for(int i=25; i>=0; i--){
            if(count[i] != 0){
                end = i+1;
                break;
            }
        }
        
        int time = 0, temp_count;
        bool all_zeros, first;
        while(count[0] != 0){
        	temp_count = 0;
            for(int i=0; i<end; i++){
        		if(count[i] != 0){
        			count[i]--;
        			temp_count++;
        		}
                if(temp_count == k+1) break;
        	}
           	
            if(count[0] == 0) time += temp_count;
            else time += k+1;
        	sort(count.begin(), count.end(), custom_sort);
        }
        return time;
    }	
};









The idea is:
0. To work on the same task again, CPU has to wait for time n, therefore we can think of as if there is a cycle, of time n+1, regardless whether you schedule some other task in the cycle or not.

    To avoid leave the CPU with limited choice of tasks and having to sit there cooling down frequently at the end, it is critical the keep the diversity of the task pool for as long as possible.
    In order to do that, we should try to schedule the CPU to always try round robin between the most popular tasks at any time.

priority_queue<task, count>

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for (char t : tasks) {
            counts[t]++;
        }
        priority_queue<pair<int, char>> pq;
        for (pair<char, int> count : counts) {
            pq.push(make_pair(count.second, count.first));
        }
        int alltime = 0;
        int cycle = n + 1;
        while (!pq.empty()) {
            int time = 0;
            vector<pair<int, char>> tmp;
            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    tmp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for (auto t : tmp) {
                if (--t.first) {
                    pq.push(t);
                }
            }
            alltime += !pq.empty() ? cycle : time;
        }
        return alltime;
    }
};

priority_queue<count>
As @milu point out, we don't really need to store <task - count> pair in the priority_queue, we don't need to know the task name, store counts works good enough:

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for (char t : tasks) {
            counts[t]++;
        }
        priority_queue<int> pq;
        for (pair<char, int> count : counts) {
            pq.push(count.second);
        }
        int alltime = 0;
        int cycle = n + 1;
        while (!pq.empty()) {
            int time = 0;
            vector<int> tmp;
            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    tmp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for (int cnt : tmp) {
                if (--cnt) {
                    pq.push(cnt);
                }
            }
            alltime += !pq.empty() ? cycle : time;
        }
        return alltime;
    }
};













/*
This is an excellent approach to this problem.
    1. First count the number of occurrences of each element.
    2. Let the max frequency seen be M for element E
    3. We can schedule the first M-1 occurrences of E, each E will be followed by at least N CPU cycles in between successive schedules of E
    4. Total CPU cycles after scheduling M-1 occurrences of E = (M-1) * (N + 1) // 1 comes for the CPU cycle for E itself
    5. Now schedule the final round of tasks. We will need at least 1 CPU cycle of the last occurrence of E. If there are multiple tasks with frequency M, they will all need 1 more cycle.
    6. Run through the frequency dictionary and for every element which has frequency == M, add 1 cycle to result.
    7. If we have more number of tasks than the max slots we need as computed above we will return the length of the tasks array as we need at least those many CPU cycles.
*/


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        int count = 0;
        for(auto e : tasks)
        {
            mp[e]++;
            count = max(count, mp[e]);
        }
        
        int ans = (count-1)*(n+1);
        for(auto e : mp) if(e.second == count) ans++;
        return max((int)tasks.size(), ans);
    }
};

