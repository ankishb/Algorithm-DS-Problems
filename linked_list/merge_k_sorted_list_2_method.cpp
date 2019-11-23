
// new try
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val > l2->val) swap(l1, l2);
        ListNode *save = l1;
        ListNode *l11, *l22;
        while(l1->next != NULL && l2 != NULL){
            if(l1->next->val < l2->val) l1 = l1->next;
            else{
                l22 = l2->next; // pointer to next of l2
                l2->next = NULL; // break link for l2
                l11 = l1->next; // pointer to next of l1
                l1->next = l2; // make new link
                l2->next = l11; // connect them
                
                l1 = l1->next;
                l2 = l22;
            }
        }
        if(l2 != NULL){
            l1->next = l2;
        }
        return save;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;
        if(n == 1) return lists.front();
        int size = log2(n);
        ListNode *first, *sec;
        if(pow(2,size) != n) size++;
        for(int i=0; i<size; i++){
            for(int j=0; j<n; j=j+pow(2,i+1)){
                first = lists[j];
                if(j+pow(2,i) >= n) sec = NULL;
                else sec = lists[j+pow(2,i)];
                lists[j] = mergeTwoLists(first, sec);
            }
        }
            
        return lists.front();
    }
};




// last one
struct compare{
	bool operator()(const ListNode* l1, const ListNode* l2){
		return (l1->val > l2-val);
	}
}

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