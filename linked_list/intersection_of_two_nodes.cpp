

int get_length(ListNode* head){
    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}

ListNode* standard_solution(ListNode* l1, ListNode* l2) {
    int l1_len = get_length(l1);
    int l2_len = get_length(l2);

    if(l1_len > l2_len){
        swap(l1, l2);
        swap(l1_len, l2_len);
    }
    // now, we found that l2 is large in size
    while(l2_len != l1_len){ l2 = l2->next; l2_len--; }
    // at this point, both have same length
    while(l1 != NULL){
        if(l1 == l2) return l1;
        l1 = l1->next;
        l2 = l2->next;
    }
    return NULL;
}


/*
Iterate over both list in parallel, until both have same node
- There are 2 possible cases:
    1. If both becomes NULL, then there is no intersection point
    2. If one list becomes NULL, init that node with other head node(saved at start)
    
Proof: As both 
*/
ListNode* tricky_solution(ListNode* l1, ListNode* l2) {
    if(l1 == NULL || l2 == NULL) return NULL;
    ListNode *l1_save = l1, *l2_save = l2;
    while(l1 != l2){
        l1 = l1->next;
        l2 = l2->next;
        if(l1 == NULL && l2 == NULL) return NULL;
        if(l1 == NULL) l1 = l2_save;
        if(l2 == NULL) l2 = l1_save;
    }
    return l1;
}



// solution with Time complexity: O(nlogn + mlogm)
// where logn is taken to insert an item in set
// Also space complexity is O(n)
ListNode* memorized_solution(ListNode* A, ListNode* B) {
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


ListNode* Solution::getIntersectionNode(ListNode* l1, ListNode* l2) {
    // return standard_solution(l1, l2);
    // return memorized_solution(l1, l2);
    return tricky_solution(l1, l2);
}