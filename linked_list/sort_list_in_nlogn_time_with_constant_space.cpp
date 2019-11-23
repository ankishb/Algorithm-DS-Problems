
// fresh one
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val > l2->val) swap(l1, l2);
        ListNode *save = l1;
        ListNode *l11, *l22;
        while(l1->next != NULL && l2 != NULL){
            if(l1->next->val < l2->val) l1 = l1->next;
            else{
                l22 = l2->next; // pointer to next of l2
                l2->next = NULL; // break link for l2
                l11 = l1->next; // pointer to next of l1
                l1->next = l2; // make new link
                l2->next = l11; // connect them
                
                l1 = l1->next;
                l2 = l22;
            }
        }
        if(l2 != NULL){
            l1->next = l2;
        }
        return save;
    }
    int get_length(ListNode* head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* merge_sort(ListNode* head, int len){
        if(len <= 0) return NULL;
        if(len == 1) return head;
        int c = 0;
        ListNode *first = head;
        while(c++ < len/2-1){
            head = head->next;
        }
        ListNode *sec = head->next;
        head->next = NULL;

        // divide further, if possible
        first = merge_sort(first, c);
        sec = merge_sort(sec, len-c);
            
        // sort those pieces
        return mergeTwoLists(first, sec);
    }
    
    ListNode* sortList(ListNode* head) {
        int len = get_length(head);
        if(len <= 1) return head;
        return merge_sort(head, len);
    }
};


// last try
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