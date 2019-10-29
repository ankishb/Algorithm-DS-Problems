struct List{
    int value;
    List* next;
    List* prev;
    List(int v) : value(v), next(NULL), prev(NULL){}
};

class LRUCache {
public:
    List* start = NULL;
    List* end = NULL;
    int cap, size;
    unordered_map<int, int> values;
    unordered_map<int, List*> address;
    
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(size == 0) return -1;
        if(values.find(key) == values.end()) return -1;
        // delete node from list
        List* deln = address[key];
        if(start == deln){
            start = start->next;
        }
        else{
            List* prev = deln->prev;
            List* next = deln->next;
            if(prev != NULL) prev->next = next;
            if(next != NULL) next->prev = prev;
        }
        // create new node and put it in the end
        List* newn = new List(values[key]);
        address[key] = newn;
        if(start == NULL){
            start = newn;
            end = start;
        }
        else{
            newn->prev = end;
            end->next = newn;
            end = newn;
        }
        return values[key];
    }
    
    
    void put(int key, int value) {
        if(start == NULL){
            List* temp = new List(value);
            start = temp, end = temp;
            address[key] = temp;
            values[key] = value;
            size++;
        }
        // if key already present, delete it and put in the end
        else if(values.find(key) != values.end()){
            // delete node from list
            List* deln = address[key];
            if(start == deln){
                start = start->next;
            }
            else{
                List* prev = deln->prev;
                List* next = deln->next;
                if(prev != NULL) prev->next = next;
                if(next != NULL) next->prev = prev;
            }
            // create new node and put it in the end
            List* newn = new List(value);
            address[key] = newn;
            if(start == NULL){
                start = newn;
                end = start;
            }
            else{
                newn->prev = end;
                end->next = newn;
                end = newn;
            }
        }
        
        else{
            // if size increased its capacity, delete front node
            if(size == cap){
                // delete first
                List* temp = start;
                start = start->next;
                if(start != NULL) start->prev = NULL;
                values.erase(temp->value);
                address.erase(temp->value);
                size--;
            }
            // create new node and put it in the end
            List* newn = new List(value);
            address[key] = newn;
            values[key] = value;
            if(start == NULL){
                start = newn;
                end = start;
            }
            else{
                newn->prev = end;
                end->next = newn;
                end = newn;
            }
            size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */