
/*
Moree-counting algorithm for majority element (> n/2)
*/
// new try
int majorityElement(vector<int>& arr){
    int n = arr.size(), result = 0;
    for(int b=0, mask=1; b<=31; b++, mask=mask<<1){
        int bit = 0;
        for(int i=0; i<n; i++){
            if(arr[i]&mask) bit++;
        }
        if(bit > n/2) result = result|mask;
    }
    // confirm, if this is the majority element
    int count = 0;
    for(auto a : arr){
        if(a == result) count++;
    }
    if(count <= n/2) result = -1;
    return result;
}



// old but gold

class Solution {
public:
    int usingMemory(vector<int> nums){
        unordered_map<int, int> myMap;
        int k = nums.size()/2;
        for(auto a : nums){
            myMap[a]++;
            if(myMap[a] > k) return a;
        }
        for(auto itr : myMap){
            if(itr.second > k) return itr.first;
        }
        return -1;
    }
    
    int bitMasking(vector<int>& nums) {
        int majority = 0;
        for (unsigned int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
            int bits = 0;
            for (int num : nums) {
                if (num & mask) {
                    bits++;
                }
            }
            if (bits > nums.size() / 2) {
                majority |= mask;
            }
        }
        return majority;
    }
    
    int majorityElement(vector<int>& nums) {
        return usingMemory(nums);
        return bitMasking(nums);
    }
};