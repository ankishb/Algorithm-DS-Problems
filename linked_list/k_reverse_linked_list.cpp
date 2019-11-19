/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* head){
    ListNode* prev = NULL, *cur = head, *next;
    while(cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
void print(ListNode* head){
    while(head != NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}
ListNode* Solution::reverseList(ListNode* head, int k) {
    if(k <= 1 || head == NULL) return  head;
    ListNode *cur = head, *prev = head;
    int kk = k;
    vector<ListNode*> all;
    while(head != NULL){
        kk--;
        if(kk == 0){
            cur = head->next;
            head->next = NULL;
            head = reverse(prev);
            // print(head);
            all.push_back(head);
            prev = cur;
            head = cur;
            kk = k;
        }
        else head = head->next;
    }
    if(all.size() == 1) return all.front();
    ListNode* save = all[0];
    cur = all[0];
    for(int i=0; i<all.size()-1; i++){
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = all[i+1];
    }
    
    return save;
}


// recursive solution
ListNode* Solution::reverseList(ListNode* A, int B) {
    ListNode *curr = A, *prev = NULL, *next = NULL;
    int cnt =0;
     while(cnt<B && curr) {
         next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
         cnt++;
     }
     if(next) {
         A->next = reverseList(next, B);
     }
     return prev;
}