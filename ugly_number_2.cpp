/*
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
Approach:
1. At each iteration, we find one number, which is multiple of one of these [2,3,5].
2. We increase the count of each number, based on result. If result%2 == 0, we increase count of 2, & so on
*/
class Solution {
public:
    int nthUglyNumber(int n) {
		vector<int> ugly_no;
		ugly_no.push_back(1);
		int no2=0, no3=0, no5=0;
		int min_;
		while(ugly_no.size() != n){
			min_ = min({ugly_no[no2]*2, ugly_no[no3]*3, ugly_no[no5]*5});
			if(min_%2 == 0) no2++;
			if(min_%3 == 0) no3++;
			if(min_%5 == 0) no5++;
			ugly_no.push_back(min_);
            // cout<<min_<<" ";
		}
		return ugly_no.back();
    }
};