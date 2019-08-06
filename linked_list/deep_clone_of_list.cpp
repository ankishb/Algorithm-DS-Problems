/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    unordered_map<Node*, Node*> my_map;
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* main = new Node(head->val,NULL,NULL);
        my_map[head] = main;
        
        while(head != NULL){
            // take care of null case for next pointer
            
            if(head->next != NULL && my_map.find(head->next) == my_map.end()){
                Node* temp = new Node(head->next->val,NULL,NULL);
                my_map[head->next] = temp;
            }
            // head->random != NULL && 
            if(head->random != NULL && my_map.find(head->random) == my_map.end()){
                Node* temp = new Node(head->random->val,NULL,NULL);
                my_map[head->random] = temp;
            }
            my_map[head]->next = (head->next != NULL) ? my_map[head->next] : NULL;
            my_map[head]->random = (head->random !=NULL) ? my_map[head->random] : NULL;
            
            head = head->next;
        }
        return main;
    }
    
};






