// Reverse a linked list from position m to n. Do it in one-pass.

// new one
void print(ListNode* head){
    while(head != NULL){
        cout<<head->val<<" ";
        head = head->next;
    } 
    cout<<endl;
}

ListNode* reverse(ListNode* head){
    if(head == NULL) return NULL;
    ListNode *prev = NULL, *cur = head, *next = head;
    while(cur != NULL){
        next = cur->next;
        cur->next = NULL;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    // print(prev);
    return prev;
}
ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
    int len = 0, flag = 0;
    ListNode* save = head, *temp, *back;
    ListNode *start = NULL, *end = NULL;
    // start = reverse(head);
    if(m == n) return head;
    if(m == 1) flag = 1;
    if(flag == 1) start = head;
    
    while(head != NULL){
        len++;
        if(len == m-1){
            back = head;
            start = head->next;
            // cout<<start->val<<" "<<back->val<<endl;
            head->next = NULL;
            head = start;
        }
        else if(len == n){
            end = head->next;
            head->next = NULL;
            // print(start);
            start = reverse(start);
            // print(start);
            if(flag == 1) save = start;
            if(flag == 0) back->next = start;
            while(start->next != NULL){
                start = start->next;
            }
            start->next = end;
            break;
        }
        else{
            head = head->next;
        }
    }
    return save;
}


// old try
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

    void print_list(ListNode* head){
        while(head != NULL){
            cout<<head->val<<" ";
            head = head->next;
        }
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if((n==0) || (n==m)) return head;
        
        ListNode* first = head;
        ListNode* last = NULL;
        for(int i=0; i<m-1; i++){
            last = first;
            first = first->next;
        }
        ListNode* first_list = head;
        if(m-1 != 0) last->next = NULL;

        last = NULL;
        ListNode* second_list = first;
        for(int i=m; i<=n; i++){
            last = first;
            first = first->next;
        }
        last->next = NULL;

        ListNode* third_list = first;

        second_list = reverseList(second_list);
        cout<<"Ist list\n"; print_list(first_list);
        cout<<"2nd list\n"; print_list(second_list);
        cout<<"3rd list\n"; print_list(third_list);

        
        if(m-1 != 0){
            // connect first and second list
            while(first_list->next != NULL){
                first_list = first_list->next;
            }
            first_list->next = second_list;
        }
        else{
            head = second_list;
        }
        if(third_list != NULL){
            // connect second list tail with third list
            while(second_list->next != NULL){
                second_list = second_list->next;
            }
            second_list->next = third_list;
            
        }
        
        cout<<"\n final: ";
        print_list(head);

        return head;
    }
};
