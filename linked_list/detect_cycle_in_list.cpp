
bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *slow, *fast;
    if(head == NULL || head->next == NULL) return false;
    slow = head;
    fast = head->next;
    while(fast->next && fast->next->next){
        if(slow == fast) return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}