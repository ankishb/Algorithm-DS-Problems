// Approach:
// We create an new vector, which store the +ve-capacity, if it starts and -ve-capacity, if it leaves and sort it on the location

bool custom(const pair<int, int> &p1, const pair<int, int> &p2){
	return p1.second<p2.second;
}

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        vector<pair<int, int> > trips_;
        for(auto itr : trips){
        	trips.push_back(make_pair(itr[0], itr[1]));
        	trips.push_back(make_pair(0-itr[0], itr[2]));
        }

        sort(trips_.begin(), trips_.end(), custom);
        for(auto itr : trips_){
        	capacity -= itr.first;
        	if(capacity < 0) return false;
        }
        return true;
    }
};








// Approach:
// We create an new vector, which store the +ve-capacity, if it starts and -ve-capacity, if it leaves and sort it on the location

bool custom_vector(const vector<int> &v1, const vector<int> &v2){
    return (v1[2]<v2[2])&&(v1[1]<v2[1]);
}

bool custom(const pair<int, int> &p1, const pair<int, int> &p2){
	return (p1.second<p2.second);
}


class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // sort(trips.begin(), trips.end(), custom_vector);
        
        vector<pair<int, int> > pick;
        vector<pair<int, int> > drop;
        for(auto itr : trips){
        	pick.push_back(make_pair(itr[0], itr[1]));
        	drop.push_back(make_pair(0-itr[0], itr[2]));
        }

        sort(pick.begin(), pick.end(), custom);
        sort(drop.begin(), drop.end(), custom);
        
        int n = trips.size();
        int pick_i = 0, drop_i = 0, cur_time = 0;
        pair<int, int> pick_ith, drop_ith;
        while(drop_i<n){
        	pick_ith = pick[pick_i];
        	drop_ith = drop[drop_i];
        	if(pick_ith.second < )
        	if(capacity >= 0){
        		// we pick passenger

        	}
        }
        for(auto itr : trips_){
        	capacity -= itr.first;
        	if(capacity < 0) return false;
        }
        return true;
    }
};






class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> v;
        
        for(int i = 0; i < trips.size(); i++){
            v.push_back({trips[i][1], trips[i][0]});
            v.push_back({trips[i][2], -trips[i][0]});
        }
        
        sort(v.begin(), v.end());
        
        int filled = 0;
        
        for(int i = 0; i < v.size(); i++){
            filled += v[i].second;
            if(filled > capacity) return false;
        }
        return true;
    }
};







static auto fast=[]{ios_base::sync_with_stdio(false); cin.tie(nullptr);return 0;}();
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        int start=INT_MAX;
        int end=INT_MIN;
        unordered_map<int,int> pick;
        unordered_map<int,int> drop;
        for(int i=0;i<trips.size();i++)
        {
            pick[trips[i][1]]+=trips[i][0];
            drop[trips[i][2]]+=trips[i][0];
            if(start>trips[i][1])
               start=trips[i][1];
            if(end<trips[i][2])
               end=trips[i][2]; 
        }
        int curr_cp=0;
        while(start!=end+1)
        {
            if(drop.find(start)!=drop.end())
                curr_cp-=drop[start];
            if(pick.find(start)!=pick.end())
            {
                curr_cp+=pick[start];
                if(curr_cp>capacity)
                   return false; 
            }
            start++;
        }
        return true;
    }
};




class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> map;
        for (int i = 0;i < trips.size();++i) {
            map[trips[i][1]] += trips[i][0]; //filled seats increase when we pick up passengers
            map[trips[i][2]] -= trips[i][0]; //filled seats decrease when we drop off the passengers
        }
        for (auto it = map.begin(); it != map.end();it++) { //map is sorted on keys( key is time instant)
            capacity -= it->second;
            if (capacity < 0) { //if at any time instant, vacant seats < no of passengers to pick up, return false
                return false;
            }
        }
        return true;
    }
};