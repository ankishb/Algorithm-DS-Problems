// mine: O(n^2)
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

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<custom_pq> pq;
        int dist, x, y;
        int n = nums1.size();
        int m = nums2.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                x = nums1[i];
                y = nums2[j];
                dist = x + y;
                
                if(pq.size() == k){
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



// another good solution
40ms solution:

class Solution {
public:
vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        k = min(k, m * n);
        vector<int> indice(m, 0);
        while(k-- > 0){
            int tmp_index = 0;
            long tmp_sum = LONG_MAX;
            for(int i = 0; i < m; i++){
                if(indice[i] < n && tmp_sum >= nums1[i] + nums2[indice[i]]){
                    tmp_index = i;
                    tmp_sum = nums1[i] + nums2[indice[i]];
                }
            }
            res.push_back(make_pair(nums1[tmp_index], nums2[indice[tmp_index]]));
            indice[tmp_index]++;
        }
        return res;
    }
};








// good solution O(N)
Here, N = min(k, n).
K = min(k, mn)
where m, n is the size of two arrays and k is the k in the problem.

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0)
            return result;
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_heap(comp);
        min_heap.emplace(0, 0);
        while(k-- > 0 && min_heap.size())
        {
            auto idx_pair = min_heap.top(); min_heap.pop();
            result.emplace_back(nums1[idx_pair.first], nums2[idx_pair.second]);
            if (idx_pair.first + 1 < nums1.size())
                min_heap.emplace(idx_pair.first + 1, idx_pair.second);
            if (idx_pair.first == 0 && idx_pair.second + 1 < nums2.size())
                min_heap.emplace(idx_pair.first, idx_pair.second + 1);
        }
        return result;
    }
};

Comments: 6
BestMost VotesNewest to OldestOldest to Newest
fentoyal's avatar
fentoyal
1140

Last Edit: September 27, 2018 2:08 AM
Read More

Sure. Suppose you are at pair 0,0 (index 0 and index 0, not value), which is the current minimum.
Then you know the only two possible followers (immediate larger ones) are 0,1 and 1,0. Any other indices, say 1,1, 1,2, 3,3 have to be larger right?
So every time you get a current minimum i,j , you want to push i+1,j and i,j+1 into heap. You don't need to worry about others yet.

The problem here is, if you are at 2,3, you will push 3,3 and 2,4; then later, you are at 3,2. Then you will push 3,3, 4,2. so you pushed 3,3 twice.

But it is easy to realize, if you are at 2,3, and you haven't seen 3,2 yet (meaning 3,2 is either still in the queue but not popped yet or not even pushed into queue), you don't need to worry about 3,3 at this moment, because 3,2 is guaranteed to be no greater than 3,3. So you can wait till you see 3,2.

This basically means every time you see i,j you just need to push i+1, j into queue. i, j+1 can be pushed into queue later when you see i - 1, j + 1. The only exception to this is, when i == 0, there is no i-1, j+1 anymore, so you want to push both i+1, j and i, j+1 when i == 0.

Hope it is clear now













// python solution, but focus on idea only
I'd like to share this elegant design with heap with you guys, which was originally conceived of by someone else.

consider two input arrays:
nums1=[a1,a2,a3]
nums2=[b1,b2,b3]

and let's say k=3

We know the brutal force way to do it is to calc (a1, b1), (a1, b2), (a1,b3)....(a3,b3)'s sum respectively and sort the sums, and pick the top 3 of them. This algorithm is O(n2). And we need an algorithm better than that.

So, the overall idea of the algorithm:
Maintain a min-heap to keep only part of the whole set of combinations of all elements from nums1 and nums2. That way, we can avoid the brutal force way which is O(n2). We only push necessary pairs into the heap, until we find all of the k pairs.

How we achieve that (for the sake of explanation, ignore the corner cases for now):
1, create a heap, then push (S0, N1, N2) into the heap, where N1 is the position of first element in nums1, N2 is the position of first element in nums2, S0 is the sum of N1 and N2. Mark (N1,N2) as visited.
2, Pop the root element (S0, N1,N2) out of the heap, add (N1,N2) to the result to be returned. and immediately push (S1, N1+1,N2) and (S2, N1, N2+1) into the heap, where S1 = nums1[N1+1]+nums2[N2], S2 = nums1[N1] + nums2[N2+1]. Here, if a pair (Nx, Ny) has already been visited, we'll ignore it and not push it to the heap.
3, repeat this, until all k pairs have been added into the return list. Return the list.

The complexity of this algorithm is O(klgk) if k<n, because we repeat k times, and each time we do a O(lgk) heappush.

Why this algorithm works? The real question is, in this algorithm, how do we know that the sum of the pair that got heappopped earlier is always smaller than the sum of any pair that got heappushed later. Why we so sure about that?

Because, look at the process:
We heappop the minimal pair (S0, N1, N2), then immediately heappush two larger pairs (S1, N1+1,N2) and (S2, N1, N2+1). (why S1 and S2 always larger than S0? Because the two arrays are sorted.) And right after the heappush, the heap gets re-heaped, and of course the root at this point is larger (at least equal) than (S0, N1, N2). Remember though, the root now maybe (S1, N1+1,N2) or (S2, N1, N2+1) or any other pair that already exists in the heap after that heappop operation. This process gets repeated over and over again until finished.

From this, we can conclude that, the pairs that get heappushed is always larger than the pairs that get heappopped earlier. It might be smaller than other pairs that are currently in the heap, but we don’t care about that. We only care about pairs that got pushed or popped.

The beauty of this algorithm is, it works perfectly under the fact: two array are sorted. If the arrays were to be unsorted, we would not be able to guarentee that the two pairs get heappushed are always larger than the pair that gets heappopped, thus it would be possible that a pair that gets heappopped later is larger than one gets heappopped ealier, which would fail to produce the correct answer.

The code:

from heapq import *
class Solution:

    def kSmallestPairs(self, nums1, nums2, k):

        if not nums1 or not nums2:
            return []

        visited = []
        heap = []
        output = []

        heappush(heap, (nums1[0] + nums2[0], 0, 0))
        visited.append((0, 0))

        while len(output) < k and heap:

            val = heappop(heap)
            output.append((nums1[val[1]], nums2[val[2]]))

            if val[1] + 1 < len(nums1) and (val[1] + 1, val[2]) not in visited:
                heappush(heap, (nums1[val[1] + 1] + nums2[val[2]], val[1] + 1, val[2]))
                visited.append((val[1] + 1, val[2]))

            if val[2] + 1 < len(nums2) and (val[1], val[2] + 1) not in visited:
                heappush(heap, (nums1[val[1]] + nums2[val[2] + 1], val[1], val[2] + 1))
                visited.append((val[1], val[2] + 1))

        return output
