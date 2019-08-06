


    Suppose there are n distinct elements to be used in Max heap. Now it is for sure that the maximum element among this n distinct element will surely be placed on the root of the heap.

    Now there will be remaining (n-1) elements to be arranged.

    Now point to be remembered here is that the structure of the heap will remain the same. That is only the values within the node will change however the overall structure remaining the same.

    As structure of the heap remains the same, the number of elements that are present in the left sub-tree of the root (L) will be fixed. And similarly the number of the elements on the right sub-tree (R) of the root. And also following equality holds .

    L + R = (n-1) 

    Now as all the remaining (n-1) elements are less than the element present at the root(The Max Element), whichever L elements among ‘n-1` elements we put in the left sub-tree, it doesn’t matter because it will satisfy the Max Heap property.

    So now there are (n-1)CL ways to pickup L elements from (n-1) elements. And then recurse the solution.

    So final equation will be as follows :

    (n-1)CL * getNumberOfMaxHeaps(L) * getNumberOfMaxHeaps(R) 

    So now the question remains only of finding L for given n. It can be found as follows:

    Find the height of the heap h = log2(n)

    Find the max number of elements that can be present in the hth level of any heap . Lets call it m. m = 2h

    Find the number of elements that are actually present in last level(hth level) in heap of size n. Lets call it p. p = n - (2h - 1)

    Now if the last level of the heap is more than or equal to exactly half filled, then L would be 2h - 1

    However if it is half filled then it will reduced by the number of elements in last level left to fill exactly half of the last level.

    So final equation for L will be as follows :

    L = 2h - 1 if p >= m/2
                        = 2h - 1 - (m/2 - p) if p<(m/2) 



// CPP program to count max heaps with n distinct keys 
#include <iostream> 
using namespace std; 
  
#define MAXN 105 // maximum value of n here 
  
// dp[i] = number of max heaps for i distinct integers 
int dp[MAXN];  
  
// nck[i][j] = number of ways to choose j elements 
//             form i elements, no order */ 
int nck[MAXN][MAXN];  
  
// log2[i] = floor of logarithm of base 2 of i 
int log2[MAXN];  
  
// to calculate nCk 
int choose(int n, int k) 
{ 
    if (k > n) 
        return 0; 
    if (n <= 1) 
        return 1; 
    if (k == 0) 
        return 1; 
  
    if (nck[n][k] != -1) 
        return nck[n][k]; 
  
    int answer = choose(n - 1, k - 1) + choose(n - 1, k); 
    nck[n][k] = answer; 
    return answer; 
} 
  
// calculate l for give value of n 
int getLeft(int n) 
{ 
    if (n == 1) 
        return 0; 
  
    int h = log2[n]; 
  
    // max number of elements that can be present in the  
    // hth level of any heap 
    int numh = (1 << h); //(2 ^ h) 
  
    // number of elements that are actually present in 
    // last level(hth level) 
    // (2^h - 1) 
    int last = n - ((1 << h) - 1); 
  
    // if more than half-filled 
    if (last >= (numh / 2)) 
        return (1 << h) - 1; // (2^h) - 1 
    else
        return (1 << h) - 1 - ((numh / 2) - last); 
} 
  
// find maximum number of heaps for n 
int numberOfHeaps(int n) 
{ 
    if (n <= 1) 
        return 1; 
  
    if (dp[n] != -1) 
        return dp[n]; 
  
    int left = getLeft(n); 
    int ans = (choose(n - 1, left) * numberOfHeaps(left)) *  
                             (numberOfHeaps(n - 1 - left)); 
    dp[n] = ans; 
    return ans; 
} 
  
// function to initialize arrays 
int solve(int n) 
{ 
    for (int i = 0; i <= n; i++) 
        dp[i] = -1; 
  
    for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= n; j++) 
            nck[i][j] = -1; 
  
    int currLog2 = -1; 
    int currPower2 = 1; 
  
    // for each power of two find logarithm 
    for (int i = 1; i <= n; i++) { 
        if (currPower2 == i) { 
            currLog2++; 
            currPower2 *= 2; 
        } 
        log2[i] = currLog2; 
    } 
  
    return numberOfHeaps(n); 
} 
  
// driver function 
int main() 
{ 
    int n = 10; 
    cout << solve(n) << endl; 
    return 0; 
} 


// #include <bits/stdc++.h>
// using namespace std;

// long long int facto(int n){
// 	if(n==1){
// 		return 1;
// 	}
// 	return n*facto(n-1);
// }

// long long int get_comb(int n, k){
// 	if(n-k < k){
// 		k = n-k;
// 	}
// 	long long int num = 1;
// 	for(int i=0; i<k; i++){
// 		num *= n;
// 		n--;
// 	}

// 	long long int den = facto(k);
// 	return num/den;
// }

// long long int rec(int n){
// 	if(n==1){
// 		return 1;
// 	}
// 	return get_comb(n)
// }

// void count_ways_to_form_max_heap(int n){
// 	long long int count = rec(n);
// }


// int main()
// {
// 	int test;
// 	cin>>test;
// 	while(test--){
// 		int n;
// 		cin>>n;
// 		count_ways_to_form_max_heap(n);
// 	}
// 	return 0;
// }





//
     

#define MAXN 105

long long int dp[MAXN];  	/* dp[i] = number of max heaps for i distinct integers */
long long int nck[MAXN][MAXN];	/* nck[i][j] = i choose j if i>=j else 0 */
int log_2[MAXN];			/* log_2[i] = int(log_2 base 2 of i) */
long long int MOD = 1000000007;

long long int choose(int n,int k)
{
        if(k>n)
            return 0;
	if(n<=1)
	    return 1;
	if(k==0)
	    return 1;

        if(nck[n][k]!=-1)
            return nck[n][k];
        long long int answer = choose(n-1,k-1) + choose(n-1,k);
        answer%=MOD;
        nck[n][k] = answer;
        return answer;
}
    
int getL(int n)
{
        if(n==1)
            return 0;
            
        int h = log_2[n];
        int p = n - ((1<<(h)) - 1);
        int m = (1<<h);
        if(p>=(m/2))
            return (1<<(h)) - 1;
        else
            return (1<<(h)) - 1 - ((m/2) - p);
}

long long int getNumberOfMaxHeaps(int n)
{
        if(n<=1)
            return 1;
            
        if(dp[n]!=-1)
            return dp[n];

        int L = getL(n);
        long long int ans = (choose(n-1,L)*getNumberOfMaxHeaps(L))%MOD*(getNumberOfMaxHeaps(n-1-L));
        ans%=MOD;
        dp[n] = ans;
        return ans;
}

    
int Solution::solve(int n)
{
        for(int i=0;i<=n;i++)
            dp[i]=-1;
            
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                nck[i][j] = -1;
                
        int currlog_2Answer = -1;
        int currPower2 = 1;
        for(int i=1;i<=n;i++)
        {
	    if(currPower2==i)
            {
                currlog_2Answer++;
                currPower2*=2;
            }
            log_2[i] = currlog_2Answer;
        }
        
        return (int)getNumberOfMaxHeaps(n);
}

