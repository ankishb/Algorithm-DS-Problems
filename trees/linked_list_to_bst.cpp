
/*
1. use turtle heir approach to find the mid
2. create root node with mid value
3. break the list in two half(carefully, consider edge cases)
4. create left and right node recursively
*/

TreeNode* Solution::sortedListToBST(ListNode* head) {
    // return make_bst(head);
        if(head == NULL) return NULL;
    // find mid
    ListNode *slow = head, *fast = head, *prev = head;
    while(fast && fast->next && fast->next->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow is mid node
    TreeNode* root = new TreeNode(slow->val);
    ListNode *left = NULL, *right = NULL;
    right = slow->next;
    prev->next = NULL;
        
    if(prev != slow){
        left = head;
    }
    
    root->left = sortedListToBST(left);
    root->right = sortedListToBST(right);
    
    return root;
}
