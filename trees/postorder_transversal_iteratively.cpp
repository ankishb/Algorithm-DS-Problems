



// previous geeksforgeeks question
void postorder_transversal(node *root){
	stack<node*> s;
	if(root == NULL){
		cout<<"NULL";
	}
	else{
		s.push(root);
		root = root->left;
		while(!s.empty()){
			int top = s.top();
			if(root != NULL){
				s.push(root);
				root = root->left;
			}
			else{
				cout<<top->data<<" ";
				s.pop();
				top = s.top();
				if(top->right != NULL){
					s.top(top->right);
				}
			}
		}
	}
}





// very good solution using 1 as well as 2 stacks

// Recursive Postorder Transversal 
// -2 5 -3 -1 21 6 11 1 
// Iterative-1 Postorder Transversal 
// -2 5 -3 -1 21 6 11 1 
// Iterative-2 Postorder Transversal 
// -2 5 -3 -1 21 6 11 1 21 6 11 1 

#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* getNewNode(int data){
	node* newNode = new node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
}

void rec_postorder_transversal(node *root){
	if(root == NULL){
		return ;
	}
	rec_postorder_transversal(root->left);
	rec_postorder_transversal(root->right);
	cout<<root->data<<" ";
}

void itr1_postorder_transversal(node* root){
	stack<node*> s1;
	stack<node*> s2;

	s1.push(root);
	node *top;
	while(!s1.empty()){
		top = s1.top();
		s1.pop();
		s2.push(top);
		if(top->left == NULL && top->right == NULL){
			continue;
		}
		if(top->left != NULL){
			s1.push(top->left);
		}
		if(top->right != NULL){
			s1.push(top->right);
		}
	}

	while(!s2.empty()){
		cout<<(s2.top())->data<<" ";
		s2.pop();
	}
	cout<<endl;
}



void itr2_postorder_transversal(node *root){
	// Time: O(n) || Space: O(h)
	stack<node*> s;
	node *cur = root;
	node *popped = NULL; // will use for special case
	node *top;
	s.push(cur);

	while(!s.empty()){
		if(cur == NULL){
			top = s.top();
			if(top->right == NULL){
				cout<<top->data<<" ";
				s.pop();
				while(!s.empty() && top == (s.top())->right){
					top == s.top();
					cout<<top->data<<" ";
					s.pop();
				}
			}
			else{
				cur = top->right;
			}


			if(top->right != NULL){
				if(top->right != popped){
					cur = top->right;
				}
				else{
					popped = s.top();
					cout<<popped->data<<" ";
					s.pop();
				}
			}
			else{
				popped = s.top();
				cout<<popped->data<<" ";
				s.pop();
			}
		}
		else{
			s.push(cur);
			cur = cur->left;
		}
	}
}


void itr3_postorder_transversal(node *root){
	// Time: O(n) || Space: O(h)
	stack<node*> s;
	node *cur = root;
	node *popped = NULL; // will use for special case
	node *top;

	while(cur != NULL || !s.empty()){
		if(cur == NULL){
			top = s.top();
			if(top->right == NULL){
				cout<<top->data<<" ";
				s.pop();
				while(!s.empty() && top == (s.top())->right){
					top == s.top();
					cout<<top->data<<" ";
					s.pop();
				}
			}
			else{
				cur = cur->right;
			}
		}
		else{
			s.push(cur);
			cur = top->right;
		}
	}
}


int main()
{
	node* root = NULL;
	root = getNewNode(1);
	root->left = getNewNode(-1);
	root->right = getNewNode(11);
	root->left->left = getNewNode(-2);
	root->left->right = getNewNode(-3);
	root->left->right->right = getNewNode(5);
	root->right->left = getNewNode(21);
	root->right->right = getNewNode(6);

	cout<<"\nRecursive Postorder Transversal \n";
	rec_postorder_transversal(root);
	
	cout<<"\nIterative-2 Postorder Transversal \n";
	itr2_postorder_transversal(root);

	cout<<"\nIterative-3 Postorder Transversal \n";
	itr3_postorder_transversal(root);

	return 0;
}

