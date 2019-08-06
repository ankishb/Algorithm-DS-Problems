
(ab) mod p = ( (a mod p) (b mod p) ) mod p 

For example a = 50,  b = 100, p = 13
50  mod 13  = 11
100 mod 13  = 9

(50 * 100) mod 13 = ( (50 mod 13) * (100 mod 13) ) mod 13 
or (5000) mod 13 = ( 11 * 9 ) mod 13
or 8 = 8

Below is the implementation based on above property.

filter_none

edit

play_arrow

brightness_5
// Iterative C program to compute modular power 
#include <stdio.h> 
  
/* Iterative Function to calculate (x^y)%p in O(log y) */
int power(int x, unsigned int y, int p) 
{ 
    int res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 
  
// Driver program to test above functions 
int main() 
{ 
   int x = 2; 
   int y = 5; 
   int p = 13; 
   printf("Power is %u", power(x, y, p)); 
   return 0; 
} 










How to avoid overflow?
We can multiply recursively to overcome the difficulty of overflow. To multiply a*b, first calculate a*b/2 then add it twice. For calculating a*b/2 calculate a*b/4 and so on (similar to log n exponentiation algorithm).

// To compute (a * b) % mod
multiply(a,  b, mod)
1)  ll res = 0; // Initialize result
2)  a = a % mod.
3)  While (b > 0)
        a) If b is odd, then add 'a' to result.
               res = (res + a) % mod
        b) Multiply 'a' with 2
           a = (a * 2) % mod
        c) Divide 'b' by 2
           b = b/2  
4)  Return res 

Below is the implementation.



filter_none

edit

play_arrow

brightness_5
// C++ program for modular multiplication without 
// any overflow 
#include<iostream> 
using namespace std; 
  
typedef long long int ll; 
  
// To compute (a * b) % mod 
ll mulmod(ll a, ll b, ll mod) 
{ 
    ll res = 0; // Initialize result 
    a = a % mod; 
    while (b > 0) 
    { 
        // If b is odd, add 'a' to result 
        if (b % 2 == 1) 
            res = (res + a) % mod; 
  
        // Multiply 'a' with 2 
        a = (a * 2) % mod; 
  
        // Divide b by 2 
        b /= 2; 
    } 
  
    // Return result 
    return res % mod; 
} 
  
// Driver program 
int main() 
{ 
   ll a = 9223372036854775807, b = 9223372036854775807; 
   cout << mulmod(a, b, 100000000000); 
   return 0; 
} 

Output:

84232501249










// Function to find the greater value 
void findGreater(int a, int b) 
{ 
    long double x = (long double)a * (long double)(log((long double)(b))); 
    long double y = (long double)b * (long double)(log((long double)(a))); 
    if (y > x) { 
        cout << "a^b is greater" << endl; 
    } 
    else if (y < x) { 
        cout << "b^a is greater" << endl; 
    } 
    else { 
        cout << "Both are equal" << endl; 
    } 
} 





// CPP program to check for integer 
// overflow on multiplication 
#include <iostream> 
using namespace std; 
  
// Function to check whether there is 
// overflow in a * b or not. It returns 
// true if there is overflow. 
bool isOverflow(long long a, long long b) 
{ 
    // Check if either of them is zero 
    if (a == 0 || b == 0)  
        return false; 
      
    long long result = a * b; 
    if (a == result / b) 
        return false; 
    else
        return true; 
} 
  
// Driver code 
int main() 
{ 
    long long a = 10000000000, b = -10000000000; 
    if (isOverflow(a, b)) 
        cout << "Yes"; 
    else
        cout << "No"; 
    return 0; 
} 

Output:

Yes

Time complexity : O(1)









Chinese Remainder Theorem | Set 2 (Inverse Modulo based Implementation)

We are given two arrays num[0..k-1] and rem[0..k-1]. In num[0..k-1], every pair is coprime (gcd for every pair is 1). We need to find minimum positive number x such that:


     x % num[0]    =  rem[0], 
     x % num[1]    =  rem[1], 
     .......................
     x % num[k-1]  =  rem[k-1] 

Example:

Input:  num[] = {3, 4, 5}, rem[] = {2, 3, 1}
Output: 11
Explanation: 
11 is the smallest number such that:
  (1) When we divide it by 3, we get remainder 2. 
  (2) When we divide it by 4, we get remainder 3.
  (3) When we divide it by 5, we get remainder 1. 

We strongly recommend to refer below post as a prerequisite for this.

Chinese Remainder Theorem | Set 1 (Introduction)

We have discussed a Naive solution to find minimum x. In this article, an efficient solution to find x is discussed.


The solution is based on below formula.


x =  ( &Sum; (rem[i]*pp[i]*inv[i]) ) % prod
   Where 0 <= i <= n-1

rem[i] is given array of remainders

prod is product of all given numbers
prod = num[0] * num[1] * ... * num[k-1]

pp[i] is product of all divided by num[i]
pp[i] = prod / num[i]

inv[i] = Modular Multiplicative Inverse of 
         pp[i] with respect to num[i]

Example:

Let us take below example to understand the solution
   num[] = {3, 4, 5}, rem[] = {2, 3, 1}
   prod  = 60 
   pp[]  = {20, 15, 12}
   inv[] = {2,  3,  3}  // (20*2)%3 = 1, (15*3)%4 = 1
                        // (12*3)%5 = 1

   x = (rem[0]*pp[0]*inv[0] + rem[1]*pp[1]*inv[1] + 
        rem[2]*pp[2]*inv[2]) % prod
     = (2*20*2 + 3*15*3 + 1*12*3) % 60
     = (40 + 135 + 36) % 60
     = 11





