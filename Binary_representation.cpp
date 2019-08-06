
#include<bits/stdc++.h> 
using namespace std; 

// iterative
void bin(unsigned n) { 
    unsigned i; 
    for (i = 1 << 31; i > 0; i = i / 2) 
        (n & i)? printf("1"): printf("0"); 
} 

// recurive
void bin(unsigned n) { 
    /* step 1 */
    if (n > 1) 
        bin(n/2); 
  
    /* step 2 */
    cout << n % 2; 
} 
  
// another recursive approach
void bin(unsigned n) { 
	if (n > 1) 
	bin(n>>1); 
	
	printf("%d", n & 1); 
} 

// Driver code 
int main(void) 
{ 
	bin(439); 
	printf("\n"); 
	bin(3); 
	return 0; 
} 