/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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