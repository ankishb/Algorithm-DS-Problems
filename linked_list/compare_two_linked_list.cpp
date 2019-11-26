/*
strcmp:
    0 if both strings are same, 
    1 if first linked list is lexicographically greater
    -1 if second is lexicographically greater.
*/
int compare(Node *h1, Node* h2) {
    while(h1 != NULL && h2 != NULL){
        if(h1->c > h2->c) return 1;
        if(h1->c < h2->c) return -1;
        h1 = h1->next;
        h2 = h2->next;
    }
    if(h1==NULL && h2==NULL) return 0;
    return (h1 != NULL) ? 1 : -1;
    
}