
struct compare{
	bool operator()(const ListNode* l1, const ListNode* l2){
		return (l1->val > l2-val);
	}
}
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
	ListNode* mergeKListsHeap(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(auto list : lists) pq.push(list);
        ListNode *head = pq.top(), *save = head;
    	if(head->next) pq.push(head->next);

    	while(!pq.empty()){
    		head->next = pq.top(); pq.pop();
    		head = head->next;
    		if(head->next) pq.push(head->next);
    	}

        return save;
    }
    ListNode* helper(ListNode* h1, ListNode* h2){
        ListNode *save = h1, *temp1;
        while(h1->next && h2){
            if(h1->next->val <= h2->val){
                h1 = h1->next;
            }
            else{
                temp1 = h1->next; // keep next node of h1
                h1->next = h2; // make connection (h1->h2)
                h2 = h2->next; // move h2 forward
                h1->next->next = temp1; // make next conn
                h1 = h1->next; // move h1 forward
            }
        }
        if(h2) h1->next = h2;
        return save;
    }

    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        if(h1 == NULL && h2 == NULL) return NULL;
        if(h1 == NULL) return h2;
        if(h2 == NULL) return h1;
        if(h1->val > h2->val) return helper(h2, h1);
        else return helper(h1, h2);
    }
    
    ListNode* mergeKListsMerge(vector<ListNode*>& lists) {
        ListNode *save1, *save2;
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        save1 = lists[0];
        for(int i=1; i<lists.size(); i++){
            save2 = mergeTwoLists(save1, lists[i]);
            save1 = save2;
        }
        return save2;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	// return mergeKListsMerge(lists);
    	return mergeKListsHeap(lists);
    }
};