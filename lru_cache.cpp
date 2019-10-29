// https://www.interviewbit.com/problems/lru-cache/

int cap = 0;
unordered_map<int, int> my_map;
queue<int> q1;
queue<int> q2;

LRUCache::LRUCache(int capacity) {
    cap = capacity;
    // unordered_map<int, int> my_map;
    // queue<int> q1;
    // queue<int> q2;
    while(!q1.empty()){
        q1.pop();
    }
    while(!q2.empty()){
        q2.pop();
    }
}

int LRUCache::get(int key) {
    if(my_map.find(key) != my_map.end()){
        return -1;
    }
    while(!q1.empty()){
        int front = q1.front();
        if(front == key){
            continue;
        }
        else{
            q2.push(front);
        }
    }
    q2.push(key);
    
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
    return my_map[key];
}

void LRUCache::set(int key, int value) {
    if(cap == 0){
        // remove least recent item
        my_map.erase(key);
        //
        my_map.insert({key, value});
    }
    else if(my_map.find(key) != my_map.end()){
        my_map[key] = value;
    }
    else{
        my_map.insert({key, value});
        cap--;
    }
}
// 2 G 2 S 5 10 S 2 3 G 5