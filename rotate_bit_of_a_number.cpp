
#include <bits/stdc++.h>
using namespace std;

void left_rotate(int n, int k){
	int left_bits = 0;
	for(int i=7; i>7-k; i--){
		left_bits += pow(2,i);
	}

	left_bits = (left_bits & n);
	left_bits = left_bits >> (8-k);
	n = n<<k;
	cout<<"Left Shifted Number: "<< (n|left_bits)<<endl;

}

void right_rotate(int n, int k){
	int right_bits = 0;
	for(int i=0; i<k; i++){
		right_bits += pow(2,i);
	}

	right_bits = (right_bits & n);
	right_bits = right_bits << (8-k);
	n = n>>k;
	cout<<"right Shifted Number: "<< (n|right_bits)<<endl;

}

void rotate_bits(){
	int n, k;
	cin>>n>>k;
	string operation;
	cin>>operation;

	// if(operation.compare('left')){
	if(operation == "left"){
		left_rotate(n, k);
	}
	else{
		right_rotate(n, k);
	}
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		rotate_bits();
	}
	return 0;
}










// C++ code to rotate bits  
// of number 
#include<iostream> 
  
using namespace std; 
#define INT_BITS 32 
class gfg 
{ 
      
/*Function to left rotate n by d bits*/
public: 
int leftRotate(int n, unsigned int d) 
{ 
      
    /* In n<<d, last d bits are 0. To 
     put first 3 bits of n at  
    last, do bitwise or of n<<d  
    with n >>(INT_BITS - d) */
    return (n << d)|(n >> (INT_BITS - d)); 
} 
  
/*Function to right rotate n by d bits*/
int rightRotate(int n, unsigned int d) 
{ 
    /* In n>>d, first d bits are 0.  
    To put last 3 bits of at  
    first, do bitwise or of n>>d 
    with n <<(INT_BITS - d) */
    return (n >> d)|(n << (INT_BITS - d)); 
} 
}; 
  
/* Driver code*/
int main() 
{ 
    gfg g; 
    int n = 16; 
    int d = 2; 
    cout << "Left Rotation of " << n <<  
            " by " << d << " is "; 
    cout << g.leftRotate(n, d); 
    cout << "\nRight Rotation of " << n << 
            " by " << d << " is "; 
    cout << g.rightRotate(n, d); 
    getchar(); 
}