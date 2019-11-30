
class Solution {
public:
    int maxPoints(vector<vector<int>>& points){
        int result = 0;
        for(int i=0; i<points.size(); i++){
            int samePoint = 0;
            int overFlowSlope = 0;
            int curMax = 0;
            unordered_map<string, int> map;
            for(int j=i+1; j<points.size(); j++){
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1])
                    samePoint++;
                else if(points[i][0] == points[j][0])
                    overFlowSlope++;
                else{
                    int yDif = points[i][1] - points[j][1];
                    int xDif = points[i][0] - points[j][0];
                    int g = std::__gcd(yDif, xDif);
                    yDif /= g;
                    xDif /= g;
                    // if (yDif < 0) {
                    //     yDif = -yDif;
                    //     xDif = -xDif;
                    // }
                    stringstream str;
                    str<<yDif<<","<<xDif;
                    map[str.str()]++;
                    curMax = std::max(curMax,map[str.str()]);
                }
                curMax = std::max(curMax, overFlowSlope);
            }
            result = std::max(result, curMax+samePoint+1);
        }
        return result;
    }
};



int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    if(A.size() == 0 || B.size() == 0){
        return 0;
    }
    
    unordered_map<double, int> myMap;
    int sol = 1;
    for(int i = 0; i < A.size(); i++){
        int duplicate = 1;
        int vertical = 0;
        for(int j = i+1; j < A.size(); j++){
            if(A[i] == A[j]){
                if(B[i] == B[j]){
                    duplicate++;
                }
                else{
                    vertical++;
                }
            }
            else{
                double slope = 0.0;
                double x = A[j] - A[i];
                double y = B[j] - B[i];
                if(B[j] != B[i]){
                    slope = (1.0 * (y/x));
                }
                if(myMap.find(slope) != myMap.end()){
                    myMap[slope]++;
                }
                else{
                    myMap[slope] = 1;
                }
            }
        }
        auto it = myMap.begin();
        while(it != myMap.end()){
            int t = it->second;
            if((t + duplicate) > sol){
                sol = t + duplicate;
            }
            it++;
        }
        if((vertical + duplicate) > sol){
            sol = vertical + duplicate;
        }
        myMap.clear();
    }
    
    return sol;
}

// #include <bits/stdc++.h>
// using namespace std;

// int get_count(vector<pair<int, int> > vect){
// 	map<int, int> my_map;
// 	pair<int, int> p;
// 	int slope;
// 	int x1, y1, x2, y2;
// 	int global_max = INT_MIN;

// 	for(int i=0; i<vect.size(); i++){
// 		my_map.clear();
// 		for(int j=i+1; j<vect.size(); j++){
// 			p = vect[i];
// 			x1 = p.first;
// 			y1 = p.second;
			
// 			p = vect[j];
// 			x2 = p.first;
// 			y2 = p.second;

// 			if((x2 - x1) != 0){
// 				slope = (y2 - y1)/(x2 - x1);
// 				my_map[slope]++;
// 			}
			
// 		}
// 		int max_count = INT_MIN;
// 		for(auto itr : my_map){
// 			max_count = max(max_count, itr.second);
// 		}
// 		global_max = max(global_max, max_count);
// 	}

// 	// int max_count = INT_MIN;
// 	// for(auto itr : my_map){
// 	// 	max_count = max(max_count, itr.second);
// 	// 	// cout<<itr.first<<" "<<itr.second<<endl;
// 	// }
// 	return global_max;
// }

// int main()
// {
// 	int test;
// 	cin>>test;
// 	while(test--){
// 		int n;
// 		cin>>n;
// 		vector<pair<int, int> > vect;
// 		int x, y;
// 		while(n--){
// 			cin>>x>>y;
// 			vect.push_back(make_pair(x, y));
// 		}
// 		cout<<get_count(vect)<<endl;
// 	}
// 	return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int get_count(vector<int> &xs, vector<int> &ys){
    if(xs.size() == 0){
        return 0;
    }
    if(xs.size() == 1){
        return 1;
    }
    map<float, int> my_map;
    float slope;
    int x1, y1, x2, y2;
    int global_max = INT_MIN;

    for(int i=0; i<xs.size()-1; i++){
        my_map.clear();
        int duplicates = 0;
        for(int j=i+1; j<xs.size(); j++){
            x1 = xs[i];
            y1 = ys[i];

            x2 = xs[j];
            y2 = ys[j];

            if(x1 == x2 && y1 == y2){
            	duplicates++;
            }
            else{
	            if((x2 - x1) != 0){
	                slope = (y2 - y1)/((x2 - x1)*1.0);
	                cout<<"slope-- "<<slope<<endl;
	            }
	            else{
	                slope = INT_MAX;
	            }
	            my_map[slope]++;
	        }
            
        }
        int max_count = INT_MIN;
        for(auto itr : my_map){
            max_count = max(max_count, itr.second);
        }
        if(max_count == INT_MIN){
        	if(duplicates != 0){
        		max_count = duplicates;
        	}
        	else{
        		max_count = 1;
        	}
        }
        else{
        	max_count += duplicates;	
        }
        
        cout<<max_count<<"--"<<endl;
        global_max = max(global_max, max_count);
    }

    // int max_count = INT_MIN;
    // for(auto itr : my_map){
    //     max_count = max(max_count, itr.second);
    //     // cout<<itr.first<<" "<<itr.second<<endl;
    // }
    return global_max+1;
}
int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> xs;
		vector<int> ys;
		int x, y;
		while(n--){
			cin>>x>>y;
			xs.push_back(x);
			ys.push_back(y);
		}
		cout<<get_count(xs, ys)<<endl;
	}
	return 0;
}