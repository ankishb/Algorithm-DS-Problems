#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
void insert(SinglyLinkedListNode **headref, int data){
    SinglyLinkedListNode *temp = new SinglyLinkedListNode(data);
    // temp->data = data;
    // temp->next = NULL;
    (*headref)->next = temp;
} 

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    SinglyLinkedListNode *ans = (head1->data < head2->data) ? head1 : head2;
    SinglyLinkedListNode *temp = ans;
    while(head1 != NULL && head2 != NULL){
        if(head1->data <= head2->data){
            insert(&temp, head1->data);
            head1 = head1->next;
        }
        else{
            insert(&temp, head2->data);
            head2 = head2->next;
        }
    }
    while(head1 != NULL){
        insert(&temp, head1->data);
        head1 = head1->next;
    }
    while(head2 != NULL){
        insert(&temp, head2->data);
        head2 = head2->next;
    }
    return ans;
}

int main()