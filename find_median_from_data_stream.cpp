https://leetcode.com/problems/find-median-from-data-stream/

/*
- Maintain lower half and upper half in two buckets
- To make decision about current element, we need boundary element from each bucket
    1. Max from lower bucket
    2. Min from upper bucket
*/
class MedianFinder {
public:
    priority_queue<int> left_half; //max_heap
    priority_queue<int, vector<int>, greater<int>> right_half;
    /** initialize your data structure here. */
    MedianFinder() {
        while(!left_half.empty()) left_half.pop();
        while(!right_half.empty()) right_half.pop();
    }
    
    void maintain_it(int num){
        // num > left_half.top, push in right half
        // else swap them
        if(num > left_half.top()) right_half.push(num);
        else{
            right_half.push(left_half.top());
            left_half.pop();
            left_half.push(num);
        }
    }
    
    void addNum(int num) {
        // maintain first 2 element properly
        if(left_half.empty()) left_half.push(num);
        else if(right_half.empty()) maintain_it(num);
        else{
            // first push num in appropriate bucket
            if(num > left_half.top()) right_half.push(num);
            else left_half.push(num);
            // now rebalance both buckets
            if(left_half.size() > right_half.size() + 1 ){
                right_half.push(left_half.top());
                left_half.pop();
            }
            else if(right_half.size() > left_half.size() + 1 ){
                left_half.push(right_half.top());
                right_half.pop();
            }
            else{ }
        }
    }
    
    double findMedian() {
        double left_top, right_top;
        if(left_half.size() == right_half.size()){
            left_top = left_half.top();
            right_top = right_half.top();
            return (left_top + right_top)/2;
        }
        else if(left_half.size() > right_half.size()){
            left_top = left_half.top();
            return left_top;
        }
        else{
            right_top = right_half.top();
            return right_top;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */




// old one 
/*
Idea is to maintain maxHeap and minHeap such that, 
    maxHeap maintains lower half of array and minHeap maintains upper half
    1. if el is lower than root of maxHeap, push in it, else push in minheap
    2. if diff of heap size vary by more than 1, we need to balance it.
*/
class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int minSize, maxSize;
    /** initialize your data structure here. */
    MedianFinder() {
        minSize = 0;
        maxSize = 0;
    }
    
    void addNum(int num) {
        if(maxHeap.empty()) maxHeap.push(num);
        else if(minHeap.empty()){
            if(maxHeap.top() > num){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
            else minHeap.push(num);
        }
        else{
            if(num < maxHeap.top()) maxHeap.push(num);
            else minHeap.push(num);
            
            // balance it
            minSize = minHeap.size();
            maxSize = maxHeap.size();
            if(abs(minSize - maxSize) > 1){
                if(minHeap.size() > maxHeap.size()){
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                }
                else{
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                }
            }
        }
    }
    
    double findMedian() {
        minSize = minHeap.size();
        maxSize = maxHeap.size();
        if(minSize > maxSize) return (double)minHeap.top();
        else if(minSize < maxSize) return (double)maxHeap.top();
        else return ((double)maxHeap.top() + (double)minHeap.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */