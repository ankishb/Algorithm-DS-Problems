/*
Approach:
1. We push an element then we rotate the queue in left shift( << ) manner, for example: 1,2,3 we push 4, it becomes 3,2,1,4 and now we rotate it (size-1) times, it will be [[2,1,4,3],[1,4,3,2],[4,3,2,1]]
2. Simple pop from front
*/

// using only one queue (push operation: O(N))
class Stack {
public:
    queue<int> que;
    // Push element x onto stack.
    void push(int x) {
        que.push(x);
        for(int i=0; i<que.size()-1; ++i){
            que.push(que.front());
            que.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        que.pop();
    }

    // Get the top element.
    int top() {
        return que.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return que.empty();
    }
};





// using deque
class MyStack {
public:
    deque<int> dq;
    /** Initialize your data structure here. */
    MyStack() {
        while(!dq.empty()) dq.pop_front();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        dq.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = dq.back();
        dq.pop_back();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return dq.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return dq.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */