
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
// 	int a = 1025;// in 4 bytes, its 10th and 1st bit is 1, others are 0
// 	int *p; // init a pointer, which points to interger
// 	p = &a;
// 	printf("Size of integer is %d bytes\n", sizeof(int));
// 	printf("Adress = %d, value = %d\n", p, a);

// 	// tricky part
// 	char *p0;
// 	// p0 = p; //raise erro, because p is a pointer which points to integer, but p0 is pointer for character
// 	p0 = (char*)p; //typecasting
// 	printf("Size of Char is %d bytes\n", sizeof(char));
// 	printf("Adress = %d, value = %d\n", p0, *p0);
// 	printf("Adress = %d, value = %d\n", p0+1, *(p0+1)); // switch to next byte, which contains 10 bits set.
// 	return 0;
// }

// int main()
// {
// 	int A[] = {1,2,3,4,5};
// 	int i;
// 	for(int i=0; i<5; i++){
// 		printf("Address = %d\n", &A[i]);
// 		printf("Address = %d\n", (A+i));// A give base address, here i=1, will increase the address by bytes size of int i.e 4 
// 		printf("Value = %d\n", A[i]);
// 		printf("Value = %d\n", *(A+i));

// 	}
// 	return 0;
// }

// /*
// We can also do something like
// int *p = A;
// now p++, will increase the address by data-types size each time.
// */


// /*
// While passing the array to function, it only pass the first element, we give how many time, it has to loop through.
// */













// arrays are always passed to functions by pointers

#include <bits/stdc++.h>
using namespace std;

// void doubling(int arr[], int n){
// 	for (int i = 0; i < n; ++i)
// 	{
// 		arr[i] = 2*arr[i];
// 	}
// }

void doubling(int *arr, int n){
	for (int i = 0; i < n; ++i)
	{
		arr[i] = 2*arr[i];
	}
}

int main()
{
	int arr[] = {1,2,3,4,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	doubling(arr, size);
	for (int i = 0; i < size; ++i)
	{
		cout<<arr[i]<<" ";
	}
}




Strings or character always stored as one more space.
char a[4] = "JOHN"; // very bad
char a[5] = "JOHN"; // here it will store space at the end, which helps to break the loop
stlen(a)

char a[] = "JOHN"; 
stlen(a);
sizeof(a);

char a[5];
a = "john"; //invalid



char c1[6] = "Hello";
char *c2;
c2 = c1
printf("%s\n", c2[0]);

int i=1;
printf("%s\n", *(c2+i));

c2++; //works
c1++; //invalid








void print_char(char *c){
	while(*c != '\0'){
		cout<<*c;
		c++;
	}
}

void print_char(char *c){
	int i=0
	while(*(c+i) != '\0'){
		cout<<c[i];
		i++;
	}
}

void print_char(char c[]){
	c[0] = 'A'; //modify the ist character
	int i=0
	while(c[i] != '\0'){
		cout<<c[i];
		i++;
	}
}

int main()
{
	char a[] = "hello";
	print_char(a);
}





