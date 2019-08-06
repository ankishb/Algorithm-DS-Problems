

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// solution with Time complexity: O(nlogn + mlogm)
// where logn is taken to insert an item in set
// Also space complexity is O(n)
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    set<ListNode*> node_set;
    while(A!=NULL){
        node_set.insert(A);
        A = A->next;
    }
    while(B!=NULL){
        if(node_set.find(B) != node_set.end()){
            return B;
        }
        B = B->next;
    }
    return NULL;
}


int getLength(ListNode* temp_node){
    int len = 0;
    while(temp_node!=NULL){
        len++;
        temp_node = temp_node->next;
    }
    return len;
}


// solution with Time complexity: O(n)
// Also space complexity is O(1)
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    int A_len = getLength(A);
    int B_len = getLength(B);
    
    // cout<<A_len<<"--"<<B_len<<endl;
    while(A_len > B_len){
        A = A->next;
        A_len--;
    }
    while(B_len > A_len){
        B = B->next;
        B_len--;
    }
    
    // cout<<A_len<<"--"<<B_len<<endl;
    while(A != NULL){
        if(A==B){
            return A;
        }
        A = A->next;
        B = B->next;
    }
    return NULL;
}
