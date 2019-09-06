{
#include<bits/stdc++.h>
/* structure for a Node */
struct Node
{
  int data;
  struct Node *next;
};
   void sortedInsert(struct Node**head_ref, int x);
/* function to insert a new_Node in a list in sorted way.
   Note that this function expects a pointer to head Node
   as this can modify the head of the input linked list */
/* Function to print Nodes in a given linked list */
void printList(struct Node *start)
{
  struct Node *temp;
  if(start != NULL)
  {
    temp = start;
    do { printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != start);
    printf("
");
  }
}
/* Driver program to test above functions */
int main()
{
int t,n,x;
scanf("%d",&t);
int arr;
  while(t--){
  scanf("%d",&n);
  int list_size, i;
  /* start with empty linked list */
  struct Node *start = NULL;
  struct Node *temp,*r;
  /* Create linked list from the array arr[].
    Created linked list will be 1->2->11->56->12 */
    if(n>0){
     scanf("%d",&arr);
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data=arr;
    temp->next=NULL;
    start=temp;
    r=start;}
 for (i = 0; i<n-1; i++)
  {
   scanf("%d",&arr);
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = arr;
    temp->next=NULL;
     r->next=temp;
     r=r->next;
  }
  if(n>0)
  temp->next=start;
 // printList(start);
  scanf("%d",&x);
  sortedInsert(&start,x);
  printList(start);
  r=start;
  while(r!=start->next)
  {
      temp=start;
      start=start->next;
      free(temp);
  }
  free(start);
 }
  return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/* structure for a node */
/*
struct Node
{
  int data;
  Node *next;
};
 */
void sortedInsert(Node** head_ref, int x)
{
    Node *cur = *head_ref;
    Node *next = cur->next;
    bool inserted = false;
    // 1. case, when list is empty
    if(cur==NULL){
        Node *new_node = new Node();
        new_node->data = x;
        new_node->next = new_node;
        *head_ref = new_node;
        inserted = true;
    }
    // 2. node should insert at first
    if(cur->data > x){
        Node *new_node = new Node();
        new_node->data = x;
        new_node->next = cur;
        *head_ref = new_node;
        inserted = true;
    }
    while(cur->next != *head_ref && !inserted){
        if(cur->data <= x && next->data > x){
            // insert node in there
            Node *new_node = new Node();
            new_node->data = x;
            cur->next = new_node;
            new_node->next = next;
            inserted = true;
            break;
        }
        next = next->next;
        cur = cur->next;
    }
    // edge case, where node should be inserted at last
    if(!inserted){
        Node *new_node = new Node();
        new_node->data = x;
        new_node->next = cur->next;
        cur->next = new_node;
    }
    
    
    
}