
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

void level_order_tranversal(node* root, vector<vector<int> > &ans){
	queue<node*> q;
	node* null_node = NULL;
	if(root != NULL){
		q.push(root);
		q.push(null_node);
	}
	while(root != NULL){
		node *top = q.front();
		if(top != NULL){
			cout<<top->data<<" ";
			q.pop();
			if(top->left != NULL){
				q.push(top->left);
			}
			if(top->right != NULL){
				q.push(top->right);
			}
		}
		else{
			q.pop();
			q.push(top);
			cout<<endl;
		}
	}
}

void level_order_tranversal3(node* root, vector<vector<int> > &ans){
	vector<int> one_level;
	queue<node*> q;
	node* null_node = NULL;
	if(root != NULL){
		q.push(root);
		q.push(null_node);
	}

	while(q.front()!=NULL || q.back()!=NULL){
		node *top = q.front();
		if(top != NULL){
			cout<<top->data<<" ";
			one_level.push_back(top->data);
			q.pop();
			if(top->left != NULL){
				q.push(top->left);
			}
			if(top->right != NULL){
				q.push(top->right);
			}
		}
		else{
			q.pop();
			q.push(top);
			cout<<endl;
			ans.push_back(one_level);
			one_level.clear();
		}
	}
	// pushlast level element in ans too
	ans.push_back(one_level);
	one_level.clear();
}

int main()
{
	node* root = NULL;
	root = getNewNode(3);
	root->left = getNewNode(9);
	root->right = getNewNode(20);
	root->right->left = getNewNode(15);
	root->right->right = getNewNode(7);

	vector<vector<int> > vect;
	level_order_tranversal3(root, vect);

	cout<<"\n---- level order transversal ----\n";
	for(int i=0; i<vect.size(); i++){
		for(int j=0; j<vect[i].size(); j++){
			cout<<vect[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"---- END of level order transversal ----\n";

	return 0;
}