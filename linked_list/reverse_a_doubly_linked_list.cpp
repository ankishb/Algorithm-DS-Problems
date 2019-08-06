void printList(DoublyLinkedListNode* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    if(head == NULL) return NULL;
    // printList(head);
    DoublyLinkedListNode* temp = head;
    DoublyLinkedListNode *save, *next=temp;
    while(true){
        save = next;
        next = next->next;
        temp = save;
        temp->next = save->prev;
        temp->prev = save->next;
        // cout<<save->data<<" ";
        if(next == NULL){
            head = temp;
            return head;
        }
    }
    return NULL;
}