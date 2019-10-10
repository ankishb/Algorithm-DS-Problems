
#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	int next;
};

void get_new_node(int data){
	node* new_node = new node();
	new_node->data = data;
	new_node->next = NULL;
}

node* insert(node* last, int data){
	node* temp = get_new_node(data);
	last->next = temp;
}

node* insert_at_begin(node* head, int data){
	node* temp = get_new_node(data);
	temp->next = head;
	head = temp;
	return head;
}

void insert_at_begin(node** head, int data){
	node* temp = get_new_node(data);
	temp->next = *head;
	*head = temp;
}

void transversal(node* head){
	node* temp = head;
	while(temp->next != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

node* insert_at_end(node* head, int data){
	node* temp = get_new_node(data);
	node* temp1 = head;
	while(temp1->next != NULL){
		temp1 = temp1->next;
	}
	temp1->next = temp;

	return head;
}


void insert_at_end(node** head, int data){
	node* temp = get_new_node(data);
	node* temp1 = *head;
	while(temp1->next != NULL){
		temp1 = temp1->next;
	}
	temp1->next = temp;

	return head;
}



void insert_at_end(node** head, int data){
	node* temp = get_new_node(data);
	node* temp1 = *head;
	while(temp1->next != NULL){
		temp1 = temp1->next;
	}
	temp1->next = temp;

	return head;
}



void insert_at_end(node** head, int data){
	node* temp = get_new_node(data);
	node* temp1 = *head;
	while(temp1->next != NULL){
		temp1 = temp1->next;
	}
	temp1->next = temp;

	return head;
}



int main()
{
	node* head = NULL;

}