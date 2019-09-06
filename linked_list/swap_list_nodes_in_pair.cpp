
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* root) {
    ListNode *first, *second, *third, *temp, *prev;
    if(root != NULL && root->next != NULL){
        first  = root;
        second = root->next;
        third  = root->next->next;
        root   = second;
        root->next = first;
        first->next = third;
    }
    else return root;
    temp = third; prev = first;
    while(temp != NULL && temp->next != NULL){
        // cout<<temp->val<<" "<<temp->next->val<<endl;
        first  = temp;
        second = temp->next;
        third  = temp->next->next;
        prev->next = second;
        second->next = first;
        first->next  = third;
        
        // next iteartion
        prev = first;
        temp = third;
    }
    return root;
}
