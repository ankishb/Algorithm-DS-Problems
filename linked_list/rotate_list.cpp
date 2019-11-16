// Given a linked list, rotate the list to the right by k places.
// new try
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* head, int k) {
    if(head == NULL) return NULL;
    int len = 0;
    ListNode* save = head;
    while(head != NULL){
        len++;
        head = head->next;
    }
    if(k%len == 0) return save;
    head = save;
    k = k%len;
    k = len - k;
    while(k > 1 && head != NULL){
        head = head->next;
        k--;
    }
    // cout << len << " " << head->val << endl;
    
    ListNode* head_ = head->next;
    head->next = NULL;
    head = head_;
    while(head->next != NULL){
        head = head->next;
    }
    head->next = save;
    return head_;
}



// old one
/*
Approach:
1. Make circular connection and count lenght of list
2. Mark head at (n-(n%k))th position and cut connection from the back of this node 
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