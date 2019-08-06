class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size() <= 1) return 0;
        sort(A.begin(), A.end());
        vector<int> dup, poss;
        int count = 0, dup_size, idx=0, num;
        for(int i=1; i<A.size(); i++){
        	if(A[i] == A[i-1]){
        		dup.push_back(A[i]);
        	}
        	else if(A[i] != A[i-1]+1 && (dup.size() - idx)>0){
                // for(auto itr : dup) cout<<itr<<" ";
                // cout<<endl;
        		// check for next possible number
        		num = A[i-1]+1;
        		while(idx < dup.size() && num != A[i]){
                    // cout<< idx <<" "<<num<<" "<<A[i]<<endl;
                    // cout<<num<<" ";
        			count += (num - dup[idx]);
        			idx++; num++;
        		}
        	}
        }
        cout<<endl;
        num = A[A.size()-1] + 1;
        while(idx < dup.size()){
            // cout<<num<<" ";
            count += (num - dup[idx]);
        	idx++; num++;
        }
        return count;
    }
};





class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    	int n = pushed.size();
    	stack<int> s;
    	// s.push(pushed[0]);
    	int pop_i = 0;
    	for(int i=0; i<n; i++){
    		s.push(pushed[i]);
    		while(!s.empty() && s.top() == popped[pop_i]){
    			s.pop();
    			pop_i++;
    		}
    	}
    	return (s.empty());
    }
};




class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int p) {
    	sort(tokens.begin(), tokens.end());
        int score=0, n=tokens.size();
        int max_score = 0;
        int lo=0, hi=n-1;
        
        while (lo <= hi && (p >= tokens[lo] || score > 0)) {
            while (lo <= hi && p >= tokens[lo]) {
                p -= tokens[lo++];
                score++;
            }

            max_score = max(max_score, score);
            if (lo <= hi && score > 0) {
                p += tokens[hi--];
                score--;
            }
        }
        return max_score;
    }
};