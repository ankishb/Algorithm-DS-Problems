
#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* next;
};

void insert_at_begin(node **headref, int data){
	node* new_node = new node();
	new_node->data = data;
	new_node->next = *headref;
	node* temp = *headref;
	// if list is empty
	if(temp == NULL){
		new_node->next = new_node;
	}
	else{
		// transverse to the last node
		while(temp->next != *headref){
			temp = temp->next;
		}
		temp->next = new_node;
	}
	// init the head node at new_node
	*headref = new_node;
}

void insert_at_end(node **headref, int data){
	node* new_node = new node();
	new_node->data = data;
	// first make circular connection of new_node with head_ref node
	new_node->next = *headref;
	node* temp = *headref;
	// if list is empty
	if(temp == NULL){
		new_node->next = new_node;
	}
	else{
		// transverse to the last node
		while(temp->next != *headref){
			temp = temp->next;
		}
		temp->next = new_node;
	}
	// init the head node at new_node
	*headref = new_node->next;
}

void insert_in_middle(node **headref, int item, int data){
	// insert node after the node, contains item
	node* new_node = new node();
	new_node->data = data;
	new_node->next = NULL;
	node *temp = *headref;

	// check if list is null, insert it
	if(temp == NULL){
		new_node->next = new_node;
		*headref = new_node;
	}
	else{
		// transverse to node, have data == item, 
		// also check if temp != headref, is so then no item is present
		while(temp->data != item && temp->next!=*headref){
			temp = temp->next;
		}
		if(temp->data == item){
			cout<<"\nInsering after : "<<temp->data<<endl;
			new_node->next = temp->next;
			temp->next = new_node;
		
		}
		else{
			cout<<"\ninserting is not possible\n";
		}
		
	}
}


void transveral_bad(node* head){
	cout<<"tranversal circular linked list\n";
	node* temp = head;
	bool flag = false;
	if(temp == NULL){
		flag = true;
	}

	// Not a very good way
	cout<<temp->data<<" ";
	temp = temp->next;
	while(temp != head && !flag){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

void transveral(node* head){
	cout<<"tranversal circular linked list\n";
	node* temp = head;
	bool flag = false;
	if(temp == NULL){
		flag = true;
	}

	
	do{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	while(temp != head && !flag);
	cout<<endl;
}

int main()
{
	node* head = NULL;

	// insert at the begining
	// insert_at_begin(&head, 4);
	// insert_at_begin(&head, 3);
	// insert_at_begin(&head, 2);
	
	// insert_at_begin(&head, 1);

	// insert at the end
	insert_at_end(&head, 1);
	transveral(head);

	insert_at_end(&head, 4);
	transveral(head);

	insert_in_middle(&head, 1, 2);
	transveral(head);

	insert_in_middle(&head, 2, 3);
	transveral(head);

	insert_in_middle(&head, 4, 5);
	transveral(head);
	
	insert_in_middle(&head, 10, 11);
	transveral(head);

	return 0;
}