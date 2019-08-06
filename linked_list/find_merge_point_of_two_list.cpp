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

    void collect_nodes(ListNode* root, stack<ListNode*> &s){
        while(root != NULL){
            s.push(root);
            // cout<<root->val<<" ";
            root = root->next;
        }
        // cout<<endl;
    }
    ListNode* naive_memory(ListNode *headA, ListNode *headB){
        if(headA==NULL || headB==NULL) return NULL;
        stack<ListNode*> s1;
        stack<ListNode*> s2;
        collect_nodes(headA, s1);
        collect_nodes(headB, s2);
        if(s1.top() != s2.top()) return NULL;
        ListNode* temp;
        while(!s1.empty() && !s2.empty()){
            temp = s1.top();
            s1.pop(); s2.pop();
            if(s1.empty() || s2.empty()) return temp;
            if(s1.top() != s2.top()) return temp;
        }
        return NULL;
    }

    ListNode* efficient(ListNode *headA, ListNode *headB){
        if(headA==NULL || headB==NULL) return NULL;
        int n1=0, n2=0;
        ListNode* temp = headA;
        while(temp != NULL){
            n1++;
            temp = temp->next;
        }
        temp = headB;
        while(temp != NULL){
            n2++;
            temp = temp->next;
        }
        if(n1 > n2){
            for(int i=0; i<n1-n2; i++){
                headA = headA->next;
            }
        }
        else if(n1 < n2){
            for(int i=0; i<n2-n1; i++){
                headB = headB->next;
            }
        }
        while(headA != NULL){
            if(headA == headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
    
    ListNode* two_pointer(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;

        if (p1 == NULL || p2 == NULL) return NULL;

        while (p1 != NULL && p2 != NULL && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;

            //
            // Any time they collide or reach end together without colliding 
            // then return any one of the pointers.
            //
            if (p1 == p2) return p1;

            //
            // If one of them reaches the end earlier then reuse it 
            // by moving it to the beginning of other list.
            // Once both of them go through reassigning, 
            // they will be equidistant from the collision point.
            //
            if (p1 == NULL) p1 = headB;
            if (p2 == NULL) p2 = headA;
        }

        return p1;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // return naive_memory(headA, headB);
        // return efficient(headA, headB);
        return two_pointer(headA, headB);
    }
};




// not working

    
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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* next = head->next;
        while(cur != NULL){
            if(next == NULL){
                // make head connection and return
                cur->next = prev;
                head = cur;
                return head;
            }
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next->next;
        }
        return head;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        headA = reverseList(headA);
        headB = reverseList(headB);
        
        while(headA != NULL && headB != NULL){
            if((headA->val == headB->val) && (headA->next->val != headB->next->val)){
                ListNode* new_node = new ListNode(headA->val);
                return new_node;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};






int findMergeNode(SinglyLinkedListNode* headA, SinglyLinkedListNode* headB) {
    if(headA==NULL || headB==NULL) return -1;
    int n1=0, n2=0;
    SinglyLinkedListNode* temp = headA;
    while(temp != NULL){
        n1++;
        temp = temp->next;
    }
    temp = headB;
    while(temp != NULL){
        n2++;
        temp = temp->next;
    }
    if(n1 > n2){
        for(int i=0; i<n1-n2; i++){
            headA = headA->next;
        }
    }
    else if(n1 < n2){
        for(int i=0; i<n2-n1; i++){
            headB = headB->next;
        }
    }
    while(headA != NULL){
        if(headA == headB){
            return headA->data;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return -1;
}
