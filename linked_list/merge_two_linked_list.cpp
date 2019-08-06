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

    ListNode* mergeTwoLists_naive(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) return NULL;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* temp = NULL;
        if(l1->val <= l2->val){
            temp =  new ListNode(l1->val);
            l1 = l1->next;
        } 
        else{
            temp =  new ListNode(l2->val);
            l2 = l2->next;
        } 
        ListNode* start = temp;
        while(l1 != NULL && l2 != NULL){
            // cout<<l1->val<<" : "<<l2->val<<endl;
            if(l1->val <= l2->val){
                ListNode* new_ = new ListNode(l1->val);
                temp->next = new_;
                temp = temp->next; l1 = l1->next;
            }
            else{
                ListNode* new_ = new ListNode(l2->val);
                temp->next = new_;
                temp = temp->next; l2 = l2->next;
            }
        }
        if(l1 != NULL) temp->next = l1;
        if(l2 != NULL) temp->next = l2;
        // delete l1;
        // delete l2;
        // delete temp;
        return start;
    }
    ListNode* mergeTwoLists_inefficient(ListNode* l1, ListNode* l2) {
    	if(l1 == NULL && l2 == NULL) return NULL;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* temp = NULL;
        ListNode* start = l1;

        while(l1 != NULL && l2 != NULL){
            cout<< l1->val << " : " << l2->val << endl;
        	if(l1->val >= l2->val){
        		ListNode* temp = new ListNode(l2->val);
        		temp->next = l1;
        		if(start == l1) start = temp;
        		l1 = temp;
        		l2 = l2->next;
        	}
        	else if(l1->val < l2->val){
        		l1 = l1->next;
        	}
        }
        if(l2 != NULL && l1 != NULL) l1->next = l2;
        return start;
    }
};


SinglyLinkedListNode* helper(SinglyLinkedListNode* h1, SinglyLinkedListNode* h2){
    SinglyLinkedListNode *save = h1, *temp1;
    while(h1->next && h2){
        if(h1->next->data <= h2->data){
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

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* h1, SinglyLinkedListNode* h2) {
    if(h1 == NULL && h2 == NULL) return NULL;
    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;
    if(h1->data > h2->data) return helper(h2, h1);
    else return helper(h1, h2);
}