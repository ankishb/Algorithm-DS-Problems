
// interview-bit
ListNode* Solution::swapPairs(ListNode* root) {
    ListNode *first, *second, *third, *temp, *prev;
    if(root != NULL && root->next != NULL){
        first  = root;
        second = root->next;
        third  = root->next->next;
        root   = second;
        root->next = first;
        first->next = third;
    }
    else return root;
    temp = third; prev = first;
    while(temp != NULL && temp->next != NULL){
        // cout<<temp->val<<" "<<temp->next->val<<endl;
        first  = temp;
        second = temp->next;
        third  = temp->next->next;
        prev->next = second;
        second->next = first;
        first->next  = third;
        
        // next iteartion
        prev = first;
        temp = third;
    }
    return root;
}




// leetcode
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* save = head;
        if(head->next) save = head->next;
        ListNode *prev = NULL;
        while(head && head->next){
            ListNode* third = head->next->next;
            ListNode* sec = head->next;
            ListNode* first = head;
            
            if(prev != NULL) prev->next = sec;
            sec->next = first;
            first->next = third;
            
            prev = first;
            head = third;
        }
        return save;
    }
};



class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        
        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        
        return next;
    }
};


