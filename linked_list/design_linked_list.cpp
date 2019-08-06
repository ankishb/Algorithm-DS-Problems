
class Node{
public:
    int val;
    Node* next;
    // Node* prev;
    Node(int data){
        val = data;
        next = NULL;
        // prev = NULL;
    }
};

class MyLinkedList {
public:
    Node* head;
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;

    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int i = 0;
        Node* temp = head;
        while(temp != NULL){
            if(i == index) return temp->val;
            temp = temp->next;
            i++;
        }
        cout<<index<<" "<<i<<endl;
        // if(index = i-1) return 0;
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if(head != NULL){
            Node* temp = new Node(val);
            temp->next = head;
            head = temp;
        }
        else{
            head = new Node(val);
        }
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* temp = new Node(val);
        Node* first = head;
        while(first->next != NULL){
            first = first->next;
        }
        first->next = temp;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index < 0 && head==NULL) addAtHead(val);
        if(index == 0){
            addAtHead(val);
        }
        else{
            int i = 0;
            Node* last = head;
            Node* first = NULL;
            while(i != index && last != NULL){
                first = last;
                last = last->next;
                i++;
            }
            if( i == index){
                Node* temp = new Node(val);
                first->next = temp;
                temp->next = last;
            }
        }
    }
    

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index == 0){
            head = head->next;
        }
        else{
            int i = 0;
            Node* last = head;
            Node* first = NULL;
            while(i != index && last != NULL){
                first = last;
                last = last->next;
                i++;
            }
            if( i == index){
                if(last == NULL || last->next==NULL){
                    first->next = NULL;
                }
                else{
                    first->next = last->next;   
                }
            }
        }        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */