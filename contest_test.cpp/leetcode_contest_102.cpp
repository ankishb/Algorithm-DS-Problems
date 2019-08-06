// Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
		int n = A.size();
		int odd_idx = 0;
		int even_idx = n-1;
		while(odd_idx < even_idx){
			if(A[odd_idx]%2 == 0) odd_idx++;
			else if(A[even_idx]%2 == 1) even_idx--;
			else{
				swap(A[odd_idx], A[even_idx]);
				odd_idx++;
				even_idx--;
			}
		}
		return A;

    }
};
/*
Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.

Since the answer may be large, return the answer modulo 10^9 + 7.

Input: [3,1,2,4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
*/

class Solution {
public:
	int mod = 1000000007;
    int sumSubarrayMins(vector<int>& A) {
    	int n = A.size();
    	vector<int> left(n), right(n);
    	stack<pair<int, int> > s;
    	for(int i=0; i<n; i++){
    		int count = 1;
    		while(!s.empty() && s.top().first > A[i]){
    			count += s.top().second;
    			s.pop();
    		}
    		s.push(make_pair(A[i], count));
    		left[i] = count;
    	}
    	while(!s.empty()) s.pop();
    	for(int i=n-1; i>=0; i--){
    		int count = 1;
    		while(!s.empty() && s.top().first >= A[i]){
    			count += s.top().second;
    			s.pop();
    		}
    		s.push(make_pair(A[i], count));
    		right[i] = count;
    	}

    	int ans = 0, temp;
    	for(int i=0; i<n; i++){
    		temp = A[i] * left[i] * right[i];
    		ans += (temp%mod);
    		ans = (ans%mod);
    	}
    	return ans;
    }
};







class Solution {
public:
	int totalFruit(vector<int> &tree) {
        unordered_map<int, int> count;
        int i, j;
        for (i = 0, j = 0; j < tree.size(); ++j) {
            count[tree[j]]++;
            if (count.size() > 2) {
                if (--count[tree[i]] == 0)count.erase(tree[i]);
                i++;
            }
        }
        return j - i;
    }




    int totalFruit(vector<int> &tree) {
        int max_type = 0;
        int n = tree.size();
        int i=0, idx=0, count=0;
        unordered_map<int, int> my_map;
        while(idx < n){
            my_map[tree[idx]]++;
            count++;
            if(my_map.size() > 2){
                // max_type = max(max_type, count-1);
                max_type = max(max_type, idx-i);
                while(my_map.size() != 2){
                    my_map[tree[i]]--;
                    count--;
                    if(my_map[tree[i]] == 0){
                        my_map.erase(tree[i]);
                    }
                    i++;
                }
            }
            idx++;
        }
        // max_type = max(max_type, count);
        max_type = max(max_type, idx-i);
        return max_type;
    }
};















Given a string S, find the length of the longest substring T that contains at most two distinct characters.
For example,
Given S = "eceba" ,
T is "ece" which its length is 3.

Given a string, find the longest substring of up to two different characters. Or the sliding window method, define a HashMap or Array to store the number of characters that have appeared, the initial position of the left and right pointers is 0, the right pointer is swept to the right, the number of different characters is added to the new character plus 1, and it is stored in the HashMap. The character, HashMap corresponds to the number of characters plus 1. If the number of different characters is greater than 2, the number of characters in the left pointer position is reduced by 1 in the HashMap. Note that this is not necessarily the case. If the number of characters is greater than 0 at this time, the character is still present, and the left pointer is added. 1 Continue to move to the right, the character scanned will not be in the window later. It should be decremented by 1 in the HashMap. If the character is decremented by 1 and 0, it means that the character is not in the window. At this time, the number of characters can be different. Subtract 1 and move the left pointer to the right to point to the next character. The length of the window is compared with the maximum length, and the maximum value is retained. Repeat the above steps until the right pointer sweeps all characters. Finally return the maximum length.

Java: T: O(n), S: O(1)

  Public int lengthOfLongestSubstringTwoDistinct(String s) {
     Int max=0;
     HashMap<Character,Integer> map = new HashMap<Character, Integer>();
     Int start=0;
 
     For(int i=0; i<s.length(); i++){
         Char c = s.charAt(i);
         If(map.containsKey(c)){
             Map.put(c, map.get(c)+1);
         }else{
             Map.put(c,1);
         }
 
         If(map.size()>2){
             Max = Math.max(max, i-start);
 
             While(map.size()>2){
                 Char t = s.charAt(start);
                 Int count = map.get(t);
                 If(count>1){
                     Map.put(t, count-1);
                 }else{
                     Map.remove(t);
                 }
                 Start++;
             }
         }
     }
 
     Max = Math.max(max, s.length()-start);
 
     Return max;
 }

Java:

  Public int lengthOfLongestSubstringTwoDistinct(String s) {
         Map<Character, Integer> map = new HashMap<>();
         Int start = 0, end = 0;
         Int counter = 0, len = 0;
         While(end < s.length()){
             Char cur = s.charAt(end);
             If(!map.containsKey(cur)) map.put(cur, 0);
             Map.put(cur, map.get(cur) + 1);
             If(map.get(cur) == 1) counter++;//new distinct char
             While(counter > 2){//
                 Char c2 = s.charAt(start);
                 Map.put(c2, map.get(c2) - 1);
                 If(map.get(c2) == 0) counter--;
                 Start++;
             }
             Len = Math.max(end - start + 1, len);
             End++;
         }
         Return len;
     }

Python:

  Class Solution:
     Def lengthOfLongestSubstringTwoDistinct(self, s):
         Longest, start, distinct_count, visited = 0, 0, 0, [0 for _ in xrange(256)]
         For i, char in enumerate(s):
             If visited[ord(char)] == 0:
                 Distinct_count += 1
             Visited[ord(char)] += 1
            
             While distinct_count > 2:
                 Visited[ord(s[start])] -= 1
                 If visited[ord(s[start])] == 0:
                     Distinct_count -= 1
                 Start += 1
  
             Longest = max(longest, i - start + 1)
         Return longest

C++:

  Class Solution {
 Public:
     Int lengthOfLongestSubstringTwoDistinct(string s) {
         Int res = 0, left = 0;
         Unordered_map<char, int> m;
         For (int i = 0; i < s.size(); ++i) {
             ++m[s[i]];
             While (m.size() > 2) {
                 If (--m[s[left]] == 0) m.erase(s[left]);
                 ++left;
             }
             Res = max(res, i - left + 1);
         }
         Return res;
     }
 };

Similar topics:

[LeetCode] 3.Longest Substring Without Repeating Characters Longest no repeating substring

[LeetCode] 340. Longest Substring with At Most K Distinct Characters Up to K longest substrings of different characters

All LeetCode Questions List

Posted @ 2018-03-08 07:41 Breeze dance reading ( ... ) Comments ( ... ) Edit collection
Refresh comment refresh page back to top
