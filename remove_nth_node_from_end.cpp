// Given a linked list, remove the n-th node from the end of list and return its head.

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