/*
Method-1: Enqueue takes constant time, Dequeue is O(n)

void enqueue(int x):
    1. Push x to InputStack.

int dequeue():
    1. IF (both InputStack and OutputStack are empty) THEN error.
    2. IF (OutputStack is empty)
       Pop all elements from InputStack and push them into OutputStack (one element at a time).
    3. Pop element from OutputStack and return.



Method-2: Enqueue is O(n), Dequeue takes constant time

void enqueue(int x):
    1. Pop everything from OutputStack and push it into InputStack.
    2. Push x into InputStack.
    3. Pop everything out from InputStack and push it into OutputStack.

int dequeue():
    1. IF (OutputStack is empty) THEN error.
    2. Pop element from OutputStack and return.

Method-3: Mixed Approach

Here, we keep the data in one stack only (either InputStack or OutputStack) and hence we optimize consecutive operation

void enqueue(int x):
    1. IF (OutputStack IS Non-Empty)
            Pop everything from OutputStack and push it into InputStack.
    2. Push x into InputStack.

int dequeue():
    1. IF (InputStack is Non-Empty) 
            Pop everything from InputStack and push it into OutputStack. 
    2. IF (OutputStack is Empty) 
            Return ERROR
       ELSE
            Pop element from OutputStack and return.
*/
