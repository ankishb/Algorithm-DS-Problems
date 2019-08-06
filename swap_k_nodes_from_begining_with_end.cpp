
#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int data;
	ListNode* next;
};

ListNode* get_new_node(int data){
	ListNode* new_node = new ListNode();
	new_node->data = data;
	new_node->next = NULL;
}

void Insert_at_last(ListNode** head_ref, ListNode**tail_ref, int data){
	ListNode* new_node = new ListNode();
	new_node->data = data;
	new_node->next = NULL;
	if(*head_ref == NULL){
		*head_ref = new_node;
		*tail_ref = new_node;
	}
	else{
		// first create a next link from the current node to new_node.
		(*tail_ref)->next = new_node;
		// node switch to new node or update the address of reference node.
		*tail_ref = new_node;
	}
}

void Insert_at_start(ListNode** head_ref, ListNode**tail_ref, int data){
	ListNode* new_node = new ListNode();
	new_node->data = data;
	new_node->next = NULL;
	if(*head_ref == NULL){
		*head_ref = new_node;
		*tail_ref = new_node;
	}
	else{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
}

void transversal(ListNode* head){
	cout<<"\n tranversal of inked list\n";
	while(head != NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}

// ListNode* swap_k_nodes(ListNode* head, int num, int k){
// 	ListNode* head_save = head;
// 	for(int i=0; i<k&&k<num; i++){
// 		ListNode* new_node = new ListNode();
// 		new_node = head;
// 		for(int j=0; j<n-k-2; j++){
// 			head = head->next;
// 		}
// 		if(i==0){
// 			head_save = head->next;
// 		}
// 		else{
// 			head
// 		}
// 	}

// }

void reverse_it(ListNode** head_ref){
	ListNode *prev, *cur, *next;
	cur = *head_ref;
	prev = NULL;
	while(cur!=NULL){
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	// cur->next = *head_ref;
	*head_ref = prev;
}
	

int main()
{
	ListNode* head = NULL;
	ListNode* tail = NULL;
	int n;
	cin>>n;
	int data;
	for(int i=0; i<n; i++){
		cin>>data;
		Insert_at_last(&head, &tail, data);
	}
	
	transversal(head);

	// for(int i=0; i<n; i++){
	// 	cin>>data;
	// 	Insert_at_start(&head, &tail, data);
	// }
	
	// transversal(head);

	// int k;
	// cin>>k;
	// swap_k_nodes(head, n, k);

	reverse_it(&head);
	transversal(head);

	return 0;
}