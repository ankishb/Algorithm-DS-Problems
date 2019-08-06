// my solution using priority queue
class custom_pq{
public:
    int dist;
    int coord1, coord2;
    custom_pq(int a, int b, int c){
        dist = a;
        coord1 = b;
        coord2 = c;
    }
};

bool operator<(const custom_pq& p1, const custom_pq& p2){
    return p1.dist < p2.dist;
}

class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<custom_pq> pq;
        int dist, x, y;
        int n = points.size();
        // custom_pq top_;
        for(int i=0; i<n; i++){
            x = points[i][0];
            y = points[i][1];
            dist = x*x + y*y;
            cout<<dist<<" ";
            if(pq.size() == K){
                custom_pq top_ = pq.top();
                if(top_.dist > dist){
                    pq.pop();
                    pq.push(custom_pq(dist, x, y));
                }
            }
            else{
                pq.push(custom_pq(dist, x, y));
            }
            
        }
        
        vector<vector<int> > ans;
        vector<int> temp;
        while(!pq.empty()){
            custom_pq top_ = pq.top();
            temp.push_back(top_.coord1);
            temp.push_back(top_.coord2);
            ans.push_back(temp);
            temp.clear();
            cout<<top_.dist<<" ";
            pq.pop();
        }
        return ans;
    }
};




// using partial_sort
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        partial_sort(points.begin(), points.begin() + K, points.end(), [](vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};