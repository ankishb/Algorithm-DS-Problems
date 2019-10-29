


[LeetCode] Employee Free Time Staff free time

We are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals , and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

Example 1:

  Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
 Output: [[3,4]]
 Explanation:
 There are a total of three employees, and all common
 Free time intervals would be [-inf, 1], [3, 4], [10, inf].
 We discard any intervals that contain inf as they aren't finite.

Example 2:

  Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
 Output: [[5,6],[7,9]]

(Even though we are representing Intervals in the form [x, y] , the objects inside are Intervals , not lists or arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2 , and schedule[0][0][0] is not defined.)

Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.

Note:

    schedule and schedule[i] are lists with lengths in range [1, 50] .
    0 <= schedule[i].start < schedule[i].end <= 10^8 . 

This question is basically not much different from the previous Merge Intervals . The question is to find the merged interval. This question asks for the unconnected interval in the middle of the merged interval. So as long as we merge the intervals, it is easy to do. Then we should first order all the intervals, according to the starting position from small to large. Because we can't always deal with the previous one, and then deal with the latter interval. After sorting the order, we first take the first interval and assign it to t, and then start traversing all the intervals in all the intervals. If the end position of t is smaller than the starting position of the interval i that is currently traversed, it means that there is no intersection between the two. Then add the disjoint part to the result res, and then assign the current interval i to t; otherwise, if there is an intersection between the interval t and the interval i, then we update the end position of t to the larger of the two because traversing in order In the interval, the end position of the interval t is the benchmark for comparison, and the larger the easier it is to merge with the later interval, see the code as follows:

Solution one:

  Class Solution { 
  Public : 
      Vector <Interval> employeeFreeTime(vector<vector<Interval>>& schedule) { 
          Vector <Interval> res, v; 
          For (auto a : schedule) { 
              V.insert(v.end(), a.begin(), a.end()); 
          } 
          Sort(v.begin(), v.end(), [](Interval &a, Interval &b) { return a.start < b.start;}); 
          Interval t = v[ 0 ]; 
          For (Interval i : v) { 
              If (t.end < i.start) { 
                  Res.push_back(Interval(t.end, i.start)); 
                  t = i; 
              } else { 
                  t = (t.end < i.end) ? i : t; 
              } 
          } 
          Return res; 
      } 
  }; 

Let's look at a solution. This solution is quite clever. We use TreeMap to establish a mapping between a position and its occurrence. For the starting position, it is positively accumulated, and for the ending position, it is negatively accumulated. Since TreeMap has the function of automatic sorting, when we traverse, we traverse from small to large. Define a variable cnt, initialized to 0, we add the mapping value in the TreeMap for each traversed number, that is, the number of times the number appears, the starting position will add a positive number, the ending position is plus negative number. At the beginning, the first number must be a starting position, then cnt is a positive number, then the next cnt may add a positive number, or subtract a negative number, we think, if the first interval and the second If there is no intersection in the interval, then the number encountered next is the end position of the first interval, so it will be subtracted by 1, so that cnt will be 0 at this time, which means that there will be a middle area, so we first put The current starting position of an interval, the ending position is temporarily put 0, and an interval is placed in the result res, so that we update the end position of the last interval in the result res when traversing to the next interval. The language description is inevitably too dry, let us take the example 1 in the title to illustrate, the established TreeMap is as follows:

1 -> 2
2 -> -1
3 -> -1
4 -> 1
5 -> 1
6 -> -1
10 -> -1

Then start traversing all the mapping pairs, cnt is first 2, then traverse the next mapping pair 2 -> -1, then cnt is 1, no other operations, then traverse down, the next mapping pair 3 -> -1, at this time cnt is 0, indicating that there will be a fault later, we will store (3, 0) in the result res. Then, when traversing to 4 -> 1, cnt is 1, and (3, 0) in the result res is updated to (3, 4). Then go to 5 -> 1, then cnt is 2, no other operations, then to 6 -> -1, then cnt is 1, no other operations, then to 10 -> -1, then cnt is 0 , add (10, 0) to the result res. Since there are no more intervals in the future, the last interval of res will not be updated any more. We should move it out of the result res because the range defined in the title cannot be infinite. See the code below:

Solution 2:

  Class Solution { 
  Public : 
      Vector <Interval> employeeFreeTime(vector<vector<Interval>>& schedule) { 
          Vector <Interval> res; 
          Map < int , int > m; 
          Int cnt = 0 ; 
          For (auto employee : schedule) { 
              For (Interval i : employee) { 
                  ++ m[i.start]; 
                  -- m[i.end]; 
              } 
          } 
          For (auto a : m) { 
              Cnt += a.second; 
              If (!cnt) res.push_back(Interval(a.first, 0 )); 
              If (cnt && !res.empty() && !res.back().end) res.back().end = a.first; 
          } 
          If (! res.empty()) res.pop_back(); 
          Return res; 
      } 
  }; 







  [LeetCode] Employee Free Time Staff free time

We are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals , and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

Example 1:

  Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
 Output: [[3,4]]
 Explanation:
 There are a total of three employees, and all common
 Free time intervals would be [-inf, 1], [3, 4], [10, inf].
 We discard any intervals that contain inf as they aren't finite.

Example 2:

  Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
 Output: [[5,6],[7,9]]

(Even though we are representing Intervals in the form [x, y] , the objects inside are Intervals , not lists or arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2 , and schedule[0][0][0] is not defined.)

Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.

Note:

    schedule and schedule[i] are lists with lengths in range [1, 50] .
    0 <= schedule[i].start < schedule[i].end <= 10^8 . 

This question is basically not much different from the previous Merge Intervals . The question is to find the merged interval. This question asks for the unconnected interval in the middle of the merged interval. So as long as we merge the intervals, it is easy to do. Then we should first order all the intervals, according to the starting position from small to large. Because we can't always deal with the previous one, and then deal with the latter interval. After sorting the order, we first take the first interval and assign it to t, and then start traversing all the intervals in all the intervals. If the end position of t is smaller than the starting position of the interval i that is currently traversed, it means that there is no intersection between the two. Then add the disjoint part to the result res, and then assign the current interval i to t; otherwise, if there is an intersection between the interval t and the interval i, then we update the end position of t to the larger of the two because traversing in order In the interval, the end position of the interval t is the benchmark for comparison, and the larger the easier it is to merge with the later interval, see the code as follows:

Solution one:

  Class Solution { 
  Public : 
      Vector <Interval> employeeFreeTime(vector<vector<Interval>>& schedule) { 
          Vector <Interval> res, v; 
          For (auto a : schedule) { 
              V.insert(v.end(), a.begin(), a.end()); 
          } 
          Sort(v.begin(), v.end(), [](Interval &a, Interval &b) { return a.start < b.start;}); 
          Interval t = v[ 0 ]; 
          For (Interval i : v) { 
              If (t.end < i.start) { 
                  Res.push_back(Interval(t.end, i.start)); 
                  t = i; 
              } else { 
                  t = (t.end < i.end) ? i : t; 
              } 
          } 
          Return res; 
      } 
  }; 

Let's look at a solution. This solution is quite clever. We use TreeMap to establish a mapping between a position and its occurrence. For the starting position, it is positively accumulated, and for the ending position, it is negatively accumulated. Since TreeMap has the function of automatic sorting, when we traverse, we traverse from small to large. Define a variable cnt, initialized to 0, we add the mapping value in the TreeMap for each traversed number, that is, the number of times the number appears, the starting position will add a positive number, the ending position is plus negative number. At the beginning, the first number must be a starting position, then cnt is a positive number, then the next cnt may add a positive number, or subtract a negative number, we think, if the first interval and the second If there is no intersection in the interval, then the number encountered next is the end position of the first interval, so it will be subtracted by 1, so that cnt will be 0 at this time, which means that there will be a middle area, so we first put The current starting position of an interval, the ending position is temporarily put 0, and an interval is placed in the result res, so that we update the end position of the last interval in the result res when traversing to the next interval. The language description is inevitably too dry, let us take the example 1 in the title to illustrate, the established TreeMap is as follows:

1 -> 2
2 -> -1
3 -> -1
4 -> 1
5 -> 1
6 -> -1
10 -> -1

Then start traversing all the mapping pairs, cnt is first 2, then traverse the next mapping pair 2 -> -1, then cnt is 1, no other operations, then traverse down, the next mapping pair 3 -> -1, at this time cnt is 0, indicating that there will be a fault later, we will store (3, 0) in the result res. Then, when traversing to 4 -> 1, cnt is 1, and (3, 0) in the result res is updated to (3, 4). Then go to 5 -> 1, then cnt is 2, no other operations, then to 6 -> -1, then cnt is 1, no other operations, then to 10 -> -1, then cnt is 0 , add (10, 0) to the result res. Since there are no more intervals in the future, the last interval of res will not be updated any more. We should move it out of the result res because the range defined in the title cannot be infinite. See the code below:

Solution 2:

  Class Solution { 
  Public : 
      Vector <Interval> employeeFreeTime(vector<vector<Interval>>& schedule) { 
          Vector <Interval> res; 
          Map < int , int > m; 
          Int cnt = 0 ; 
          For (auto employee : schedule) { 
              For (Interval i : employee) { 
                  ++ m[i.start]; 
                  -- m[i.end]; 
              } 
          } 
          For (auto a : m) { 
              Cnt += a.second; 
              If (!cnt) res.push_back(Interval(a.first, 0 )); 
              If (cnt && !res.empty() && !res.back().end) res.back().end = a.first; 
          } 
          If (! res.empty()) res.pop_back(); 
          Return res; 
      } 
  }; 










#include <bits/stdc++.h>
using namespace std;

bool check_subset_sum(vector<int> A, int sum){
	unordered_map<int, int> my_map;
	my_map[0] = -1;
	int n = A.size();
	int cur_sum=0;
	for(int i=0; i<n; i++){
		cur_sum += A[i];
		if(my_map.find(cur_sum - sum) != my_map.end()) return true;
		my_map[cur_sum] = i;
	}
	return false;
}

int main()
{
    int test;
    cin>> test;
    while(test--){
        int n, sum;
        cin>>n>>sum;
        vector<int> A(n);
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        (check_subset_sum(A, sum)) ? cout<<"YES\n" : cout<<"NO\n";
    }
    return 0;
}






#include <bits/stdc++.h>
using namespace std;

void get_seq_len(vector<int> &A, int idx, int sum, int &ans, int size){
	if(sum < 0) return ;
	ans = max(ans, size);
// 	cout<<sum<<" ";

	for(int i=idx; i<A.size(); i++){
	   // cout<<sum<<" : "<<A[i]<<endl;
		if(A[i] <= sum){
			get_seq_len(A, i+1, sum-A[i], ans, size+1);
		}
	}
}


int get_seq_len(vector<int> &A, int sum){
	int n = A.size();
	int count = 0;
	for(int i=0; i<n; i++){
		if(A[i] <= sum){
			sum = sum-A[i];
			count++;
		}
		else break;
	}
	return count;
}

int main()
{
    int test;
    cin>> test;
    while(test--){
        int A, B, n;
        cin>>A>>B>>n;
        vector<int> AA(n);
        for(int i=0; i<n; i++){
            cin>>AA[i];
        }
        sort(AA.begin(), AA.end());
        int A_count=0, B_count=0;
        int size=0, idx=0;
        A_count = get_seq_len(AA, A);
        // cout<<endl;
        B_count = get_seq_len(AA, B);
        // cout<<endl;
        
        // cout<<A_count<<" : "<<B_count<<endl;
        if(A_count < B_count) cout<<"Sayan Won\n";
        else if(A_count > B_count) cout<<"Raghu Won\n";
        else cout<<"Tie\n";
    }
    return 0;
}
