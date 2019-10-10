/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* naive(ListNode* head, int k) {
    ListNode *temp = head, *new_h = NULL, *save = NULL;
    while(temp != NULL){
        if(temp->val < k){
            if(new_h == NULL){
                new_h = new ListNode(temp->val);
                save = new_h;
            }
            else{
                new_h->next = new ListNode(temp->val);
                new_h = new_h->next;
            }
        }
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        if(temp->val >= k){
            if(new_h == NULL){
                new_h = new ListNode(temp->val);
                save = new_h;
            }
            else{
                new_h->next = new ListNode(temp->val);
                new_h = new_h->next;
            }
        }
        temp = temp->next;
    }
    return save;
}

ListNode* optimal(ListNode* head, int k) {
    ListNode *temp = head, *new_h = NULL, *save = NULL;
    return save;
}
ListNode* Solution::partition(ListNode* head, int k) {
    // return naive(head, k);
    return optimal(head, k);
}
