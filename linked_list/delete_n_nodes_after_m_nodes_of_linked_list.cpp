

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

void delete_nodes_iteratively(node **headref, int n, int m){
	int n1 = n;
	int m1 = m;
	node *cur = *headref;
	node *prev = NULL;
	cur = cur->next;
	n--;
	while(cur != *headref){
		cout<<"n: "<<n<<" m: "<<m<<" "<<cur->data<<endl;
		
		if(n>0){
			prev = cur;
			cur = cur->next;
			n--;
			if(n==0){
				m = m1;
			}
		}
		else{
			// delete node
			prev->next = cur->next;
			cur->next = NULL;
			cur = prev->next;
			m--;
			if(m==0){
				n = n1;
			}
		}
	}
	*headref = cur;
}


void delete_even_nodes(node **headref){
	node *cur = *headref;
	node *prev = NULL;
	bool last_flag = false;
	
	do{
		cout<<cur->data<<endl;
		
		if((cur->data)%2 == 0){
			if(cur == *headref){
				cur = cur->next;
				*headref = cur;
				last_flag = true;
			}
			else{
				// delete node
				prev->next = cur->next;
				cur->next = NULL;
				cur = prev->next;
			}
		}
		else{
			prev = cur;
			cur = cur->next;
		}
	}
	while(cur->next != *headref);
	// *headref = cur;
	// if first node is deleted, then maintain the circular link to the updated node
	if(last_flag){
		if((cur->data)%2 == 0){
			prev->next = *headref;
			cur->next = NULL;
		}
		else{
			cur->next = *headref;
		}
	}
	// if((cur->data)%2 == 0){
	// 	prev->next = *headref;
	// 	cur->next = NULL;
	// }
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
	int test;
	cin>>test;
	while(test--){
		int no;
		cin>>no;
		node* head = NULL;
		while(no--){
			int el;
			cin>>el;

			// insert at the begining
			insert_at_begin(&head, el);
		}
		transveral(head);
		delete_even_nodes(&head);
		// int N, M;
		// cin>>N>>M;
		// delete_nodes_iteratively(&head, N, M);
		transveral(head);
		delete head;
	}

	return 0;
}










// #include<stdio.h>
// #include<stdlib.h>
// //using namespace std;
// /* A linked list node */
// struct node
// {
//     int data;
//     struct node *next;
// };
// struct node *start = NULL;
// void linkdelete(struct node  *head, int M, int N);
// /* Function to print nodes in a given linked list */
// void printList(struct node *node)
// {
//     while (node != NULL)
//     {
//         printf("%d ", node->data);
//         node = node->next;
//     }
//     printf("");
    
// }
// void insert(int n1)
// {
//     int n,value,i;
//     //scanf("%d",&n);
//     n=n1;
//     struct node *temp;
//     for(i=0;i<n;i++)
//     {
//         scanf("%d",&value);
//         if(i==0)
//         {
//             start=(struct node *) malloc( sizeof(struct node) );
//             start->data=value;
//             start->next=NULL;
//             temp=start;
//             continue;
//         }
//         else
//         {
//             temp->next= (struct node *) malloc( sizeof(struct node) );
//             temp=temp->next;
//             temp->data=value;
//             temp->next=NULL;
//         }
//     }
// }
// int main()
// {
    
//      int m,n;
    
//     int t,n1;
//     scanf("%d",&t);
//     while (t--) {
//         scanf("%d",&n1);
//         scanf("%d",&m);
//         scanf("%d",&n);
//         insert(n1);

//         linkdelete(start,m,n);
        
        
//         printList(start);
//     }
    
//     return 0;
// }

// /*This is a function problem.You only need to complete the function given below*/
// /*
// delete n nodes after m nodes
//   The input list will have at least one element  
//   Node is defined as 
//   struct node
//   {
//      int data;
//      struct node *next;
//   }
// */
// void linkdelete(struct node  *head, int M, int N)
// {
// //Add code here   
// }
