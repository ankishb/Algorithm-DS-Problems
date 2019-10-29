




class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n=A.size(), m=A[0].length();
        if(n <= 1) return 0;
        int count = 0;
        bool flag;
        for(int j=0; j<m; j++){
        	flag = true;
        	for(int i=1; i<n; i++){
        		if((A[i][j]-'a') < (A[i-1][j] - 'a')){
        			flag = false;
        			break;
        		}
        	}
        	if(flag == false) count++;
        }
        return count;
    }
};


class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        int inc=0, dec=0;
        if(n<3) return false;
        int i=1;
        if(A[i] < A[i-1]) return false;
        while(i<n && A[i] > A[i-1]) i++;
        if(i == n) return false;
        if(A[i] == A[i-1]) return false;
        while(i<n && A[i] < A[i-1]) i++;
        if(i != n) return false;
        else return true;
    }
};



class Solution {
public:
    void print(vector<int> store){
        cout<<endl;
        for(auto itr : store) cout<<itr<<" ";
        cout<<endl;
    }
    
	void helper(string str, int idx, vector<int> &store, vector<bool> &vis){
        // cout<<store.size()<<" ";
		int n = str.length();
		if(store.size() == n+1){
            // print(store);
            return;
        }

        // if(store.size() < n+1){     
            for(int i=0; i<n+1; i++){
                // cout<<i<<" ";
                if(str[idx] == 'I' && vis[i] == false && store.back() < i){
                    vis[i] = true;
                    store.push_back(i);
                    helper(str, idx+1, store, vis);
                    if(store.size() < n+1){
                        vis[i] = false;
                        store.pop_back();   
                    }
                    
                }
                else if(str[idx] == 'D' && vis[i] == false && store.back() > i){
                    vis[i] = true;
                    store.push_back(i);
                    helper(str, idx+1, store, vis);
                    if(store.size() < n+1){
                        vis[i] = false;
                        store.pop_back();
                    }
                }
            }
        // }
	}

    vector<int> recusive(string str) {
        int n = str.length();
        vector<int> store;
        if(n==0){
            store.push_back(0);
            return store;
        }
        vector<bool> vis(n+1, 0);
        for(int i=0; i<n+1; i++){
            vis[i] = true;
            store.push_back(i);
            helper(str, 0, store, vis);
            // print(store);
            if(store.size() == n+1) return store;
            vis[i] = false;
            store.pop_back();
        }
        
        return store;
    }
    
    vector<int> diStringMatch(string str) {
        int n = str.length();
        vector<int> store;
        if(n==0){
            store.push_back(0);
            return store;
        }
        int low=0, high = n;
        for(int i=0; i<n+1; i++){
            if(str[i] == 'I'){
                store.push_back(low);
                low++;
            }
            else{
                store.push_back(high);
                high--;
            }
        }
        return store;
    }
};









/*
https://leetcode.com/problems/find-the-shortest-superstring/
Given an array A of strings, find any smallest string that contains each string in A as a substring.
We may assume that no string in A is substring of another string in A.
Example 1:

Input: ["alex","loves","leetcode"]
Output: "alexlovesleetcode"
Explanation: All permutations of "alex","loves","leetcode" would also be accepted.

Example 2:

Input: ["catg","ctaagt","gcta","ttca","atgcatc"]
Output: "gctaagttcatgcatc

Note:

    1 <= A.length <= 12
    1 <= A[i].length <= 20

X. TSP
https://leetcode.com/problems/find-the-shortest-superstring/discuss/194932/Travelling-Salesman-Problem
Travelling Salesman Problem

    graph[i][j] means the length of string to append when A[i] followed by A[j]. eg. A[i] = abcd, A[j] = bcde, then graph[i][j] = 1
    Then the problem becomes to: find the shortest path in this graph which visits every node exactly once. This is a Travelling Salesman Problem.
    Apply TSP DP solution. Remember to record the path.

Time complexity: O(n^2 * 2^n)
*/
    public String shortestSuperstring(String[] A) {
        int n = A.length;
        int[][] graph = new int[n][n];
        // build the graph
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = calc(A[i], A[j]);
                graph[j][i] = calc(A[j], A[i]);
            }
        }
        int[][] dp = new int[1 << n][n];
        int[][] path = new int[1 << n][n];
        int last = -1, min = Integer.MAX_VALUE;
  
        // start TSP DP
        for (int i = 1; i < (1 << n); i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) > 0) {
                    int prev = i - (1 << j);
                    if (prev == 0) {
                        dp[i][j] = A[j].length();
                    } else {
                        for (int k = 0; k < n; k++) {
                            if (dp[prev][k] < Integer.MAX_VALUE && dp[prev][k] + graph[k][j] < dp[i][j]) {
                                dp[i][j] = dp[prev][k] + graph[k][j];
                                path[i][j] = k;
                            }
                        }
                    }
                }
                if (i == (1 << n) - 1 && dp[i][j] < min) {
                    min = dp[i][j];
                    last = j;
                }
            }
        }
  
        // build the path
        StringBuilder sb = new StringBuilder();
        int cur = (1 << n) - 1;
        Stack<Integer> stack = new Stack<>();
        while (cur > 0) {
            stack.push(last);
            int temp = cur;
            cur -= (1 << last);
            last = path[temp][last];
        }
  
        // build the result
        int i = stack.pop();
        sb.append(A[i]);
        while (!stack.isEmpty()) {
            int j = stack.pop();
            sb.append(A[j].substring(A[j].length() - graph[i][j]));
            i = j;
        }
        return sb.toString();
    }
    private int calc(String a, String b) {
        for (int i = 1; i < a.length(); i++) {
            if (b.startsWith(a.substring(i))) {
                return b.length() - a.length() + i;
            }
        }
        return b.length();
    }

https://leetcode.com/problems/find-the-shortest-superstring/discuss/198920/Shortest-Hamiltonian-Path-in-weighted-digraph-(with-instructional-explanation)
1. Formulate the problem as a graph problem
Let's consider each string as a node on the graph, using their overlapping range as a similarity measure, then the edge from string A to string B is defined as:

(A,B) = len(A) - overlapping(tail of A to head of B), 
eg    A="catg" B= "atgcatc", overlapping is "atg",which is a tail part of A, and a head part of B, therefore (A,B) = 4-3 = 1

Notice here that we must formulate the problem setup as a digraph, as (A,B)!=(B,A)
eg B="atgcatc" A="catg", overlapping is "c", so (B,A) = 7-1=6
Thus we can compute a distance matrix for this graph (see code below). Notice that the diagonal is always 0, and as this is a digraph, this matrix is asymmetric.
2. Using DP to find a minimum Hamiltonian cycle (which is in fact a Travelling Salesman Problem)
The major steps here are:
(1) We arbitrarily select a starting node. It doesn't matter which one we choose, as we are looking for a Hamiltonian cycle, so every node will be included and can be used as a starting node. Here we choose node 0.
(2) We build a path by selecting a node as an endpoint, and build it up from there. For example,

We want to compute a subpath containing {2,4,5}. We have 3 candidates here:
2 as the endpoint, compute subproblem {4,5};
4 as the endpoint, compute subproblem {2,5};
5 as the endpoint, compute subprobelm {2,4};
The one with the minimum distance will be our choice.

Notice the base case here is simply a subpath of only one node i. In this case we simply return the distance from our starting node(0) to node i, this is where the pre-computed distance matrix comes in handy.
eg {i} = distance_matrix [0] [i]
Also notice that I implement it as a top-down approach, a bottom up one is equally if not more efficient.
3. Convert the full tour to a path
Why do we need to convert the tour to a path? This point can be subtle, as it seems that we can simply build the superstring directly from the tour, but there is a problem, our superstring might "wrap around" and fail to contain all the strings. Consider this example:

["catg","atgcatc"]
The distance matrix is
0 1
6 0

And the TSP algorithm will give the result of "catgcat", as the min distance is 7, and we indeed have 7 characters in the superstring, but do you see the problem here? "atgcatc" misses a "c"! This is because the "c" wraps around to the head of "catg". So the TSP algorithm give a correct result per se, but we need to modify it to get the correct Hamiltonian Path for our particular problem.
Below I will highlight the intuition, and the implementation favors clarity rather than efficiency.
Say we've found a tour, (0,2,4,3,1,0) for and input of 5 strings.
Now there are 5 possible shortest Hamiltonian Paths as our candidates.
(0,2,4,3,1), (2,4,3,1,0), (4,3,1,0,2), (3,1,0,2,4), (1,0,2,4,3).
The insight here is that the length of these 5 paths may well be different, precisely due to the wrap around nature of our string problem.

Consider this example:

"catg","ttca"

Both "catgttca" and "ttcatg" will be valid Hamiltonian paths, as we only have 2 nodes here. So (1,2) and (2,1) are two valid paths.
The unmodified TSP might give us "catgtt" or "ttcatg", both of length 6. 

Notice that for the first one, the "ca" of "ttca" wraps around to the head of "catg" as we explaned above, so "tcaa" is not actually contained in our result, but it's the correct tour! The second one is the one we want. But depending our choice of starting node, we might get the first one. That's why we need this extra step to convert a tour to a correct path.
This is, however, very straightforward, if not very efficient. We simply construct all the possible paths from the tour, and compare their length, then return the one with the min length. By this we solve the uncertainty with the starting point choice. In the original TSP, it doesn't matter where the salesman starts his journey, as it's a tour. But our superstring problem requires this small modification.
Below is the top down approach. For clarity and debugging purposes, I use a String to store the path. Arrays, tuples (if your language supports it) and any other data structure that preserves ordering will be adequate.
As I said, this is not the most efficient implementation of the TSP / Shortest Hamiltonian Path problem, but I hope this gives you an idea behind the algorithm and the subtleties of it when applied to another problem.

    int[][] distance;
    Map<String,String> memo;
    public String shortestSuperstring(String[] A) {
        if(A.length==1) return A[0];
        buildDistanceMatrix(A);
        memo = new HashMap<>();
        //build key for the final solution, key is in the form "end:set of nodes", eg "0:1,2,3,4"
        StringBuilder builder = new StringBuilder();
        for(int i=1; i<A.length; i++){
            builder.append(i);
            builder.append(",");
        }
        builder.deleteCharAt(builder.length() - 1);
        String key = "0"+":"+builder.toString();
        
        // start top-down algo, val is in the form of "sequence;minDistance", eg "0,3,4,2,1,0;20"
        String seq = TSP(key).split(";")[0];
        String res = convertToHP(seq,A);
        return res;
    }
    
    private String convertToHP(String seq, String[]A){
        String[] tour = seq.split(",");
        int N = tour.length-1;
        int[] hamPath = new int[N];
        for(int i=0; i<N; i++){
            hamPath[i] = Integer.parseInt(tour[i]);
        }
        
        int[][] pool = new int[N][N];
        pool[0] = hamPath;
        for(int i=1; i<N; i++){
            int[]candidate = new int[N];
            for(int j=i; j<i+N; j++){
                candidate[j-i] = hamPath[j%N];
            }
            pool[i] = candidate;
        }
        int min = 1000;
        String sol = "";
        for(int[]path:pool){
            String res = buildPath(path,A);
            if(res.length()<min){
                min = res.length();
                sol = res;
            }
        }
        return sol;
    }
    
    private String buildPath(int[]path,String[]A){
        StringBuilder builder = new StringBuilder();
        for(int j=0; j<path.length-1; j++){
            int start = path[j];
            int end = path[j+1];
            int len = distance[start][end];
            builder.append(A[start].substring(0,len));
        }
        builder.append(A[path[path.length-1]]);
        return builder.toString();
    }
    
    private void buildDistanceMatrix(String[]A){
        int N = A.length;
        distance = new int[N][N];
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(i==j) continue;
                String start = A[i];
                String end = A[j];
                for(int k=Math.min(start.length(),end.length()); k>0; k--){
                    if(start.endsWith(end.substring(0,k))){
                        distance[i][j] = start.length()-k;
                        break;
                    }
                    else distance[i][j] = start.length();
                }
            }
        }
    }
    
    private String TSP(String key){
        if(memo.containsKey(key)) return memo.get(key);
        
        String[] temp = key.split(":");
        String endPointS = temp[0];
        int endPoint = Integer.parseInt(endPointS);
        
        //base case
        if(key.endsWith(":")){
            String seq = "0"+","+endPointS;
            int dist = distance[0][endPoint];
            String res = seq+";"+Integer.toString(dist);
            memo.put(key,res);
            return res;
        }
        
        String[] elements = temp[1].split(",");
        int min = 1000;
        String candidate="X";
        for(int i=0; i<elements.length; i++){
            String subKey = buildKey(elements, i);
            String[] res = TSP(subKey).split(";");
            int updatedDist = distance[Integer.parseInt(elements[i])][endPoint] + Integer.parseInt(res[1]);
            String updatedSeq = res[0] + "," + endPointS;
            if(updatedDist<min){
                min = updatedDist;
                candidate = updatedSeq;
            }
        }
        String val = candidate + ";" + Integer.toString(min);
        memo.put(key,val);
        return val;
    }
    
    private String buildKey(String[]s, int excl){
        String endPoint = s[excl];
        StringBuilder builder = new StringBuilder();
        builder.append(endPoint);
        builder.append(":");
        if(s.length==1) return builder.toString();
        
        for(String node:s){
            if(node.equals(endPoint))continue;
            builder.append(node);
            builder.append(",");
        }
        builder.deleteCharAt(builder.length() - 1);
        return builder.toString();
    }


https://leetcode.com/articles/find-the-shortest-superstring/
We have to put the words into a row, where each word may overlap the previous word. This is because no word is contained in any word.
Also, it is sufficient to try to maximize the total overlap of the words.
Say we have put some words down in our row, ending with word A[i]. Now say we put down word A[j]as the next word, where word j hasn't been put down yet. The overlap increases by overlap(A[i], A[j]).
We can use dynamic programming to leverage this recursion. Let dp(mask, i) be the total overlap after putting some words down (represented by a bitmask mask), for which A[i] was the last word put down. Then, the key recursion is dp(mask ^ (1<<j), j) = max(overlap(A[i], A[j]) + dp(mask, i)), where the jth bit is not set in mask, and i ranges over all bits set in mask.
Of course, this only tells us what the maximum overlap is for each set of words. We also need to remember each choice along the way (ie. the specific i that made dp(mask ^ (1<<j), j) achieve a minimum) so that we can reconstruct the answer.
Our algorithm has 3 main components:

    Precompute overlap(A[i], A[j]) for all possible i, j.
    Calculate dp[mask][i], keeping track of the "parent" i for each j as described above.
    Reconstruct the answer using parent information.

    Time Complexity: O(N^2 (2^N + W))O(N2(2N+W)), where NN is the number of words, and WW is the maximum length of each word.
    Space Complexity: O(N (2^N + W))O(N(2N+W)). 

  public String shortestSuperstring(String[] A) {
    int N = A.length;

    // Populate overlaps
    int[][] overlaps = new int[N][N];
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        if (i != j) {
          int m = Math.min(A[i].length(), A[j].length());
          for (int k = m; k >= 0; --k)
            if (A[i].endsWith(A[j].substring(0, k))) {
              overlaps[i][j] = k;
              break;
            }
        }

    // dp[mask][i] = most overlap with mask, ending with ith element
    int[][] dp = new int[1 << N][N];
    int[][] parent = new int[1 << N][N];
    for (int mask = 0; mask < (1 << N); ++mask) {
      Arrays.fill(parent[mask], -1);

      for (int bit = 0; bit < N; ++bit)
        if (((mask >> bit) & 1) > 0) {
          // Let's try to find dp[mask][bit]. Previously, we had
          // a collection of items represented by pmask.
          int pmask = mask ^ (1 << bit);
          if (pmask == 0)
            continue;
          for (int i = 0; i < N; ++i)
            if (((pmask >> i) & 1) > 0) {
              // For each bit i in pmask, calculate the value
              // if we ended with word i, then added word 'bit'.
              int val = dp[pmask][i] + overlaps[i][bit];
              if (val > dp[mask][bit]) {
                dp[mask][bit] = val;
                parent[mask][bit] = i;
              }
            }
        }
    }

    // # Answer will have length sum(len(A[i]) for i) - max(dp[-1])
    // Reconstruct answer, first as a sequence 'perm' representing
    // the indices of each word from left to right.

    int[] perm = new int[N];
    boolean[] seen = new boolean[N];
    int t = 0;
    int mask = (1 << N) - 1;

    // p: the last element of perm (last word written left to right)
    int p = 0;
    for (int j = 0; j < N; ++j)
      if (dp[(1 << N) - 1][j] > dp[(1 << N) - 1][p])
        p = j;

    // Follow parents down backwards path that retains maximum overlap
    while (p != -1) {
      perm[t++] = p;
      seen[p] = true;
      int p2 = parent[mask][p];
      mask ^= 1 << p;
      p = p2;
    }

    // Reverse perm
    for (int i = 0; i < t / 2; ++i) {
      int v = perm[i];
      perm[i] = perm[t - 1 - i];
      perm[t - 1 - i] = v;
    }

    // Fill in remaining words not yet added
    for (int i = 0; i < N; ++i)
      if (!seen[i])
        perm[t++] = i;

    // Reconstruct final answer given perm
    StringBuilder ans = new StringBuilder(A[perm[0]]);
    for (int i = 1; i < N; ++i) {
      int overlap = overlaps[perm[i - 1]][perm[i]];
      ans.append(A[perm[i]].substring(overlap));
    }

    return ans.toString();

  }


X. https://www.techiedelight.com/shortest-superstring-problem/
Shortest Superstring Problem is a NP Hard problem. A solution that always finds shortest superstring takes exponential time. Below is an Approximate Greedy algorithm.

Let arr[] be given set of strings.

1) Create an auxiliary array of strings, temp[].  Copy contents
   of arr[] to temp[]

2) While temp[] contains more than one strings
     a) Find the most overlapping string pair in temp[]. Let this
        pair be 'a' and 'b'. 
     b) Replace 'a' and 'b' with the string obtained after combining
        them.

3) The only string left in temp[] is the result, return it.

Two strings are overlapping if prefix of one string is same suffix of other string or vice verse. The maximum overlap mean length of the matching prefix and suffix is maximum.


    private static int findOverlappingPair(String s1, String s2,

                                            StringBuilder sb)

    {

        // max will store maximum overlap i.e maximum length of the

        // matching prefix and suffix

        int max = Integer.MIN_VALUE;


        // consider minimum length

        int n = Integer.min(s1.length(), s2.length());


        // check suffix of s1 matches with prefix of s2

        for (int i = 1; i <= n; i++)

        {

            // compare last i characters in s1 with first i characters in s2

            if (s1.substring(s1.length() - i).equals(s2.substring(0, i)))

            {

                if (max < i)

                {

                    //update max and str

                    max = i;

                    sb.setLength(0);

                    sb.append(s1).append(s2.substring(i));

                }

            }

        }


        // check prefix of s1 matches with suffix of s2

        for (int i = 1; i <= n; i++)

        {

            // compare first i characters in s1 with last i characters in s2

            if (s1.substring(0, i).equals(s2.substring(s2.length() - i)))

            {

                if (max < i)

                {

                    //update max and str

                    max = i;

                    sb.setLength(0);

                    sb.append(s2).append(s1.substring(i));

                }

            }

        }


        return max;

    }


    // Function to calculate smallest string that contains

    // each string in the given set as substring.

    public static String findShortestSuperstring(List<String> list)

    {

        int n = list.size();


        // run n-1 times to consider every pair

        while (n != 1)

        {

            // to store  maximum overlap

            int max = Integer.MIN_VALUE;


            // stores index of strings involved in maximum overlap

            int p = -1, q = -1;


            // to store resultant string after maximum overlap

            String res_str = "";


            for (int i = 0; i < n; i++)

            {

                for (int j = i + 1; j < n; j++)

                {

                    StringBuilder sb = new StringBuilder();


                    // r will store maximum length of the matching prefix

                    // and suffix sb is passed by reference and will store

                    // the resultant string after maximum overlap of

                    // list.get(i) and list.get(j), if any

                    int r = findOverlappingPair(list.get(i),list.get(j),sb);


                    // check for maximum overlap

                    if (max < r)

                    {

                        max = r;

                        res_str = sb.toString();

                        p = i;

                        q = j;

                    }

                }

            }


            // ignore last element in next cycle

            n--;


            // if no overlap, append list.get(n) to list.get(0)

            if (max == Integer.MIN_VALUE) {

                list.set(0, list.get(0) + list.get(n));

            }

            else {

                // copy resultant string to index p

                list.set(p, res_str);


                // copy string at last index to index q

                list.set(q, list.get(n));

            }

        }


        return list.get(0);

    }
