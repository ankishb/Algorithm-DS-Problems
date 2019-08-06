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
	ListNode* middleNode(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head;
        while(first != NULL){
        	if(second->next == NULL){
        		// list has odd length, we skip one node
        		return first->next;
        	}
        	else if(second->next->next == NULL){
        		// list has even length
        		return first->next;
        	}
        	else{
        		first = first->next;
        		second = second->next->next;
        	}
        }
        return NULL;
    }

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
    void print_list(ListNode* root){
        while(root != NULL){
            cout<<root->val << " ";
            root = root->next;
        }
        cout<<endl;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        if(head->next == NULL) return true;
        ListNode* second = middleNode(head);
        second = reverseList(second);
        // print_list(second);
        while(second != NULL){
        	if(head->val != second->val){
        		return false;
        	}
        	head = head->next;
        	second = second->next;
        }
        return true;
    }
};









// another alternative:
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        
        // Find middle & reverse 2nd half of the list
        ListNode* reversed2ndHalf = reverseList(findMiddle(head));
        
        // Verify palindrome property
        while (reversed2ndHalf != nullptr && head)
        {
            if (reversed2ndHalf->val != head->val)
                return false;
            
            reversed2ndHalf = reversed2ndHalf->next;
            head = head->next;
        }
        
        return true;
    }
    
private:
    ListNode* findMiddle(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* slow = head; ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // If we have an odd number of elements skip over the middle element
        if (fast != nullptr) slow = slow->next;
        
        return slow;
    }
    
    ListNode* reverseList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* prev = nullptr;
        while (head != nullptr)
        {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
};






// recursive
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        return check(head, head);
    }
    
    bool check(ListNode*& head, ListNode* p) {
        if(!p) { return true; }
        bool isPal = check(head, p->next);
        if(head->val != p->val) {
            return false;
        }
        head = head->next;
        return isPal;
    }
};




// another same approach as mine
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};