
// new try
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *copy = head, *save = head;
        while(copy != NULL){
            len++;
            copy = copy->next;
        }
        len = len-n;
        if(len == 0) return head->next;
        if(len < 0) return head;
        
        while(len > 1 && head != NULL){
            head = head->next;
            len--;
        }
        if(head != NULL && head->next != NULL){
            head->next = head->next->next;
        }
        return save;
    }
};

// old one
class Solution {
public:
    // ListNode* remove_head(ListNode* head){
    //     return head->next;
    // }
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        if(head == NULL) return NULL;
        if(k == 0) return head;
        int n = 0;
        ListNode* first = head;
        while(first != NULL){
        	first = first->next;
        	n++;
        }
        if(k == n){
            return head->next;
        }
        ListNode* next = head;
        first = NULL;
        for(int i=0; i<n-k; i++){
        	first = next;
        	next = next->next;
        }
        
        first->next = next->next;
        next = NULL;
        return head;
    }
};