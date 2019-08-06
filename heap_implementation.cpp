
#include<bits/stdc++.h>
using namespace std;

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

class minHeap{
public:
    int temp;
    int capacity, size;
    vector<int> heap;
    unordered_map<int,int> my_map;
    minHeap(int N){
        capacity = N;
        size = 0;
        heap.resize(N);
    }
    int parent(int i){ return (i-1)/2; }
    int leftChild(int i){ return (2*i + 1); }
    int rightChild(int i){ return (2*i + 2); }
    int minElement(){ return heap[0]; }
    
    void removeMin(){
        /*
        1. if only 1 element, delete it
        2. if size > 1, remove it and heapify
        */
        my_map[heap[size-1]] = 0;
        heap[0] = heap[size-1];
        size--;
        minHeapify(0);
        // return top;
    }

    void minHeapify(int ref){
        int l = leftChild(ref);
        int r = rightChild(ref);
        if(l < size && heap[l] < heap[ref]){
            temp = my_map[heap[ref]];
            my_map[heap[ref]] = l;
            my_map[heap[l]] = temp;

            swap(heap[ref], heap[l]);
            minHeapify(l);
        }
        else if(r < size && heap[r] < heap[ref]){
            temp = my_map[heap[ref]];
            my_map[heap[ref]] = r;
            my_map[heap[r]] = temp;

            swap(heap[ref], heap[r]);
            minHeapify(r);
        }
    }

    void addValue(int idx, int newValue){
        heap[idx] = newValue;
        my_map[newValue] = idx;
        int pIdx = parent(idx);
        while(idx!=0 && heap[pIdx] > heap[idx]){
            temp = my_map[heap[idx]];
            my_map[heap[idx]] = pIdx;
            my_map[heap[pIdx]] = temp;
            
            swap(heap[idx], heap[pIdx]);
            idx = pIdx;
        }
    }

    void deleteElement(int value){
        /*
        // there are 3 steps
        1. first replace the value of index to minimum
        2. replace with top element
        3. remove it from top && heapify the array
        */ 
        int index = my_map[value];
        addValue(index, INT_MIN);
        removeMin();
        my_map.erase(value);
    }

    void insertElement(int value){
        if(size == capacity) return;
        size++;
        addValue(size-1, value);
    }

};

long int stringToInt(string s){
    long int ans = 0;
    for(int i=2; i<s.length(); i++){
        ans = ans*10 + (s[i]-'0');
    }
    return ans;
}

int main()
{
    minHeap heap(100005);
    int n, query;
    long int value;
    string s;
    getline(cin, s);
    n = s[0] - '0';
    for(int i=0; i<n; i++){
        getline(cin, s);
        if(s[0]-'0' == 1){
            value = stringToInt(s);
            heap.insertElement(value);
        }
        else if(s[0]-'0' == 2){
            value = stringToInt(s);
            heap.deleteElement(value);
        }
        else if(s[0]-'0' == 3){
            cout<<heap.minElement()<<endl;
        }
    }
    return 0; 
}