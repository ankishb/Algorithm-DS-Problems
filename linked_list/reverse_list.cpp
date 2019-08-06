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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;
    	ListNode* prev = NULL;
    	ListNode* cur = head;
    	ListNode* next = head->next;
    	while(cur != NULL){
    		if(next == NULL){
    			// make head connection and return
                cur->next = prev;
    			head = cur;
    			return head;
    		}
    		cur->next = prev;
    		prev = cur;
    		cur = next;
    		next = next->next;
    	}
    	return head;
    }
};