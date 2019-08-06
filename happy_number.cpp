class Solution {
public:
    int util(int n){
        int ans = 0;
        while(n != 0){
            // cout<< n%10 <<" ";
            ans += (n%10)*(n%10);
            n = n/10;
        }
        // cout<<ans<<" \n";
        return ans;
    }
    bool isHappy(int n) {
        unordered_map<int, int> my_map;
        int temp;
        my_map[n] = 1;
        while(n != 1){
            // cout<<n<<" ";
            temp = util(n);
            if(my_map.find(temp) != my_map.end()) return false;
            else my_map[temp] = 1;
            n = temp;
        }
        return true;
    }
};

we can simply adapt the Floyd Cycle detection algorithm. I believe that many people have seen this in the Linked List Cycle detection problem. The following is my code:

int digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while(slow != fast);
    if (slow == 1) return 1;
    else return 0;
}