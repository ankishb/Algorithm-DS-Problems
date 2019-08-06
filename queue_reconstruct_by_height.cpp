
bool custom_sort(const vector<int> &v1, const vector<int> &v2){
	return (v1[0]>v2[0])||(v1[0]==v2[0] && v1[1]<v2[1]);
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    	int n = people.size();
        sort(people.begin(), people.end(), custom_sort);
        // for(auto itr : people){
        //     cout<<itr[0]<<" "<<itr[1]<<endl;
        // }
        int pos, cur_pos;
        vector<vector<int> > ans;
        for(int i=0; i<n; i++){
        	if(people[i][1] >= i) ans.push_back(people[i]);
        	else{
        		// we find the right position
        		ans.push_back(people[i]);
        		pos = i;
                cur_pos = people[pos][1];
        		while(pos != cur_pos){
        			pos--;
        			swap(ans[pos], ans[pos+1]);
        		}
        	}
        }
        // for(auto itr : ans){
        // 	cout<<itr[0]<<" "<<itr[1]<<endl;
        // }
        return ans;
    }
};





// elegant solution
class Solution {
   public:
    // [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
    //  
    // Sort first:
    //
    // [7, 0] 0
    // [7, 1] 1
    // [6, 1] 2
    // [5, 0] 3
    // [5, 2] 4
    // [4, 4] 5
    //  
    // Reconstruct the queue step by step:
    //  
    // [7, 0]
    // [7, 0] [7, 1] 
    // [7, 0] [6, 1] [7, 1]
    // [5, 0] [7, 0] [6, 1] [7, 1]
    // [5, 0] [7, 0] 5, 2] [6, 1] [7, 1]
    // [5, 0] [7, 0] 5, 2] [6, 1] [4, 4] [7, 1]
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        auto cmp = [](const vector<int> &a, const vector<int> &b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        };
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> peopleAfter;
        for (int i = 0; i < people.size(); i++) {
            if (people[i][1] == peopleAfter.size()) {
                // Heights of all previous people are greater or equal to
                // current person.
                peopleAfter.push_back(people[i]);
            } else {
                // Insert at correct position
                peopleAfter.insert(peopleAfter.begin() + people[i][1],
                                   people[i]);
            }
        }
        return peopleAfter;
    }
};


[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
