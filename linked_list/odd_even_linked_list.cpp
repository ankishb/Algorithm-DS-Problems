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
If len is even [1->2->3->4]    there 4 is our last odd node
If len is odd  [1->2->3->4->5] there 4 is our last odd node
So our condition of odd and odd->next will help.
Note that when len is odd, this consition will save us from having an extra node 5 at the end of 4 in odd list.
*/
class Solution {
public:
    void print(ListNode* head){
        while(head != NULL){
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *even=head, *odd=head->next, *oddSave = head->next;
        while(odd != NULL && odd->next != NULL){
            even->next = even->next->next;
            odd->next = odd->next->next;
            even = even->next;
            odd = odd->next;
        }
        even->next = oddSave;
        return head;
    }
};