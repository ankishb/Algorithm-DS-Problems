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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* save = head;
        queue<int> q;
        while(head && head->next){
            if(head->next != NULL && head->val == head->next->val){
                q.push(head->val);
            }
            while(head->next != NULL && head->val == head->next->val){
                head->next = head->next->next;
            }
            head = head->next;
        }
        
        head = save;
        while(head != NULL && q.front() == head->val){
            head = head->next;
            q.pop();
        }
        save = head;
        if(head == NULL) return NULL;
        while(!q.empty()){
            while(head->next != NULL && head->next->val != q.front()){
                head = head->next;
            }
            head->next = head->next->next;
            q.pop();
        }
        
        return save;
    }
};