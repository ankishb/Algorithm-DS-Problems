
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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_map<int, int> my_map;
        for(auto itr : G) my_map[itr] = 1;
        int count = 0;
        bool last = false;
        ListNode* cur;
        while(head != NULL){
            last = false;
            cur = head;
            while(cur != NULL && my_map.find(cur->val) != my_map.end()){
                // cout<<cur->val<<" ";
                last = true;
                cur = cur->next;
            }
            if(last) count++;
            if(cur == NULL) return count;
            if(cur != NULL) head = cur->next;
        }
        
        return count;
    }
};