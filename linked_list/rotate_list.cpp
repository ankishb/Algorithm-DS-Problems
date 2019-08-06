// Given a linked list, rotate the list to the right by k places.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
Approach:
1. Make circular connection and count lenght of list
2. Mark head at (n-(n%k))th position and cut connection from thw back of this node 
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
    	if(head == NULL || head->next == NULL) return head;
        ListNode* first = head;
        int n = 0;
        while(first->next != NULL){
        	first = first->next;
        	n++;
        }
        n++;
        first->next = head;
        k = k%n;
        ListNode* next = head;
        int count = 0;
        first = NULL;
        while(count != (n-k)){
            first = next;
        	next = next->next;
            count++;
        }
        head = next;
        first->next = NULL;
        return head;
    }
};