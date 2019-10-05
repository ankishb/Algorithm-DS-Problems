
// new and good one
RandomListNode* cleaner(RandomListNode* head){
    if(head == NULL) return NULL;
    RandomListNode *head_save = head;
    unordered_map<RandomListNode*, RandomListNode*> map;
    while(head){
        map[head] = new RandomListNode(head->label);
        head = head->next;
    }
    head = head_save;
    while(head != NULL){
        map[head]->next = map[head->next];
        map[head]->random = map[head->random];
        
        head = head->next;
    }
    return map[head_save];
}
RandomListNode* good_solution(RandomListNode* head){
    if(head == NULL) return NULL;
    RandomListNode *head_save = head;
    unordered_map<RandomListNode*, RandomListNode*> map;
    while(head != NULL){
        if(map.find(head) == map.end()){
            map[head] = new RandomListNode(head->label);
        }
        if(head->next && map.find(head->next) == map.end()){
            map[head->next] = new RandomListNode(head->next->label);
        }
        if(head->random && map.find(head->random) == map.end()){
            map[head->random] = new RandomListNode(head->random->label);
        }
        if(head->next) map[head]->next = map[head->next];
        if(head->random) map[head]->random = map[head->random];
        
        head = head->next;
    }
    return map[head_save];
}
RandomListNode* Solution::copyRandomList(RandomListNode* head){
    // return good_solution(head);
    return cleaner(head);
}


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