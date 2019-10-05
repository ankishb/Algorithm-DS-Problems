
#include <bits/stdc++.h>
using namespace std;
/*
1 X : Move the message with ID X from UNREAD to READ.
2 X : Move the message with ID X from READ to TRASH.
3 X : Move the message with ID X from UNREAD to TRASH.
4 X : Move the message with ID X from TRASH to READ.
*/
class node{
public:
    int data;
    node* next;
    
    node(int x): data(x), next(NULL){}
    // node(int x){
    //     data = x;
    //     next = NULL;
    // }
};

node* insert_node(node* head, int data){
    // insert node at the end
    if(head == NULL){
        head = new node(data);
        return head;
    }
    else{
        node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = new node(data);
        return head;
    }
}

node* delete_node(node* head, int key){
    if(head->data == key){
        return head->next;
    }
    else{
        node* temp = head;
        while(temp->next){
            if(temp->next->data == key){
                temp->next = temp->next->next;
                return head;
            }
        }
        return head;
    }
}

void print(node* sur){
    while(sur){
        cout<<sur->data<<" ";
        sur = sur->next;
    }cout<<endl;
}
void solve(){
    int n, nq;
    cin>>n>>nq;
    node *unread = NULL;
    node *sur, *sr, *st;
    for(int i=1; i<=n; i++){
        if(unread == NULL){
            unread = new node(i);
            sur = unread;
        }
        else{
            unread->next = new node(i);
            unread = unread->next;
        }
    }
    // print(sur);
    for(int i=0; i<nq; i++){
        int q, x;
        cin>>q>>x;
        switch(q){
            case 1:
                // unread to read
                sur = delete_node(sur, x);
                sr = insert_node(sr, x);
            case 2:
                // read to trash
                sr = delete_node(sr, x);
                st = insert_node(st, x);
            case 3:
                // unread to trash
                sur = delete_node(sur, x);
                st = insert_node(st, x);
            case 4:
                // trash to read
                st = delete_node(st, x);
                sr = insert_node(sr, x);
        }
    }
    print(sur);
    print(sr);
    print(st);
}

int main()
 {
	int test;
	cin>>test;
	while(test--){
	    solve();
	}
	return 0;
}