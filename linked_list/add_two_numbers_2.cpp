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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1, *temp2 = l2;
        int len1 = 0, len2 = 0;
        while(temp1){
            len1++; temp1 = temp1->next;
        }
        while(temp2){
            len2++; temp2 = temp2->next;
        }
        int a, b, sum;
        ListNode *ans = NULL, *save;
        while(l1 != NULL || l2 != NULL){
            if(len1 == len2){
                a = l1->val; b = l2->val;
                l1 = l1->next; l2 = l2->next;
                len1--; len2--;
            }
            else if(len1 > len2){
                a = l1->val; b = 0;
                l1 = l1->next; len1--;
            }
            else{
                a = 0; b = l2->val;
                l2 = l2->next; len2--;
            }
            sum = a+b;
            if(ans == NULL){
                ans = new ListNode(sum);
                save = ans;
            }
            else{
                ans->next = new ListNode(sum);
                ans = ans->next;
            }
        }
        
        ListNode* save_ = save;
        // transverse till each value of list node is single digit
        while(true){
            save = save_;
            bool single = true;
            if(save->val >= 10){
                ListNode *temp = new ListNode(save->val / 10);
                save->val = save->val % 10;
                save_ = temp;
                temp->next = save;
            }
            while(save->next){
                int next = save->next->val;
                if(next >= 10){
                    single = false;
                    save->next->val = next%10;
                    save->val = save->val + next/10;
                }
                save = save->next;
            }
            if(single == true) break;
        }
        return save_;
    }
};