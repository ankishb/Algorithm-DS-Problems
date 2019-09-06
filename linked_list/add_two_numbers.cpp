
/*
1. Number of digit in both list can vary, run the loop while both of them are zero.
2. Otherwise, just add them and create new node as answer.

*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = NULL, *save;
        int a, b, sum, carry = 0;
        while(l1 != NULL || l2 != NULL){
            a = (l1 == NULL) ? 0 : l1->val;
            b = (l2 == NULL) ? 0 : l2->val;
            sum = a + b + carry;
            carry = sum / 10;
            sum = sum % 10;
            if(ans == NULL){
                ans = new ListNode(sum);
                save = ans;
            }
            else{
                ans->next = new ListNode(sum);
                ans = ans->next;
            }
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }
        if(carry != 0) ans->next = new ListNode(carry);
        return save;
    }
};