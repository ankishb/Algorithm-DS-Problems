
/*
To make a balanced bst, we will pick a mid element and create a root node
and then its left and right child will be the mid element from the left 
and right part of the array
*/

// balanced-bst from array
class Solution {
public:
    TreeNode* build_bst(vector<int> A, int l, int r){
        if(l > r) return NULL;
        int m = l + (r - l)/2;
        TreeNode* root = new TreeNode(A[m]);
        root->left = build_bst(A, l, m-1);
        root->right= build_bst(A, m+1, r);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return build_bst(nums, 0, nums.size()-1);
    }
};



// balanced-bst from linked-list
class Solution {
public:
    TreeNode* build_bst(vector<int> A, int l, int r){
        if(l > r) return NULL;
        int m = l + (r - l)/2;
        TreeNode* root = new TreeNode(A[m]);
        root->left = build_bst(A, l, m-1);
        root->right= build_bst(A, m+1, r);
        return root;
    }

    TreeNode* naive_solution(ListNode* head){
        if(head == NULL) return NULL;
        vector<int> A;
        while(head != NULL){
            A.push_back(head->val);
            head = head->next;
        }
        return build_bst(A, 0, A.size()-1);
    }

    TreeNode* sortedListToBST(ListNode* head) {
    	// return naive_solution(head);
        return memory_optimized(head);
    }

    /*
	Recursively build tree:
	    1. find midpoint by fast/slow method, use middle node as root.
	    2. build left child by first half of the list
	    3. build right child by second half of the list (head is midpoint->next)
	*/
    TreeNode* memory_optimized(ListNode *head) {
            if(!head) return NULL;
            if(!head->next) return new TreeNode(head->val);
            
            // fast/slow pointer to find the midpoint
            auto slow = head;
            auto fast = head;
            auto pre = head;
            while(fast && fast->next) {
                pre = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            pre->next = 0; // break two halves 
            
            // slow is the midpoint, use as root
            TreeNode* root = new TreeNode(slow->val);
            root->left = sortedListToBST(head);
            root->right = sortedListToBST(slow->next);
            
            return root;
        }
};

// old one
#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* get_new_node(int data){
	node* new_node = new node();
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

void inorder_tran(node* root){
	if(root == NULL){
		return ;
	}
	inorder_tran(root->left);
	cout<<root->data<<" ";
	inorder_tran(root->right);
}

node* make_bst(vector<int> vect, int left, int right){
	if(left > right){
		return NULL;
	}
	int mid = left + (right-left)/2;
	cout<<mid+1<<" ";
	node* root = get_new_node(vect[mid]);
	root->left = make_bst(vect, left, mid-1);
	root->right = make_bst(vect, mid+1, right);

	return root;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int el;
		vector<int> vect;
		while(n--){
			cin>>el;
			vect.push_back(el);
		}

		node* root = NULL;
		cout<<"\n --making BST--\n ";
		root = make_bst(vect, 0, vect.size()-1);

		cout<<"\n --verify BST using Inorder Tranversal--\n";
		inorder_tran(root);
	}
	return 0;
}