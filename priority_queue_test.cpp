
#include <bits/stdc++.h>
using namespace std;
 
void make_min_heap(){
	cout<<endl<<"---- Min Heap ----"<<endl;
	int n;
	cin>>n;
	int el;
	priority_queue<int> min_heap;
	
	for(int i=0; i<n; i++){
		cin>>el;
		min_heap.push(el);
		cout<<"--"<<min_heap.top()<<endl;
	}
	min_heap.pop();
	cout<<"--"<<min_heap.top()<<endl;

	cout<<"---- printing all elements: ----"<<endl;
	while(!min_heap.empty()){
		cout<<min_heap.top()<<" ";
		min_heap.pop();
	}
	cout<<endl;
}

void make_max_heap(){
	cout<<endl<<"---- Max Heap ----"<<endl;
	int n;
	cin>>n;
	int el;
	priority_queue<int, vector<int>, greater<int> > max_heap;
	
	for(int i=0; i<n; i++){
		cin>>el;
		max_heap.push(el);
		cout<<"--"<<max_heap.top()<<endl;
	}
	max_heap.pop();
	cout<<"--"<<max_heap.top()<<endl;

	cout<<"---- printing all elements: ----"<<endl;
	while(!max_heap.empty()){
		cout<<max_heap.top()<<" ";
		max_heap.pop();
	}
	cout<<endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		make_min_heap();
		make_max_heap();
 	}
 	return 0;
}



// program in c++ to use priority_queue with structure 
  
#include <iostream> 
#include <queue> 
using namespace std; 
#define ROW 5 
#define COL 2 
  
struct Person { 
  
    int age; 
  
    float height; 
  
    // this will used to initialize the variables 
    // of the structure 
    Person(int age, float height) 
        : age(age), height(height) 
    { 
    } 
}; 
  
// this is an strucure which implements the 
// operator overlading 
struct CompareHeight { 
    bool operator()(Person const& p1, Person const& p2) 
    { 
        // return "true" if "p1" is ordered  
        // before "p2", for example: 
        return p1.height < p2.height; 
    } 
}; 
  
int main() 
{ 
    priority_queue<Person, vector<Person>, CompareHeight> Q; 
  
    // When we use priority_queue with  structure 
    // then we need this kind of syntax where 
    // CompareAge is the functor or comparision function 
    float arr[ROW][COL] = { { 30, 5.5 }, { 25, 5 },  
                    { 20, 6 }, { 33, 6.1 }, { 23, 5.6 } }; 
  
    for (int i = 0; i < ROW; ++i) { 
  
        Q.push(Person(arr[i][0], arr[i][1])); 
  
        // insert an object in priority_queue by using 
        // the Person strucure constructor 
    } 
  
    while (!Q.empty()) { 
        Person p = Q.top(); 
        Q.pop(); 
        cout << p.age << " " << p.height << "\n"; 
    } 
    return 0; 
} 







priority_queue<Person> pq; 

To rectify the error above, we will use operator overloading to define the priority. So that priority_queue can decide how to store the structure object.

Given below is the priority_queue implementation with structure below:
filter_none

edit

play_arrow

brightness_5
// program in c++ to use priority_queue with structure 
  
#include <iostream> 
#include <queue> 
using namespace std; 
#define ROW 5 
#define COL 2 
  
struct Person { 
  
    int age; 
  
    float height; 
  
    // this will used to initialize the variables 
    // of the structure 
    Person(int age, float height) 
        : age(age), height(height) 
    { 
    } 
}; 
  
// this is an strucure which implements the 
// operator overlading 
struct CompareHeight { 
    bool operator()(Person const& p1, Person const& p2) 
    { 
        // return "true" if "p1" is ordered  
        // before "p2", for example: 
        return p1.height < p2.height; 
    } 
}; 
  
int main() 
{ 
    priority_queue<Person, vector<Person>, CompareHeight> Q; 
  
    // When we use priority_queue with  structure 
    // then we need this kind of syntax where 
    // CompareAge is the functor or comparision function 
    float arr[ROW][COL] = { { 30, 5.5 }, { 25, 5 },  
                    { 20, 6 }, { 33, 6.1 }, { 23, 5.6 } }; 
  
    for (int i = 0; i < ROW; ++i) { 
  
        Q.push(Person(arr[i][0], arr[i][1])); 
  
        // insert an object in priority_queue by using 
        // the Person strucure constructor 
    } 
  
    while (!Q.empty()) { 
        Person p = Q.top(); 
        Q.pop(); 
        cout << p.age << " " << p.height << "\n"; 
    } 
    return 0; 
} 

Output :
33 6.1
20 6
23 5.6
30 5.5
25 5

Given below is the implementation of priority_queue using Class

// program in c++ to use priority_queue with class 
#include <iostream> 
#include <queue> 
using namespace std; 
  
#define ROW 5 
#define COL 2 
  
class Person { 
  
public: 
    int age; 
  
    float height; 
  
    // this is used to initialize the variables of the class 
    Person(int age, float height) 
        : age(age), height(height) 
    { 
    } 
}; 
  
// we are doing operator overloading through this 
bool operator<(const Person& p1, const Person& p2) 
{ 
  
    // this will return true when second person  
    // has greater height. Suppose we have p1.height=5  
    // and p2.height=5.5 then the object which 
    // have max height will be at the top(or  
    // max priority) 
    return p1.height < p2.height; 
} 
  
int main() 
{ 
  
    priority_queue<Person> Q; 
  
    float arr[ROW][COL] = { { 30, 5.5 }, { 25, 5 },  
               { 20, 6 }, { 33, 6.1 }, { 23, 5.6 } }; 
  
    for (int i = 0; i < ROW; ++i) { 
  
        Q.push(Person(arr[i][0], arr[i][1])); 
  
        // insert an object in priority_queue by using 
        // the Person class constructor 
    } 
  
    while (!Q.empty()) { 
  
        Person p = Q.top(); 
  
        Q.pop(); 
  
        cout << p.age << " " << p.height << "\n"; 
    } 
    return 0; 
} 

Output :
33 6.1
20 6
23 5.6
30 5.5
25 5
