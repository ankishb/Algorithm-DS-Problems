
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        for(int i=0; i<n; i++){
        	if(hours[i] > 8) hours[i] = 1;
        	else hours[i] = 0;
        }

        int max_len = INT_MIN;
        int start=0, cur=0, ones=0, zeros=0;

        while(start < n){
        	if(hours[cur] == 0) zeros++;
        	else ones++;

        	if(ones > zeros){
        		max_len = max(max_len, ones+zeros);
        	}
        	else{
        		while(start != cur && ones <= zeros){
        			if(hours[start] == 0) zeros--;
        			else ones--;
        			start++;
        		}
        	}
        	cur++;
        }
        return max_len;
    }
}




	int longestWPI(vector<int>& hours) {
        int res = 0, score = 0, n = hours.size();
        unordered_map<int, int> seen = {{0, -1}};
        for (int i = 0; i < n; ++i) {
            score += hours[i] > 8 ? 1 : -1;
            if (score > 0) {
                res = i + 1;
            } else {
            	/*
            	If the score is a new lowest score, we record the day by seen[cur] = i.
				seen[score] means the first time we see the score is seen[score]th day.

				We want a positive score, so we want to know the first occurrence of score - 1.
				score - x also works, but it comes later than score - 1.
				So the maximum interval is i - seen[score - 1]
				*/

                if (seen.find(score) == seen.end())
                    seen[score] = i;
                if (seen.find(score - 1) != seen.end())
                    res = max(res, i - seen[score - 1]);
            }
        }
        return res;
    }



class Solution {
    public int longestWPI(int[] hours) {
        if (hours.length == 0) return 0;
        int maxLen = 0;
        Map<Integer, Integer> map = new HashMap();  // key is possible sum in hours array, value is index where that sum appears for the first time
        int sum = 0;  // sum at index i indicates the sum of hours[0:i] after transformation
		
        for (int i = 0; i < hours.length; i++) {
            sum += hours[i] > 8 ? 1 : -1;  // transform each hour to 1 or -1
            if (!map.containsKey(sum)) {
                map.put(sum, i);  // record where the sum appears for the first time
            }
			
            if (sum > 0) {  // in hours[0:i], more 1s than -1s
                maxLen = i + 1;
            } else if (map.containsKey(sum - 1)) {  // get the index j where sum of hours[0:j] is sum - 1, so that sum of hours[j+1:i] is 1
                maxLen = Math.max(maxLen, i - map.get(sum - 1));
            }            
            
        }
        
        return maxLen;
    }
}









int longestWPI(vector<int>& hours) {
    int n=hours.size();
    
    unordered_map<int,int> mp;
    int result=0,sum=0;
    for(int i=0;i<n;i++) {
        if(hours[i]>8) {
            sum++;
        }
        else {
            sum--;
        }
        
        if(sum>0)   result=i+1;
        else if(sum<=0) {
            if(mp.find(sum-1)!=mp.end()) {
                result=max(result,i-mp[sum-1]);
            }
        }
        if(mp.find(sum)==mp.end())
            mp[sum]=i;
    }
    return result;
}



class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int res = 0, cnt = 0, n = hours.size();
        for (int i = 0; i < n; ++i) {
            if (hours[i] > 8) ++cnt;
            if (cnt * 2 > i + 1) res = i + 1;
            int left = 0, curCnt = cnt;
            while (left < i && curCnt * 2 <= i - left + 1) {
                if (hours[left] > 8) --curCnt;
                ++left;
                if (curCnt * 2 > i - left + 1) res = max(res, i - left + 1);
            }
        }
        return res;
    }
};







class Solution {
public:
    int findMaxLength(vector<int>& nums) {
		int n = nums.size();
		for(int i=0; i<nums)        
    }
};