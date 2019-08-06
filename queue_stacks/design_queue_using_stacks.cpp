/*
Approach:
We keep two stacks, one for mainting push and other for popping.
1. While pushing, we push the element in stack s1, first and then we clear s2 and push all element in s2.
2. While popping, we pop from s2 and clear s1 and push all element from s2 to s1.
*/
void insert_s1_to_s2(stack<int> s1, stack<int> &s2){
	while(!s2.empty()) s2.pop();
	while(!s1.empty()){
		s2.push(s1.top());
		s1.pop();
	}
}

void insert_s2_to_s1(stack<int> &s1, stack<int> s2){
	while(!s1.empty()) s1.pop();
	while(!s2.empty()){
		s1.push(s2.top());
		s2.pop();
	}
}

void print(stack<int> s1, stack<int> s2){
    cout<<"\n first stack: ";
    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<"\n second stack: ";
    while(!s2.empty()){
        cout<<s2.top()<<" ";
        s2.pop();
    }
}

class MyQueue {
public:
    stack<int> s1, s2;
    /** Initialize your data structure here. */
    MyQueue() {
        while(!s1.empty()) s1.pop();
        while(!s2.empty()) s2.pop();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
        insert_s1_to_s2(s1, s2);
        // print(s1, s2);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!s2.empty()){
        	int top = s2.top();
        	s2.pop();
        	insert_s2_to_s1(s1, s2);
            return top;
        }
        return -1;
    }
    
    /** Get the front element. */
    int peek() {
        if(!s2.empty()) return s2.top();
        return -1;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (s1.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */