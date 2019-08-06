
/*
Approach:
1. cut the list in two half, using toroise pointer method
2. sort those two list using recusion (fist & second step)
3. merge them

Time complexity: O(nlogn), space complexity: O(1)
*/
class Solution {
public:
    ListNode* sortList(ListNode* h) {
        if(h == NULL || h->next == NULL) return h;
        ListNode *l1 = h, *l2, *fast = h, *slow = h;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        l2 = slow->next; // get second list
        if(slow->next) slow->next = NULL; // break the list
        l1 = sortList(l1);
        l2 = sortList(l2);
        
        return mergeTwoLists(l1, l2);
    }
    ListNode* helper(ListNode* h1, ListNode* h2){
        ListNode *save = h1, *temp1;
        while(h1->next && h2){
            if(h1->next->val <= h2->val){
                h1 = h1->next;
            }
            else{
                temp1 = h1->next; // keep next node of h1
                h1->next = h2; // make connection (h1->h2)
                h2 = h2->next; // move h2 forward
                h1->next->next = temp1; // make next conn
                h1 = h1->next; // move h1 forward
            }
        }
        if(h2) h1->next = h2;
        return save;
    }

    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        if(h1 == NULL && h2 == NULL) return NULL;
        if(h1 == NULL) return h2;
        if(h2 == NULL) return h1;
        if(h1->val > h2->val) return helper(h2, h1);
        else return helper(h1, h2);
    }
};