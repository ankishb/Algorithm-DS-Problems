
// new try
ListNode* Solution::detectCycle(ListNode* head) {
    if(head == NULL || head->next == NULL) return NULL;
    ListNode* slow = head;
    bool loop = false;
    ListNode* fast = head;
    while(slow != NULL && fast != NULL && fast->next != NULL){
        
        slow = slow->next;
        fast = fast->next->next;
    
        if(slow == fast){
            loop = true;
            break;
        }
    }
    if(!loop) return NULL;
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* root) {
    if(root == NULL) return NULL;
    ListNode *slow=root, *fast=root;
    
    while(slow != NULL && fast != NULL){
    // while(slow != fast){
        if(fast==NULL || fast->next==NULL 
        || fast->next->next==NULL) return NULL;
        // cout<<slow->val<<" "<<fast->val<<endl;
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) break;
    }
    
    if(slow == NULL || fast == NULL) return  NULL;
    
    // cout<<slow->val<<" "<<fast->val<<endl;
    
    ListNode* start = root;
    while(start != slow){
        start = start->next;
        slow  = slow->next;
    }
    
    return slow;
}



ListNode* Solution::detectCycle(ListNode* head) {
    if(head == NULL || head->next == NULL) return NULL;
    ListNode* slow = head;
    bool loop = false;
    ListNode* fast = head;
    while(fast == NULL && fast->next != NULL){
        
        slow = slow->next;
        fast = fast->next->next;
    
        if(slow == fast){
            loop = true;
            break;
        }
    }
    if(!loop) return NULL;
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *slow, *fast;
    if(head == NULL || head->next == NULL) return false;
    slow = head;
    fast = head->next;
    while(fast->next && fast->next->next){
        if(slow == fast) return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}