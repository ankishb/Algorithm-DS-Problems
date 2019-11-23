<!-- ---
layout: post
title: "cpp-compact-summary"
date: 2019-08-30
tag: c++
--- -->

## Imp Questions:
1. I was asked about Copy constructor and why we use Copy constructor instead of memcpy. I was also asked about virtual functions and their use. The interviewer made me write the code to explain my examples clearly. Lastly he asked about virtual memory – What is virtual memory and how it works in detail.
2. Basics about run time and compile time polymorphism. (with examples)
3. what is the need of run time polymorphism if we already have compile time polymorphism? (with example)

## The virtual table
By Alex on February 8th, 2008 | last modified by Alex on September 19th, 2019

To implement virtual functions, C++ uses a special form of late binding known as the virtual table. The virtual table is a lookup table of functions used to resolve function calls in a dynamic/late binding manner. The virtual table sometimes goes by other names, such as “vtable”, “virtual function table”, “virtual method table”, or “dispatch table”.

Because knowing how the virtual table works is not necessary to use virtual functions, this section can be considered optional reading.

The virtual table is actually quite simple, though it’s a little complex to describe in words. First, every class that uses virtual functions (or is derived from a class that uses virtual functions) is given its own virtual table. This table is simply a static array that the compiler sets up at compile time. A virtual table contains one entry for each virtual function that can be called by objects of the class. Each entry in this table is simply a function pointer that points to the most-derived function accessible by that class.

Second, the compiler also adds a hidden pointer to the base class, which we will call *__vptr. *__vptr is set (automatically) when a class instance is created so that it points to the virtual table for that class. Unlike the *this pointer, which is actually a function parameter used by the compiler to resolve self-references, *__vptr is a real pointer. Consequently, it makes each class object allocated bigger by the size of one pointer. It also means that *__vptr is inherited by derived classes, which is important.


## Page Fault Handling in Operating System

A page fault occurs when a program attempts to access data or code that is in its address space, but is not currently located in the system RAM. So when page fault occurs then following sequence of events happens :

    The computer hardware traps to the kernel and program counter (PC) is saved on the stack. Current instruction state information is saved in CPU registers.
    An assembly program is started to save the general registers and other volatile information to keep the OS from destroying it.
    Operating system finds that a page fault has occurred and tries to find out which virtual page is needed. Some times hardware register contains this required information. If not, the operating system must retrieve PC, fetch instruction and find out what it was doing when the fault occurred.
    Once virtual address caused page fault is known, system checks to see if address is valid and checks if there is no protection access problem.
    If the virtual address is valid, the system checks to see if a page frame is free. If no frames are free, the page replacement algorithm is run to remove a page.
    If frame selected is dirty, page is scheduled for transfer to disk, context switch takes place, fault process is suspended and another process is made to run until disk transfer is completed.
    As soon as page frame is clean, operating system looks up disk address where needed page is, schedules disk operation to bring it in.
    When disk interrupt indicates page has arrived, page tables are updated to reflect its position, and frame marked as being in normal state.
    Faulting instruction is backed up to state it had when it began and PC is reset. Faulting is scheduled, operating system returns to routine that called it.
    Assembly Routine reloads register and other state information, returns to user space to continue execution.

## virtual memory

Virtual memory is a memory management capability of an operating system (OS) that uses hardware and software to allow a computer to compensate for physical memory shortages by temporarily transferring data from random access memory (RAM) to disk storage. Virtual address space is increased using active memory in RAM and inactive memory in hard disk drives (HDDs) to form contiguous addresses that hold both the application and its data.

While copying virtual memory into physical memory, the OS divides memory into pagefiles or swap files with a fixed number of addresses. Each page is stored on a disk and when the page is needed, the OS copies it from the disk to main memory and translates the virtual addresses into real addresses.

## Preprocessor Vs Macro:
Lines that start with # are preprocessing directives. They are directives that tell the preprocessor to do something.

- #include, #if, #ifdef, #ifndef, #else, #elif, #endif, #define, #undef, #line, #error, and #pragma are all preprocessing directives. (A line containing only # is also a preprocessing directive, but it has no effect.)

- #define blah 8 is a preprocessing directive, it is not a macro. blah is a macro. This #define preprocessing directive defines the macro named blah as an object-like macro replaced by the token 8.


Preporcessor: the program that does the preprocessing (file inclusion, macro expansion, conditional compilation).

Macro: a word defined by the #define preprocessor directive that evaluates to some other expression.

Preprocessor directive: a special #-keyword, recognized by the preprocessor



## Memory Layout of C Programs
A typical memory representation of C program consists of following sections.
#
1. Text segment
2. Initialized data segment
3. Uninitialized data segment
4. Stack
5. Heap

1. Text Segment:
A text segment , also known as a code segment or simply as text, is one of the sections of a program in an object file or in memory, which contains executable instructions.

2. Initialized Data Segment:
Initialized data segment, usually called simply the Data Segment. A data segment is a portion of virtual address space of a program, which contains the global variables and static variables that are initialized by the programmer.

Note that, data segment is not read-only, since the values of the variables can be altered at run time.
#
3. Uninitialized Data Segment:
Data in this segment is initialized by the kernel to arithmetic 0 before the program starts executing

uninitialized data starts at the end of the data segment and contains all global variables and static variables that are initialized to zero or do not have explicit initialization in source code.
#
4. Stack:
The stack area traditionally adjoined the heap area and grew the opposite direction; when the stack pointer met the heap pointer, free memory was exhausted. (With modern large address spaces and virtual memory techniques they may be placed almost anywhere, but they still typically grow opposite directions.)Stack, where automatic variables are stored, along with information that is saved each time a function is called. Each time a function is called, the address of where to return to and certain information about the caller’s environment, such as some of the machine registers, are saved on the stack.5. Heap: Heap is the segment where dynamic memory allocation usually takes place.

The heap area begins at the end of the BSS segment and grows to larger addresses from there.The Heap area is managed by malloc, realloc, and free, which may use the brk and sbrk system calls to adjust its size (note that the use of brk/sbrk and a single “heap area” is not required to fulfill the contract of malloc/realloc/free; they may also be implemented using mmap to reserve potentially non-contiguous regions of virtual memory into the process’ virtual address space). The Heap area is shared by all shared libraries and dynamically loaded modules in a process.



#### exp:
The following declares a variable i on the stack:

int i;

When I ask for an address using &i I get the actual location on the stack.

When I allocate something dynamically using malloc, there are actually TWO pieces of data being stored. The dynamic memory is allocated on the heap, and the pointer itself is allocated on the stack. So in this code:

int* j = malloc(sizeof(int));

This is allocating space on the heap for an integer. It's also allocating space on the stack for a pointer (j). The variable j's value is set to the address returned by malloc.


## Difference between Definition and Declaration
Declaration of a variable is for informing to the compiler the following information: name of the variable, type of value it holds and the initial value if any it takes. i.e., declaration gives details about the properties of a variable. Whereas, Definition of a variable says where the variable gets stored. i.e., memory for the variable is allocated during the definition of the variable.
Declaration   Definition
A variable or a function can be declared any number of times  A variable or a function can be defined only once
Memory will not be allocated during declaration   Memory will be allocated

int f(int);

The above is a function declaration. This declaration is just for informing the compiler that a function named f with return type and argument as int will be used in the function.
  

int f(int a)
{
  return a;
} 

The system allocates memory by seeing the above function definition. 

---

## C header file:
1. stdio: standard input output
    - fopen, fclose, buffer handles
    - file read and file write
    - gets, puts, getchar
    - scanf, printf
2. conio: console input outoput
    - clrscr()
    - getch()
3. string: 
    - string manipulation: strcpy, strcat
    - basic string : strlen, strcmp
    - memcpy
4. math
5. assert
6. limits:
    - size of basic types: INT_MAX
7. time
8. stdlib:
    - dynamic memory allocation: malloc, calloc, free
    - conversion to numeric (atoi)
    - random number: rand, srand
9. threads
10. error

## C++ header files:
1. Utilies:
    - bitset: all bitwise operation
    - tuple: stoing multiple datatypes in list
2. Dynamic Memory Management:
    - new
    - memory
    - memory_resource
3. Numeric limit:
    - climit : INT_MIN, ...
4. Error handling:
    - exception
5. String
6. Contaier:
    - array, list, vector, deque, ...
7. Iterator:
8. Algorithms
9. Input-Output:
    - sstream
    - iostream
10. Regex
11. Threading
    - semaphore
    - mutux
    - thread
12. Filesystem

---
## Ascii Range:
1. Digit: `48 - 57`
2. Alphabet:
    - Upper case: `65 - 90`
    - Lower Case: `97 - 122`

> Remember `90` is the boundary, Add `7` to switch to lower case and `7` is the last digit as well for digit boundary.


## What is the difference between a macro and a function in C programming?
- The basic difference is that function is compiled and macro is preprocessed. 
- When you use a function call it will be translated into ASM CALL with all these stack operations to pass parameters and return values. When you use a MACRO, C preprocessor will translate all strings using macro and then compile.

- a macro is a preprocessor directive. This means that before your program starts compiling it will go through and process all your macros.

## Difference between template and macros?
- Templates cause code substitution, but obey a certain set of rules. That means that the compiler checks types before creating the new class/object. Macro are parsed by the Pre-processor, which only replaces text.

- So, templates will always take longer to process. The code generated by the Macro, however, can take a certain time to process.


## Advantage of C++ (OOP)?
- `Classes`: Class is a blueprint of data and functions or methods. Class does not take any space.
- Class is a user defined data type like structures and unions in C.

### There are four pillars of OOP, which are
1. `Encapsulation` (wrapping of everything in a packet(class))
2. `Data Abstraction` (display only, what world need to see, there are access modifiers: public, private or protect to do this job)
3. `Polymorphism` (don't repeat code for each data type, use template)
4. `Inheritance` (Inherit base class in other classes, there are function overloading, to edit the existed function)

## Encapsulation: 
- Wrapping of data and functions into a single unit. 
- The data is not accessible to the outside world and only those functions which are wrapping in the class can access it. 
- It is called data hiding or `information hiding`.

## Data abstraction:
- provide only needed information to the outside world and `hiding implementation` details. 
- We have `access modifiers: public, private and protect` to do this job

## Inheritance: 
- inheritance is the process by which objects of one class acquire the properties of objects of another class. 
- It provides re usability. This means that we can add additional features to an existing class without modifying it.


## Polymorphism: 
- polymorphism means ability to take more than one form. 
- An operation may exhibit different behaviors in different instances. The behavior depends upon the types of data used in the operation.
- There are `2` types of polymorphism
    1. Compile-time polymorphism
        1. Function overloading
        2. Operator overloading
    2. Run-time polymorphism
        1. Virtual function
        2. Pure Virtual Function
- C++ supports operator overloading and function overloading.
    - The process of making an operator to exhibit different behaviors in different instances is known as `operator overloading`.
    - `Function overloading` is using a single function name to perform different types of tasks.

---

## Virtual functions in C++: Runtime Polymorphism
In this guide, we will see what are virtual functions and why we use them. When we declare a function as virtual in a class, all the sub classes that override this function have their function implementation as virtual by default (whether they mark them virtual or not). Why we declare a function virtual? To let compiler know that the call to this function needs to be resolved at runtime (also known as late binding and dynamic linking) so that the object type is determined and the correct version of the function is called.

Lets take an example to understand what happens when we don’t mark a overridden function as virtual.

### Example 1: Overriding a non-virtual function
See the problem here. Even though we have the parent class pointer pointing to the instance (object) of child class, the parent class version of the function is invoked.

You may be thinking why I have created the pointer, I could have simply created the object of child class like this: Dog obj; and assigned the Dog instance to it. Well, in this example I have only one child class but when we a big project having several child classes, creating the object of child class separately is not recommended as it increases the complexity and the code become error prone. More clarity to this after this example.
```c++
#include<iostream>
using namespace std;
//Parent class or super class or base class
class Animal{
public:
   void animalSound(){
      cout<<"This is a generic Function";
   }
};
//child class or sub class or derived class
class Dog : public Animal{
public:
   void animalSound(){ 
      cout<<"Woof";
   }
};
int main(){
   Animal *obj;
   obj = new Dog();
   obj->animalSound();
   return 0;
}

Output:

This is a generic Function
```

### Example 2: Using Virtual Function
See in this case the output is Woof, which is what we expect. What happens in this case? Since we marked the function animalSound() as virtual, the call to the function is resolved at runtime, compiler determines the type of the object at runtime and calls the appropriate function.
```c++
#include<iostream>
using namespace std;
//Parent class or super class or base class
class Animal{
public:
   virtual void animalSound(){
      cout<<"This is a generic Function";
   }
};
//child class or sub class or derived class
class Dog : public Animal{
public:
   void animalSound(){ 
      cout<<"Woof";
   }
};
int main(){
   Animal *obj;
   obj = new Dog();
   obj->animalSound();
   return 0;
}

Output:

Woof
```

#### Pure virtual function:
- class with pure virtual function, called `abstract class`
- can't create object of abstract class
- Need to implement virtual function in derived class
- much cleaner abstract class defination
```c++
class ClickHandler {
public:
  virtual void OnClick()=0;
}
```



## Dynamic Binding: 
In dynamic binding, the code to be executed in response to function call is decided at runtime. C++ has virtual functions to support this.



Message Passing: Objects communicate with one another by sending and receiving information to each other. A message for an object is a request for execution of a procedure and therefore will invoke a function in the receiving object that generates the desired results. Message passing involves specifying the name of the object, the name of the function and the information to be sent.


## Access Modifiers:
- Main purpose is **Data Hiding**.
- Access modifiers or Access Specifiers in a class are used to set the accessibility of the class members. That is, it sets some restrictions on the class members not to get directly accessed by the outside functions.

There are 3 types of access modifiers available in C++:
1. Public
2. Private
3. Protected

> Note: By default the access modifier is Private.

Let us now look at each one these access modifiers in details:
### Public: 
- All the class members declared under public will be available to everyone. 
- The data members and member functions declared public can be accessed by other classes too. 
- The public members of a class can be accessed from anywhere in the program using the direct member access operator (.) with the object of that class.

### Private: 
- The class members declared as private can be accessed `only by the functions inside the class`. 
- They are not allowed to be accessed directly by any object or function outside the class. 
- Only the member functions or the `friend functions` are allowed to access the private data members of a class.
Example:
```c++
class Circle {    
// private data member 
private:  
    double radius; 
   
// public member function     
public:     
    double  compute_area(){   
    // member function can access private data member radius 
        return 3.14*radius*radius; 
    } 
}; 
  
// main function 
int main() 
{    
    Circle obj; 
      
    // trying to access private data member directly outside the class 
    obj.radius = 1.5; //raise compile time error
    cout << "Area is:" << obj.compute_area(); 
    return 0; 
} 
```

However, we can access the private data members of a class indirectly using the public member functions of the class. Below program explains how to do this:
```c++
class Circle 
{    
private:  
    double radius; 
public:     
    void compute_area(double r) {   
        // member function can access private  
        radius = r; 
        double area = 3.14*radius*radius; 
          
        cout << "Radius is:" << radius << endl; 
        cout << "Area is: " << area; 
    } 
}; 

int main() 
{    
    Circle obj; 
    obj.compute_area(1.5); 
    return 0; 
} 
```

### Protected: 
- `Protected are inaccessible outside the class`
- they can be accessed by any subclass(derived class) of that class.
- Similar bahaviour as that of private access modifier except above one case

---

## Constructor:
### What is constructor?
- A constructor is a member function of a class which initializes objects of a class. 
- In C++, they are automatically called when object(instance of class) create. It is special member function of the class.

### How constructors are different from a normal member function?
A constructor is different from normal functions in following ways:
1. Constructor has same name as the class itself
2. Constructors don’t have return type
3. A constructor is automatically called when an object is created.
4. If we do not specify a constructor, C++ compiler generates a default constructor for us (expects no parameters and has an empty body).

### Types of Constructors
#### `Default Constructors`: 
- It doesn’t take any argument.

> Note: Even if we do not define any constructor explicitly, the compiler will automatically provide a default constructor implicitly.

#### Parameterized Constructors: 
- It is possible to pass arguments to constructors. Typically, these arguments help initialize an object when it is created. To create a parameterized constructor, simply add parameters to it the way you would to any other function. When you define the constructor’s body, use the parameters to initialize the object

Uses of Parameterized constructor:
1. It is used to initialize the various data elements of different objects with different values when they are created.
2. `It is used to overload constructors.`

> we can have more than one constructors in a class as well. This is `Constructor Overloading`.

## Copy Constructor:
It is a member function which initializes an object using another object of the same class.
```c++
class Point { 
private: 
    int x, y; 
public: 
    Point(int x1, int y1) { 
        x = x1; 
        y = y1;
    } 
    // Copy constructor 
    Point(const Point &p2) {
        x = p2.x; 
        y = p2.y; 
    } 
}; 
  
int main() 
{ 
    Point p1(10, 15); // Normal constructor is called here 
    Point p2 = p1; // Copy constructor is called here 
    return 0; 
}
```

### When is copy constructor called?
In C++, a Copy Constructor may be called in following cases:
1. When an object of the class is returned by value.
2. When an object of the class is passed (to a function) by value as an argument.
3. When an object is constructed based on another object of the same class.
4. When the compiler generates a temporary object.

It is, however, not guaranteed that a copy constructor will be called in all these cases, because the C++ Standard allows the compiler to optimize the copy away in certain cases, one example is the return value optimization

> By default all members of a class are private. Since no access specifier is there for Point(), it becomes private and it is called outside the class when t1 is constructed in main. 

---

## Difference between `overloading` and `overriding`
- Overloading a method (or function) in C++ is the ability for functions of the same name to be defined as long as these methods have different signatures (different set of parameters). Method overriding is the ability of the inherited class rewriting the virtual method of the base class.

1. Function Overloading happens in the `same class` when we declare same functions with different arguments in the same class. Function Overriding is happens in the child class when `child class overrides parent class function`.
2. In function overloading function signature should be different for all the overloaded functions. In function overriding the signature of both the functions (overriding function and overridden function) should be same.
3. Overloading happens at the compile time thats why it is also known as `compile time polymorphism` while overriding happens at run time which is why it is known as `run time polymorphism`.
4. In function overloading we can have `any number of overloaded functions`. In function overriding we can have only one overriding function in the child class.
5. `Overloading does not block inheritance` from the superclass whereas overriding blocks inheritance from the superclass.
6. `Static binding` is being used for overloaded methods and `dynamic binding` is being used for overridden/overriding methods.
7. Performance: `Overloading gives better performance compared to overriding`. The reason is that the binding of overridden methods is being done at runtime.
8. `private and final methods can be overloaded but they cannot be overridden`. It means a class can have more than one private/final methods of same name but a child class cannot override the private/final methods of their base class.

---

## Difference between `Static Binding` vs `Dynamic Binding`
1. Static binding happens at compile-time while dynamic binding happens at runtime.
2. Binding of private, static and final methods always happen at compile time since these methods cannot be overridden. When the method overriding is actually happening and the reference of parent type is assigned to the object of child class type then such binding is resolved during runtime.
3. The binding of overloaded methods is static and the binding of overridden methods is dynamic.

---

## Structure:
- Assignment is allowed in c
- **no logical operation can be done**
```c++
struct book{
    char title[100];
    int total_page;
};

struct book b1;
struct book b2 = {"GOT", 100};
struct book b_arr[2] = {{"GOT1", 100}, {"GOT2", 200}};
b1 = b2; //valid
if(b1 != b2) // invalid
```

## Swapping:
- vector swapping is done in **O(1)**, whereas element wise swapping takes **O(n)** time.
- ```cpp vect1.swap(vect2)``` it swaps complete vector with the other vector with the same type and size.

---

## Set in STL:
- it is a container (**not vector**)
- with no duplicates
- data in lexical order
- For insertion, use **set_name.insert(data)**
- **find an element in O(n)** instead of **O(n)** in another container.
- Example: **how to detect, if insertion is success or failute**.
- std::set returns std::pair<iterator, bool>, where the bool is false when the insertion failed (by adding duplicate values for example).

``` c++
std::set<int> set{ 1, 2, 3 };
auto result = set.insert(1);
if (!result.second)
    std::cout << "Failed to insert element!" << std::endl;
```

---

## Time complexity Analysis:
- `Big-Oh notation: O(g(n))`: 
    - Give us `upper bound`
    - there exist a constant `c` and `no`, such that `f(n) <= g(n)` for all `n > no`, 
    - Graphically, at `n > no`, the function `c*g(n)` will cross the function `f(n)`, which act as upper bound.
- `Omega notation`: 
    - Give us `lower bound`
    - there exist a number, such that after that point, the function never cross the `omega(g(n))`
- Theta Notation: which gives a `tight bound of function`.
- For example: our algo has `T(n) = 5n*n + 3n + 1`, upper bound can be specified by 8n*n and lower bound as n*n.


## Time complexity of Sorting Algorithms:


Algorithm | Best | Average | Worst 
--- | --- | --- | --- 
| Selection Sort | Ω(n^2)       | θ(n^2)      |  O(n^2)
| Bubble Sort    | Ω(n)         | θ(n^2)      |  O(n^2)
| Insertion Sort | Ω(n)         | θ(n^2)      |  O(n^2)
| Heap Sort      | Ω(n log(n))  | θ(n log(n)) |  O(n log(n))
| Quick Sort     | Ω(n log(n))  | θ(n log(n)) |  O(n^2)
| Merge Sort     | Ω(n log(n))  | θ(n log(n)) |  O(n log(n))
| Bucket Sort    | Ω(n+k)       | θ(n+k)      |  O(n^2)
| Radix Sort     | Ω(nk)        | θ(nk)       |  O(nk)


## Tree Based Method:
- Binary Tree:

Operation | General |  Worst |
---|---|---
 Insertion |   Ω(n)     | θ(n)   |
 Deletion  |   Ω(n)     | θ(n)   |
 Search    |   Ω(n)     | θ(n)   |

- Binary Search Tree:

Operation | General |  Worst |
---|---|---
Insertion | Ω(h)       | θ(n)   |
Deletion  | Ω(h)       | θ(n)   |
Search    | Ω(h)       | θ(n)   |
-----------------------------------
- AVL/Height Balanced Tree

Operation | General |  Worst |
---|---|---
Insertion | Ω(log2n)  | θ(log2n) |
Deletion  | Ω(log2n)  | θ(log2n) |
Search    | Ω(log2n)  | θ(log2n) |

---

## Resizing Strategy in stack (optimization of capacity of array)
The resize()\verb#resize()#resize() method is called only when the size of the stack is a power of 2. There are ∼log2⁡n powers of 2 between 1 and n.

## Cycle Detection in Directed/Undirected Graph:
- In directed Graph, there is single link for each node as **u-->v**.
- In Undirected Graph, there is doubly link for each node as **u-->v && v-->v**, therefore, while checking whether the node is already visited or not, we need to consider following conidition, that the **node should not be parent of the other node, which means, the edge we are checking should not be u-->v**, it can be sth like **u-->w-->v-->u**.



## Data Types:

Data Type        |   Size (in bytes)|     Range
--- | --- | ---
short int              | 2 |          -32,768 to 32,767
unsigned short int     | 2 |          0 to 65,535
unsigned int           | 4 |          0 to 4,294,967,295
int                    | 4 |          -2,147,483,648 to 2,147,483,647
long int               | 4 |          -2,147,483,648 to 2,147,483,647
unsigned long int      | 4 |          0 to 4,294,967,295
long long int          | 8 |          -(2^63) to (2^63)-1
unsigned long long int | 8 |          0 to 18,446,744,073,709,551,615
signed char            | 1 |          -128 to 127
unsigned char          | 1 |          0 to 255
float                  | 4 |
double                 | 8 |
long double            | 12|
wchar_t                | 2 or 4 |       1 wide character

---
## Pointers:
- watch mycodeschool video lecture or checkout **Pointer_tutorial.cpp** file

## Genereic pointer type
- void pointer
- it doesn't map to any particuylar data type
- we can not dereference of void pointer.

## Lower and Upper Bound:
- It find the range of value as **[low, high)**, note that, high is excluded, so if you want to find the range of value in the array, it will be **[lower_bound, upper_bound-1]**.
```c++
int low, high;
high = upper_bound(A.begin(), A.end(), B) - A.begin();
// cout<<high;
if(A[high-1] != B){
    vector<int> vect{-1, -1};
    return vect;
}
low  = lower_bound(A.begin(), A.end(), B) - A.begin();
vector<int> vect{low, high-1};
return vect;
```

## Upper Bound:
- Index of element just greater than value.
- **For exp: [10,20,20,30], for 20 or 25, upper bound is 3.**
- It returns an iterator pointing to the first element in the range [first, last) that is greater than value, or last if no such element is found. The elements in the range shall already be sorted or at least partitioned with respect to val.

## 2d Vector initialization:
- **Method 1**:
```c++
vector<vector<int>> array_2d(rows, vector<int>(cols, 0));
// now access variable as follows:
cin>>array_2d[i][j];
```

```c++ 
vector<vector<int>> array_2d(rows);
// This is empty vector, just push element in the 2D vector as simple
vect[1].push_back(2); 
```

## Why we can't access the size of the array from the function?
- Just imagine a stack, where it store all local/global variables. Now in that stack, we already have an stored array in **main** function. After calling to function, it will create all the local varaible again, **Beautiful Part**, if we copy the entire data/array again, it is memory as well as time inefficient. So to avoid this, it **creates an pointer to that array and out statement int arr[] become int *arr that is deferencing the pointer**, and that is accessed by the function.**

## (A+i) is same as &A[i]
## *(A+i) is same as A[i]

## Iterator: (anagramic pair of string_array)
- pairs can be accessed in two ways: **(*it).first** or **it->first****
```c++
// method1
unordered_map<int, vector<int> > map_;
for(auto it=map_.begin(); it!=map_.end(); ++it){
    cout<<endl<<it->first<<" -> ";
    for(auto it2=(it->second).begin(); it2!=(it->second).end(); ++it2){
        cout<<*it2<<" ";
    }
}

// method2
for(auto it=map_.begin(); it!=map_.end(); ++it){
    cout<<endl<<(*it).first<<" -> ";
    for(auto it2=((*it).second).begin(); it2!=((*it).second).end(); ++it2){
        cout<<*it2<<" ";
    }
}
```

## Difference between string and string-stream:
```c++
string s2 = "Dragon Land";
s1.assign(s2);          // Dragon Land
s1.assign(s2, 2, 4);    // agon         | this is string
s2.assign("Window");    // Window
s2.assign("Window", 4); // Wind         | this is string-stream, where it takes size of string to init, rather than the pointer to position first.

s1.assign(4, 's');      // ssss
s1.append(" oye");      // ssss oye
s1.insert(2, " ankish ", 4)// ss ankssss oye
s1.replace(pos, size, with_whom, pos, size);
s1.replace(2, 5, s2, 3, 3); // abgn oye
s1.erase(pos, size);
s2.substr(pos, size);

```

## Pointer in struct node:
- when we create a new node, it will create an pointer which point to a node, with defined data space of struct node.
- At start head is pointing to NULL. When we create new node and fill data in it, let's say it is temp_node, we can directly do **head = temp_node**, which saves the temp_node pointer address in the head node pointer.

## Q: What is the space taken by initializing a node in tree?

## Amotized Analysis:
- It analyse the worst-case run time per operation, rather than per algorithm, can be too pessimistic.
- For example, inserting an N element in vector, takes O(n) time, but O(1), for inserting a single element.

## Dynamic Programming:
The idea is very simple, If you have solved a problem with the given input, then save the result for future reference, so as to avoid solving the same problem again.. shortly ‘Remember your Past’. If the given problem can be broken up in to smaller sub-problems and these smaller subproblems are in turn divided in to still-smaller ones, and in this process, if you observe some overlapping subproblems, then its a big hint for DP. Also, the optimal solutions to the subproblems contribute to the optimal solution of the given problem


## [set_precision_of_double] [look in c++ tutorial file]
```c++


#include <iomanip>
#include <iostream>

int main()
{
    double num1 = 3.12345678;
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(2);
    std::cout << num1 << std::endl;
    return 0;
}

```


## Difference between endl vs '\n':
- endl is exacly do what '\n' do for us, but it also do one extra operation `flush`.
- '\n' takes one byte, because it is a character, but endl doesn't need any memory.
- `flush` operation is done by calling an OS to flush the data.

## How buffer works in c++?
- Consider writing to a file. This is an expensive operation. If in your code you write one byte at a time, then each write of a byte is going to be very costly. So a common way to improve performance is to store the data that you are writing in a temporary buffer. Only when there is a lot of data is the buffer written to the file. By postponing the writes, and writing a large block in one go, performance is improved.

- **With this in mind, flushing the buffer is the act of transferring the data from the buffer to the file.**

## Why to use **const** while writing an customize operator like comparator for sorting.
- It is passing by refernce operator.
- Let's say you have an vector of 1000 element, if we don't use pass by reference, which will copy the current element in local variable and operate the operation. Which is time consuming, as of storing the variable.



## A important theorm:
- **if i1 < i2 && j1 < j2, then max(|i1 - j1|, |i2 - j2|) <= max(|i1 - j2|, |i2 - j1|)**

## Greedy Algorithm Vs Dynamic Programming

Feature | Greedy method | Dynamic programming
---- | --- | --- 
Feasibility | In a greedy Algorithm, we make whatever choice seems best at the moment in the hope that it will lead to global optimal solution. | In Dynamic Programming we make decision at each step considering current problem and solution to previously solved sub probelm to calculate optimal solution .
Optimality | In Greedy Method, sometimes there is no such guarantee of getting Optimal Solution. | It is guaranteed that Dynamic Programming will generate an optimal solution as it generally considers all possible cases and then choose the best.
Recursion | A greedy method follows the problem solving heuristic of making the locally optimal choice at each stage. | A Dynamic programming is an algorithmic technique which is usually based on a recurrent formula that uses some previously calculated states.
Memorization | It is more efficient in terms of memory as it never look back or revise previous choices | It requires dp table for memorization and it increases it’s memory complexity.
Time complexity | Greedy methods are generally faster. For example, Dijkstra’s shortest path algorithm takes O(ELogV + VLogV) time.   Dynamic Programming is generally slower. For example, Bellman Ford algorithm takes O(VE) time.
Fashion | The greedy method computes its solution by making its choices in a serial forward fashion, never looking back or revising previous choices. | Dynamic programming computes its solution bottom up or top down by synthesizing them from smaller optimal sub solutions.
Strategy | Greedy algorithm follows the top-down strategy | Dynamic programming follows the bottom-up strategy
Example | Fractional knapsack | 0/1 knapsack problem

---

## Inheritance:
- `class Daughter: protected Mother;` the protected keyword, tells the inheritance level, in this case, all the members will be inherited from Mother either they are `public` or `protected` as `protected`. **Note that `private` members cann't be inherited in any child class.**

What is inherited from the base class?
In principle, a publicly derived class inherits access to every member of a base class except:
1.  constructors and its destructor
2. its assignment operator members (operator=)
3. its friends
4. its private members **I doubt it**

Access | public | protected | private
--- | --- | --- | ---
members of the same class | yes | yes | yes
members of derived class | yes | yes | no

---

## Intersting:
- class object cann't accessed, if they are initialized in if statement, because there scope is limited only in that conditional statemnt parenthesis. One way to go is that

```
int main(){
    Report header;

    if (...) {
      header = Report();
    else
      header = Report(name,company);

    // Or in a shorter way:

    Report header; // calls default constructor

    if (shouldInitializeWithParams) {
      header = Report(name,company);
    }
}
```





## Types of Inheritance:
1. single inheitance

2. multilevel inheritance
```
    india
     ||
    Asia
     ||
    World
```
3. Multiple Inheritance
```
           Bird
        /        \
    sparrow     parrot
```
4. Hierarchical
```
           world
        /          \
    India          USA
    /    \        /   \
```
5. Hybrid:
    - **Multiple + multilevel**
    - **Hierarchical + Multiple**
```
         class A
      /     |     \
class B     |     Class D
      \     |    /
         class C
```



## sizeof()
limit.h
float.h

## Enum DataType
- Syntax: `enum boolean {NO, YES}`;
- By default it start with 0 for these variable
- Syntax `enum months {Jan=1, Feb, Mar, Apr}`;
- Usuage in `Better readability of code` for exp `month==2`, can be misleading where as `month==Feb`, make more sense
- #define No 0
- enumeration has a scoping rule, where hash define doesn't. That's why enum is prefered
- Also in #define, we need to declare each element separately, where enum has property to assign value in increasing order.


## Constant DataType
- int: 1234
- long int: 1234l
- float: 12.34
- octal: 037 `number starting with 0` ie 3*8 + 7
- hexadeciaml: 0x12: `number starting with 0x`
- long octal: 0x12l `last digit is L`
- character: `x`

`const float pi = 3.14` or `#define pi 3.14`
- #define is faster, as it will replace the keyword `pi` with `3.14` where as in other case, it has to go to address of variable to fill the value



## Increment (pre and post):
- `++i`: increment n before its value is used
- `i++` increment n after the value is used
- for exp: `x = 10; y = x++; z = ++x`, their result  will be `y = 10 and z = 12`
- `y = x++` is equivalent to `y = x, x += 1`. Similarly `z = ++x` is equivalent to `x += 1, z = x`
- So x is increment twice, before assigning it to `z`

## Operator
- `!` not gate
- `~` complement (~0110 = 1001)
- `&` exclusive and
- `^` bitwise explisive or
- `|` inclusive or
- `&&` logical and (condition check)
- `||` normal OR (logical)


## Storage Management:
- there are `4` sections, stack(local variable and functions), heap(dynamic memory allocation unit for variables), static and global variable, text.
- static and global variable are init by 0 (`Default`)
- local variable are init randomly.
- static variable are only init once, even we explicity declare initailization, it won't be init again.
- malloc/calloc allocates memory in **continuous blocks**. if there is no enough memory of block, it will return `NULL`.
- if also store one more bytes along with given allocated space. This extra byte store the `container size`, which is used by `free` function to free the memory space.
- realloc will reassign the memory again with the given size, it will expand the block if available, otherwise it will copy the data from previous memory to new one. For exp, we create array of 5 bytes, now we reallocates to  10 bytes. it space available, it will expand, otherwise it find 10 bytes space and copy data there.
- malloc syntax: `int *p = (int*) malloc(sizeof(int))` (int*) is type casting, sizeof(int) will be system dependent, it will assign a block of memory of size interger

```
int main()
{
    static i = 5
    if(--i){
        main();
        cout<<i<<" ";
    }
}
Output:
0 0 0 0
```


## How malloc works
- it call system node, to ask for free memory block, it will ask for some big chunk of memory not that what we ask it to
- it chops that chunk and return us the desired space. 
- if you ask for larger block, if it already has that, then it return, otherwise it will again call system to ask for memory.
- it use linked list to maintain these block of memory.
- while assigning a memory, it use `first-fit` method, (can read more about in operating system).


## structure
- no space is allocated by declaring struct
- assign memory while initailized or feeding data
- struct name call tag, which is used to call
- self refrential structure in some ds, we use it(tree, list), to create new nodes inside a node of same type
```
struct node
{
    int value;
    struct node *next;
}
```

- 
```
struct
{
    int a;
}a, y, z;
```
- better
```
struct tagName
{
    int a;
    char x;
};
struct tag1 = {1, 'd'};
struct tag2, tag3;
tag1.a = 10;
```

---

## Upper Bound: [1,2,4,5], 3 ==> index=2, value=4
- If A[mid] is greater or equal, just stay there
- if A[mid] is smaller, move leftn pointer to mid+1


## Lower Bound: [1,2,4,5], 3 ==> index=1, value=2
- If A[mid] is greater, move right pointer to mid-1
- if A[mid] is smaller or equal, just stay there

---

## Virtual Class:
- Also called as dynamic polymorphism or runtime polymorphism
- It is member function which is defined within base class and then redefined in derived class.
- when we refer to derived class using pointer or reference to class, we can call virtual function for that object.
```c++
class base{
public:
    virtual void print(){ cout<<"base class"; }
};
class derived : public base{
public:
    void print(){cout<<"derived class"; }
};

int main(){
    base *b; //base class pointer
    derived d; //object of class
    b = &d
    b->print(); //output: derived class
}

int main(){
    base *bptr; //base class pointer
    base b; //base class object
    derived d; //object of class
    bptr = &b; //reference to base class
    bptr->print(); // Output: base class
    bptr = &d; //reference to derived class
    bptr->print(); // Output: derived class
}
```

#### Main Rule to use virtual function:
1. They can be accesed only object pointer
2. It can be friend of other function
3. It must be member of same class
4. They cann't be static member
5. It can be friend of other function
6. It must be defined in base class
7. We don't have vitual constructor, but virtual deconstructor is possible.



## New/ delete operator
- var can't be deleted/free once done
- can't free/delete, if new is not used yet
- new ptr is returned, if memory is not available
```c++
int *a = new int;
*a = 200;
cout<<a;
delete a;

or 
int *a = new int(200);
```

---

## Friend class and function:
- A friend class is a class that can access the private and protected members of a class in which it is declared as friend. This is needed when we want to allow a particular class to access the private and protected members of a class. 
- Similar to friend class, this function can access the private and protected members of another class. A global function can also be declared as friend as shown in the example below:
Friend Function Example
```c++
#include <iostream>
using namespace std;
class XYZ {
private:
   int num=100;
   char ch='Z';
public:
   friend void disp(XYZ obj);
};
//Global Function
void disp(XYZ obj){
   cout<<obj.num<<endl; 
   cout<<obj.ch<<endl;
}
int main() {
   XYZ obj;
   disp(obj);
   return 0;
}

Output:

100
Z
```
    1) Friend of the class can be member of some other class.
    2) Friend of one class can be friend of another class or all the classes in one program, such a friend is known as GLOBAL FRIEND.
    3) Friend can access the private or protected members of the class in which they are declared to be friend, but they can use the members for a specific object.
    4) Friends are non-members hence do not get “this” pointer.
    5) Friends, can be friend of more than one class, hence they can be used for message passing between the classes.
    6) Friend can be declared anywhere (in public, protected or private section) in the class.

### Application:
For instance: when it is not possible to implement some function, without making private members accessible in them. This situation arises mostly in case of operator overloading.

Or another example when you want to compare two private data members of two different classes in that case you need a common function which can make use of both the private variables of different class. In that case you create a normal function and make friend in both the classes, as to provide access of theirs private variables.

---

## Diamond problem in multiple inheritance:
while using multiple inheritance, it add several copies of constructor of base class, which add ambiguity. To avoid that, we use `virtual` keyword while inheritance.

```
      A  
     / \  
    B   C  
     \ /  
      D 
```

- without virtual inheritance
```
    A   A  
    |   |
    B   C  
     \ /  
      D 
```


- Virtual inheritance means that there will be only 1 instance of the base `A` class not 2. 
- Your type `D` would have 2 vtable pointers (you can see them in the first diagram), one for `B` and one for `C` who virtually inherit `A`.  `D`'s object size is increased because it stores 2 pointers now; however there is only one `A` now.  

```c++
#include<iostream> 
using namespace std; 
class Person { 
public: 
    Person()     { cout << "Person::Person() called" << endl;   } 
}; 
  
class Faculty : virtual public Person { 
public: 
    Faculty():Person(x)   { 
       cout<<"Faculty::Faculty()called"<< endl; 
    } 
}; 
  
class Student : virtual public Person { 
public: 
    Student():Person(x) { 
        cout<<"Student::Student()called"<< endl; 
    } 
}; 
  
class TA : public Faculty, public Student  { 
public: 
    TA():Student(), Faculty(), Person()   { 
        cout<<"TA::TA()called"<< endl; 
    } 
}; 
  
int main()  { 
    TA ta1(); 
} 

Output:
without virtual keyword
    Person::Person() called
    Faculty::Faculty() called
    Person::Person() called
    Student::Student() called
    TA::TA() called

with virtual keyword
    Person::Person() called
    Faculty::Faculty() called
    Student::Student() called
    TA::TA() called

```


---

## Why is Binary Heap Preferred over BST for Priority Queue?

A typical Priority Queue requires following operations to be efficient.

    Get Top Priority Element (Get minimum or maximum)
    Insert an element
    Remove top priority element
    Decrease Key

A Binary Heap supports above operations with following time complexities:

    O(1)
    O(Logn)
    O(Logn)
    O(Logn)

heapvsbst


A Self Balancing Binary Search Tree like AVL Tree, Red-Black Tree, etc can also support above operations with same time complexities.

    Finding minimum and maximum are not naturally O(1), but can be easily implemented in O(1) by keeping an extra pointer to minimum or maximum and updating the pointer with insertion and deletion if required. With deletion we can update by finding inorder predecessor or successor.
    Inserting an element is naturally O(Logn)
    Removing maximum or minimum are also O(Logn)
    Decrease key can be done in O(Logn) by doing a deletion followed by insertion. See this for details.

So why is Binary Heap Preferred for Priority Queue?

    Since Binary Heap is implemented using arrays, there is always better locality of reference and operations are more cache friendly.
    Although operations are of same time complexity, constants in Binary Search Tree are higher.
    We can build a Binary Heap in O(n) time. Self Balancing BSTs require O(nLogn) time to construct.
    Binary Heap doesn’t require extra space for pointers.
    Binary Heap is easier to implement.
    There are variations of Binary Heap like Fibonacci Heap that can support insert and decrease-key in Θ(1) time

Is Binary Heap always better?
Although Binary Heap is for Priority Queue, BSTs have their own advantages and the list of advantages is in-fact bigger compared to binary heap.

    Searching an element in self-balancing BST is O(Logn) which is O(n) in Binary Heap.
    We can print all elements of BST in sorted order in O(n) time, but Binary Heap requires O(nLogn) time.
    Floor and ceil can be found in O(Logn) time.
    K’th largest/smallest element be found in O(Logn) time by augmenting tree with an additional field.

---

## Advanatge of STL-container
1. They are implemented correctly, and it can save time of debugging the containers
2. They are fast, and likely more efficient
3. They share common interfaces, making it quite simple to utilize different containers without looking up member function definitions
4. They are well-documented and easily understood by other developers, improving the understandability and maintainability of our projects

#### Standard Container Thread Safety
The following general thread-safety rules apply:

1. All container functions are safe to be called concurrently on different objects of the same container type (i.e. it is safe to use two different std::vector instances on two different threads
2. All const member functions can be called concurrently by different threads
3. Containers can be safely read from multiple threads if no thread is making asynchronous writes
4. Different elements in the same container can be modified concurrently, except for the elements of std::vector<bool>.
5. If an object is written to by one thread and read by other threads, the object must be protected
6. In general, iterator operations read from a container, but do not modify it, so they are thread-safe
    - Container operations that invalidate iterators are NOT thread-safe, as they modify the container


---

## What is the difference between a macro and a function in C programming?
The basic difference is that function is compiled and macro is preprocessed. When you use a function call it will be translated into ASM CALL with all these stack operations to pass parameters and return values. When you use a MACRO, C preprocessor will translate all strings using macro and then compile.

In C (and C++) a macro is a preprocessor directive. This means that before your program starts compiling it will go through and process all your macros.

## Difference between template and macros?
Templates cause code substitution, but obey a certain set of rules. That means that the compiler checks types before creating the new class/object. Macro are parsed by the Pre-processor, which only replaces text.

So, templates will always take longer to process. The code generated by the Macro, however, can take a certain time to process.




## Operator overloading
List of operators that cannot be overloaded

1> Scope Resolution Operator  (::)    
2> Pointer-to-member Operator (.*)    
3> Member Access or Dot operator  (.)    
4> Ternary or Conditional Operator (?:) 
5> Object size Operator   (sizeof) 
6> Object type Operator   (typeid) 



## Pre vs Post increment:
#### PostIncrement
```c++ 
b = x++; is really: { b = x; x++};
```

#### PreIncrement
```c++
b = ++x; is really: { x++; b = x; };
```



## In pre-increment, we just define the function overloading with void type, where as in post-increment we need to mention a int datatype in function definition
```c++
Overloading the increment operator

The operator symbol for both prefix(++i) and postfix(i++) are the same. Hence, we need two different function definitions to distinguish between them. This is achieved by passing a dummy int parameter in the postfix version.

Here is the code to demonstrate the same.

Pre-increment overloading
filter_none

edit

play_arrow

brightness_4
// C++ program to demonstrate 
// prefix increment operator overloading 
  
#include <bits/stdc++.h> 
using namespace std; 
  
class Integer { 
private: 
    int i; 
  
public: 
    // Parameterised constructor 
    Integer(int i = 0) 
    { 
        this->i = i; 
    } 
  
    // Overloading the prefix operator 
    Integer operator++() 
    { 
        Integer temp; 
        temp.i = ++i; 
        return temp; 
    } 
  
    // Function to display the value of i 
    void display() 
    { 
        cout << "i = " << i << endl; 
    } 
}; 
  
// Driver function 
int main() 
{ 
    Integer i1(3); 
  
    cout << "Before increment: "; 
    i1.display(); 
  
    // Using the pre-increment operator 
    Integer i2 = ++i1; 
  
    cout << "After pre increment: "; 
    i2.display(); 
} 
Output:

Before increment: i = 3
After pre increment: i = 4

Post-increment overloading
filter_none

edit

play_arrow

brightness_4
// C++ program to demonstrate 
// postfix increment operator overloading 
  
#include <bits/stdc++.h> 
using namespace std; 
  
class Integer { 
private: 
    int i; 
  
public: 
    // Parameterised constructor 
    Integer(int i = 0) 
    { 
        this->i = i; 
    } 
  
    // Overloading the postfix operator 
    Integer operator++(int) 
    { 
        Integer temp; 
        temp.i = i++; 
        return temp; 
    } 
  
    // Function to display the value of i 
    void display() 
    { 
        cout << "i = " << i << endl; 
    } 
}; 
  
// Driver function 
int main() 
{ 
    Integer i1(3); 
  
    cout << "Before increment: "; 
    i1.display(); 
  
    // Using the post-increment operator 
    Integer i2 = i1++; 
  
    cout << "After post increment: "; 
    i2.display(); 
} 
Output:

Before increment: i = 3
After post increment: i = 3
```


```
void init(int =1, int =2, int =3);
```
Is valid



```
Static Keyword in C++

Prerequisite : Static variables in C

Static keyword has different meanings when used with different types. We can use static keyword with:

Static Variables : Variables in a function, Variables in a class
Static Members of Class : Class objects and Functions in a class

Let us now look at each one of these use of static in details:

Static Variables

    Static variables in a Function: When a variable is declared as static, space for it gets allocated for the lifetime of the program. Even if the function is called multiple times, space for the static variable is allocated only once and the value of variable in the previous call gets carried through the next function call. This is useful for implementing coroutines in C/C++ or any other application where previous state of function needs to be stored.
    filter_none

    edit

    play_arrow

    brightness_4
    // C++ program to demonstrate  
    // the use of static Static  
    // variables in a Function 
    #include <iostream> 
    #include <string> 
    using namespace std; 
      
    void demo() 
    {  
        // static variable 
        static int count = 0; 
        cout << count << " "; 
          
        // value is updated and 
        // will be carried to next 
        // function calls 
        count++; 
    } 
      
    int main() 
    { 
        for (int i=0; i<5; i++)     
            demo(); 
        return 0; 
    } 

    Output:

    0 1 2 3 4 

    You can see in the above program that the variable count is declared as static. So, its value is carried through the function calls. The variable count is not getting initialized for every time the function is called.
    As a side note, Java doesn’t allow static local variables in functions.
    Static variables in a class: As the variables declared as static are initialized only once as they are allocated space in separate static storage so, the static variables in a class are shared by the objects. There can not be multiple copies of same static variables for different objects. Also because of this reason static variables can not be initialized using constructors.
    filter_none

    edit

    play_arrow

    brightness_4
    // C++ program to demonstrate static 
    // variables inside a class 
      
    #include<iostream> 
    using namespace std; 
      
    class GfG 
    { 
       public: 
         static int i; 
          
         GfG() 
         { 
            // Do nothing 
         }; 
    }; 
      
    int main() 
    { 
      GfG obj1; 
      GfG obj2; 
      obj1.i =2; 
      obj2.i = 3; 
        
      // prints value of i 
      cout << obj1.i<<" "<<obj2.i;    
    } 

    You can see in the above program that we have tried to create multiple copies of the static variable i for multiple objects. But this didn’t happen. So, a static variable inside a class should be initialized explicitly by the user using the class name and scope resolution operator outside the class as shown below:
    filter_none

    edit

    play_arrow

    brightness_4
    // C++ program to demonstrate static 
    // variables inside a class 
      
    #include<iostream> 
    using namespace std; 
      
    class GfG 
    { 
    public: 
        static int i; 
          
        GfG() 
        { 
            // Do nothing 
        }; 
    }; 
      
    int GfG::i = 1; 
      
    int main() 
    { 
        GfG obj; 
        // prints value of i 
        cout << obj.i;  
    } 

    Output:

    1

Static Members of Class

    Class objects as static: Just like variables, objects also when declared as static have a scope till the lifetime of program.
    Consider the below program where the object is non-static.
    filter_none

    edit

    play_arrow

    brightness_4
    // CPP program to illustrate 
    // when not using static keyword 
    #include<iostream> 
    using namespace std; 
      
    class GfG 
    { 
        int i; 
        public: 
            GfG() 
            { 
                i = 0; 
                cout << "Inside Constructor\n"; 
            } 
            ~GfG() 
            { 
                cout << "Inside Destructor\n"; 
            } 
    }; 
      
    int main() 
    { 
        int x = 0; 
        if (x==0) 
        { 
            GfG obj; 
        } 
        cout << "End of main\n"; 
    } 

    Output:

    Inside Constructor
    Inside Destructor
    End of main

    In the above program the object is declared inside the if block as non-static. So, the scope of variable is inside the if block only. So when the object is created the constructor is invoked and soon as the control of if block gets over the destructor is invoked as the scope of object is inside the if block only where it is declared.
    Let us now see the change in output if we declare the object as static.
    filter_none

    edit

    play_arrow

    brightness_4
    // CPP program to illustrate 
    // class objects as static 
    #include<iostream> 
    using namespace std; 
      
    class GfG 
    { 
        int i = 0; 
          
        public: 
        GfG() 
        { 
            i = 0; 
            cout << "Inside Constructor\n"; 
        } 
          
        ~GfG() 
        { 
            cout << "Inside Destructor\n"; 
        } 
    }; 
      
    int main() 
    { 
        int x = 0; 
        if (x==0) 
        { 
            static GfG obj; 
        } 
        cout << "End of main\n"; 
    } 

    Output:

    Inside Constructor
    End of main
    Inside Destructor

    You can clearly see the change in output. Now the destructor is invoked after the end of main. This happened because the scope of static object is through out the life time of program.
    Static functions in a class: Just like the static data members or static variables inside the class, static member functions also does not depend on object of class. We are allowed to invoke a static member function using the object and the ‘.’ operator but it is recommended to invoke the static members using the class name and the scope resolution operator.
    Static member functions are allowed to access only the static data members or other static member functions, they can not access the non-static data members or member functions of the class.
    filter_none

    edit

    play_arrow

    brightness_4
    // C++ program to demonstrate static 
    // member function in a class 
    #include<iostream> 
    using namespace std; 
      
    class GfG 
    { 
       public: 
          
        // static member function 
        static void printMsg() 
        { 
            cout<<"Welcome to GfG!"; 
        } 
    }; 
      
    // main function 
    int main() 
    { 
        // invoking a static member function 
        GfG::printMsg(); 
    } 

    Output:

    Welcome to GfG!


```


## Definition of static data function
```

#include <iostream> 
using namespace std; 
  
class A 
{ 
    int x; 
public: 
    A() { cout << "A's constructor called " << endl;  } 
}; 
  
class B 
{ 
    static A a; 
public: 
    B() { cout << "B's constructor called " << endl; } 
    static A getA() { return a; } 
}; 
  
A B::a;  // definition of a 
  
int main() 
{ 
    B b1, b2, b3; 
    A a = b1.getA(); 
  
    return 0; 
} 

Output:

A's constructor called
B's constructor called
B's constructor called
B's constructor called
```



```
Templates and Static variables in C++

Function templates and static variables:
Each instantiation of function template has its own copy of local static variables. For example, in the following program there are two instances: void fun(int ) and void fun(double ). So two copies of static variable i exist.
filter_none

edit

play_arrow

brightness_4
#include <iostream> 
  
using namespace std; 
  
template <typename T> 
void fun(const T& x) 
{ 
  static int i = 10; 
  cout << ++i; 
  return; 
} 
  
int main() 
{     
  fun<int>(1);  // prints 11 
  cout << endl; 
  fun<int>(2);  // prints 12 
  cout << endl; 
  fun<double>(1.1); // prints 11 
  cout << endl; 
  getchar(); 
  return 0; 
} 

Output of the above program is:

  11
  12
  11

Class templates and static variables:
The rule for class templates is same as function templates
Each instantiation of class template has its own copy of member static variables. For example, in the following program there are two instances Test and Test. So two copies of static variable count exist.
filter_none

edit

play_arrow

brightness_4
#include <iostream> 
  
using namespace std; 
  
template <class T> class Test 
{   
private: 
  T val;  
public: 
  static int count; 
  Test() 
  { 
    count++; 
  } 
  // some other stuff in class 
}; 
  
template<class T> 
int Test<T>::count = 0; 
  
int main() 
{ 
  Test<int> a;  // value of count for Test<int> is 1 now 
  Test<int> b;  // value of count for Test<int> is 2 now 
  Test<double> c;  // value of count for Test<double> is 1 now 
  cout << Test<int>::count   << endl;  // prints 2   
  cout << Test<double>::count << endl; //prints 1 
     
  getchar(); 
  return 0; 
} 

Output of the above program is:

  2
  1
```


```
Function Overloading in C++

Function overloading is a feature in C++ where two or more functions can have the same name but different parameters.

Function overloading can be considered as an example of polymorphism feature in C++.

Following is a simple C++ example to demonstrate function overloading.
filter_none

edit

play_arrow

brightness_4
#include <iostream> 
using namespace std; 
  
void print(int i) { 
  cout << " Here is int " << i << endl; 
} 
void print(double  f) { 
  cout << " Here is float " << f << endl; 
} 
void print(char const *c) { 
  cout << " Here is char* " << c << endl; 
} 
  
int main() { 
  print(10); 
  print(10.10); 
  print("ten"); 
  return 0; 
}

Output:

Here is int 10 
Here is float 10.1 
Here is char* ten 
```




```

Some interesting facts about static member functions in C++

1) static member functions do not have this pointer.
For example following program fails in compilation with error “`this’ is unavailable for static member functions “
filter_none

edit

play_arrow

brightness_4
#include<iostream> 
class Test {       
   static Test * fun() { 
     return this; // compiler error 
   } 
}; 
   
int main() 
{ 
   getchar(); 
   return 0; 
} 

2) A static member function cannot be virtual (See this G-Fact)

3) Member function declarations with the same name and the name parameter-type-list cannot be overloaded if any of them is a static member function declaration.
For example, following program fails in compilation with error “‘void Test::fun()’ and `static void Test::fun()’ cannot be overloaded ”
filter_none

edit

play_arrow

brightness_4
#include<iostream> 
class Test { 
   static void fun() {} 
   void fun() {} // compiler error 
}; 
   
int main() 
{ 
   getchar(); 
   return 0; 
} 

4) A static member function can not be declared const, volatile, or const volatile.
For example, following program fails in compilation with error “static member function `static void Test::fun()’ cannot have `const’ method qualifier ”
filter_none

edit

play_arrow

brightness_4
#include<iostream> 
class Test {       
   static void fun() const { // compiler error 
     return; 
   } 
}; 
   
int main() 
{ 
   getchar(); 
   return 0; 
} 

```



```

Pure Virtual Functions and Abstract Classes in C++

Sometimes implementation of all function cannot be provided in a base class because we don’t know the implementation. Such a class is called abstract class. For example, let Shape be a base class. We cannot provide implementation of function draw() in Shape, but we know every derived class must have implementation of draw(). Similarly an Animal class doesn’t have implementation of move() (assuming that all animals move), but all animals must know how to move. We cannot create objects of abstract classes.

A pure virtual function (or abstract function) in C++ is a virtual function for which we don’t have implementation, we only declare it. A pure virtual function is declared by assigning 0 in declaration. See the following example.
filter_none

edit

play_arrow

brightness_4
// An abstract class 
class Test 
{    
    // Data members of class 
public: 
    // Pure Virtual Function 
    virtual void show() = 0; 
    
   /* Other members */
}; 

A complete example:
A pure virtual function is implemented by classes which are derived from a Abstract class. Following is a simple example to demonstrate the same.
filter_none

edit

play_arrow

brightness_4
#include<iostream> 
using namespace std; 
  
class Base 
{ 
   int x; 
public: 
    virtual void fun() = 0; 
    int getX() { return x; } 
}; 
  
// This class inherits from Base and implements fun() 
class Derived: public Base 
{ 
    int y; 
public: 
    void fun() { cout << "fun() called"; } 
}; 
  
int main(void) 
{ 
    Derived d; 
    d.fun(); 
    return 0; 
} 

Output:

fun() called

Some Interesting Facts:
1) A class is abstract if it has at least one pure virtual function.
In the following example, Test is an abstract class because it has a pure virtual function show().
filter_none

edit

play_arrow

brightness_4
// pure virtual functions make a class abstract 
#include<iostream> 
using namespace std; 
  
class Test 
{ 
   int x; 
public: 
    virtual void show() = 0; 
    int getX() { return x; } 
}; 
  
int main(void) 
{ 
    Test t; 
    return 0; 
} 

Output:

Compiler Error: cannot declare variable 't' to be of abstract
 type 'Test' because the following virtual functions are pure 
within 'Test': note:     virtual void Test::show() 

2) We can have pointers and references of abstract class type.
For example the following program works fine.
filter_none

edit

play_arrow

brightness_4
#include<iostream> 
using namespace std; 
  
class Base 
{ 
public: 
    virtual void show() = 0; 
}; 
  
class Derived: public Base 
{ 
public: 
    void show() { cout << "In Derived \n"; } 
}; 
  
int main(void) 
{ 
    Base *bp = new Derived(); 
    bp->show(); 
    return 0; 
}

Output:

In Derived 

3) If we do not override the pure virtual function in derived class, then derived class also becomes abstract class.
The following example demonstrates the same.
filter_none

edit

play_arrow

brightness_4
#include<iostream> 
using namespace std; 
class Base 
{ 
public: 
    virtual void show() = 0; 
}; 
  
class Derived : public Base { }; 
  
int main(void) 
{ 
  Derived d; 
  return 0; 
}

Compiler Error: cannot declare variable 'd' to be of abstract type 
'Derived'  because the following virtual functions are pure within
'Derived': virtual void Base::show() 

4) An abstract class can have constructors.
For example, the following program compiles and runs fine.
filter_none

edit

play_arrow

brightness_4
#include<iostream> 
using namespace std; 
  
// An abstract class with constructor 
class Base 
{ 
protected: 
   int x; 
public: 
  virtual void fun() = 0; 
  Base(int i) { x = i; } 
}; 
  
class Derived: public Base 
{ 
    int y; 
public: 
    Derived(int i, int j):Base(i) { y = j; } 
    void fun() { cout << "x = " << x << ", y = " << y; } 
}; 
  
int main(void) 
{ 
    Derived d(4, 5); 
    d.fun(); 
    return 0; 
} 

Output:

x = 4, y = 5

Comparison with Java
In Java, a class can be made abstract by using abstract keyword. Similarly a function can be made pure virtual or abstract by using abstract keyword. See
Abstract Classes in Java for more details.

Interface vs Abstract Classes:
An interface does not have implementation of any of its methods, it can be considered as a collection of method declarations. In C++, an interface can be simulated by making all methods as pure virtual. In Java, there is a separate keyword for interface
```


## Sorting algorithms
See also: Sorting algorithm § Comparison of algorithms
Algorithm   Data structure  Time complexity:Best    Time complexity:Average     Time complexity:Worst   Space complexity:Worst
Quick sort  Array   O(n log(n))     O(n log(n))     O(n2)   O(n)
Merge sort  Array   O(n log(n))     O(n log(n))     O(n log(n))     O(n)
Heap sort   Array   O(n)    O(n log(n))     O(n log(n))     O(1)
Smooth sort     Array   O(n)    O(n log(n))     O(n log(n))     O(1)
Bubble sort     Array   O(n)    O(n2)   O(n2)   O(1)
Insertion sort  Array   O(n)    O(n2)   O(n2)   O(1)
Selection sort  Array   O(n2)   O(n2)   O(n2)   O(1)
Bogo sort   Array   O(n)    O(n n!)     O(∞)    O(1) 




Quicksort is usually the fastest on average, but It has some pretty nasty worst-case behaviors. So if you have to guarantee no bad data gives you O(N^2), you should avoid it.

Merge-sort uses extra memory, but is particularly suitable for external sorting (i.e. huge files that don't fit into memory).

Heap-sort can sort in-place and doesn't have the worst case quadratic behavior, but on average is slower than quicksort in most cases.

Where only integers in a restricted range are involved, you can use some kind of radix sort to make it very fast.

In 99% of the cases, you'll be fine with the library sorts, which are usually based on quicksort.


---
If the data set is small, both the sorting algorithms are fast and differences are not noticeable. However, when the data sets are very large compare to the main memory that one has ( hence, the cache memory compared to the full main memory ) locality matters.

Mergesort : Merge sort takes advantage of the ease of merging already sorted lists into a new sorted list. It starts by comparing every two elements (i.e., 1 with 2, then 3 with 4...) and swapping them if the first should come after the second. It then merges each of the resulting lists of two into lists of four, then merges those lists of four, and so on; until at last two lists are merged into the final sorted list

Heapsort : Heapsort is a much more efficient version of selection sort. It also works by determining the largest (or smallest) element of the list, placing that at the end (or beginning) of the list, then continuing with the rest of the list, but accomplishes this task efficiently by using a data structure called a heap. Once the data list has been made into a heap, the root node is guaranteed to be the largest (or smallest) element. When it is removed and placed at the end of the list, the heap is rearranged so the largest element remaining moves to the root.

1. Merger sort is stable while heap sort is not stable because operations on the heap can change the relative order of equal items.

2. Heap Sort is more memory efficient and also in place. It doesn't copy the array and store it elsewhere (like merge sort) hence needs less space. It can use used in situations like what's the top 10 numbers from a list of 1 million numbers.

3. Heapsort may make more comparisons than optimal. Each siftUp operation makes two comparisons per level, so the comparison bound is approximately 2n log_2 n. In practice heapsort does only slightly worse than quicksort.

4. Space Complexity

    Merge sort : O(n)

    Heap sort : O(1) (if done iteratively)  But we would have to heapify the array first which will take O(n) time.

5. Merge sort works best on linked lists.

---