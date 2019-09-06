/*
1. Make a binary array, with cum_sum being odd and even
2. use count of 1's and 0's in that array, we find the number of subarray. [we add 1 in count of 1's]
3. use handshaking lemma to count subarray with even sum that is [n*(n-1)/2] that would be if two 1's present or two 0's present.
Note: reason of adding 1 in count of 1's, 
	- 1 even : ans = 1, but with lemma it is 0
	- 2 even : ans = 3, but with lemma it is 1
	- 3 even : ans = 6, but with lemma it is 3

So it is running 1 iteration late.
*/
int evenSumSubarrays(const vector<int>& vec) {
	int sum = 0, odds = 0, evens = 1; // Insert a virtual node
	for (auto it = vec.begin(), ie = vec.end(); it != ie; ++it) {
	sum = (sum + *it) % 2;
	(sum == 0) ? ++evens : ++odds;
	}
	return (evens * (evens - 1) / 2) + (odds * (odds - 1) / 2);
}