// Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

/*
Let's verify the idea, we make an map and pick first 2 string and make an string of alternate character and keep repeating.
*/
bool custom_sort(const pair<char, int> &p1, const pair<char, int> &p2){
	return (p1.second > p2.second);
}

class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> my_map;
        int n = S.length();
        for(int i=0; i<n; i++) my_map[S[i]]++;
        // for(auto itr : my_map){
        //     cout<<itr.first<<" : "<<itr.second<<endl;
        // }
        vector<pair<char, int> > vect;
    	for(auto itr : my_map){
    		vect.push_back(make_pair(itr.first, itr.second));
    	}
        my_map.clear();
    	sort(vect.begin(), vect.end(), custom_sort);
    	// for(auto itr : vect){
    	// cout<<itr.first<<" : "<<itr.second<<endl;
    	// }

        string ans = "";
        while(vect[0].second!=0 && vect[1].second!=0){
        	// pick first two string
        	for(int i=0; i<min(vect[0].second, vect[1].second); i++){
        		ans += vect[0].first;
                ans += vect[1].first;
                // cout<<ans<<" ";
        		vect[0].second -= 1;
        		vect[1].second -= 1;
        	}
            
        	sort(vect.begin(),vect.end(),custom_sort);
            if(vect[1].second!=0) break;
            // for(auto itr : vect){
            //     if(itr.second == 0) break;
            //     cout<<itr.first<<" : "<<itr.second<<endl;
            // }
            // cout<<"--------\n";

        }
        if(vect[0].second > 1){
        	return "";
        }
        else if(vect[0].second == 1){
            return ans+vect[0].first ;
        }
        else{
            return ans ;
        }

    }
};