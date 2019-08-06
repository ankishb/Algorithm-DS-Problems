["MyCircularQueue","enQueue","enQueue","enQueue","enQueue","Rear","isFull","deQueue","enQueue","Rear"]
[[3],[1],[2],[3],[4],[],[],[],[4],[]]

[null,true,true,false,false,2147483647,true,false,false,2147483647]

[null,true,true,true,false,3,true,true,true,4]

class MyCircularQueue {
public:
    vector<int> vect;
    int front_idx, rear_idx, capacity;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        vector<int> temp(k, INT_MAX);
        vect = temp;
        temp.clear();
        front_idx = 0;
        rear_idx = k-1;
        capacity = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(!isFull()){
            rear_idx++;
            if(rear_idx == capacity){
                rear_idx = 0;
            }
            vect[rear_idx] = value;
            return true;
        }
        return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(!isEmpty()) return false;
        vect[front_idx] = INT_MAX;
        front_idx++;
        if(front_idx == capacity){
            front_idx = 0;
        }
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return vect[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        return vect[rear_idx];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(abs(rear_idx - front_idx + 1)%capacity !=0){
            if(vect[rear_idx] != INT_MAX && vect[front_idx] != INT_MAX){
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if(abs(rear_idx - front_idx + 1)%capacity !=0){
            if(vect[rear_idx] != INT_MAX || vect[front_idx] != INT_MAX){
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
