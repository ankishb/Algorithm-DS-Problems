
int Solution::solve(ListNode* head) {
    int len = 0;
    ListNode* save = head;
    while(head != NULL){
        head = head->next;
        len++;
    }
    int val;
    len = len/2 + 1; len--;
    head = save;
    while(len--){
        head = head->next;
    }
    return head->val;
}


/*
Approach:
We use turtle and rabit race, assign two node from first(turtle) and second(rabbit)
if(second->next == NULL){
	// list has odd length
	return first;
}
else if(second->next->next == NULL){
	// list has even length
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head;
        while(first != NULL){
        	if(second->next == NULL){
        		// list has odd length
        		return first;
        	}
        	else if(second->next->next == NULL){
        		// list has even length
        		return first->next;
        	}
        	else{
        		first = first->next;
        		second = second->next->next;
        	}
        }
        return NULL;
    }
};




// nice and concise code
ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
        slow = slow->next, fast = fast->next->next;
    return slow;
}