// class Solution {
// public:
//     int reachNumber(int target) {
//         queue<pair<int,int>> q;
//         int moves, agge, piche;
//         q.push({0,1});
//         while(true){
//             pair<int,int> p = q.front();
//             q.pop();
//             if(p.first == target) return p.second-1;
//             moves = p.second+1;
//             agge = p.first+p.second;
//             piche = p.first-p.second;
//             if(agge <= target*2)
//                 q.push({agge, moves});
//             if(piche >= -target)
//                 q.push({piche, moves});
//         }
//         return -1;
//     }
// };

/*
1. We can always take abs(target), since the axis is symmetric.
2. First of all we keep adding sum=1+2+..+n>=target, solve this quadratic equation gives the smallest n such that sum>=target.
3. If 1+2+..+n==target, return n.
4. Now we must minus res=sum-target. If res is even, we can flip one number x in [1,n] to be -x.
5. Otherwise if res is odd, and n+1 is odd, we can first add n+1, then res is even. Next flip an x to be -x.
6. If res is odd and n+1 is even, we add n+1 then subtract n+2, res becomes even, then flip an x.
*/
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        long long n = ceil((-1.0 + sqrt(1+8.0*target)) / 2);
        long long sum = n * (n+1) / 2;
        if (sum == target) return n;
        long long res = sum - target;
        if ((res&1) == 0) 
            return n;
        else 
            return n+((n&1) ? 2 : 1);
        
    }
};