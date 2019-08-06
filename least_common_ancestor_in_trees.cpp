// binary tree node
Node * LCA(Node* root ,int n1 ,int n2 ){
	if(root==NULL){
		return NULL;
	}
	if(root->data == n1 || root->data == n2){
		return root;
	}
	Node* left_lca = LCA(root->left, n1, n2);
	Node* right_lca = LCA(root->right, n1, n2);

	if((left_lca==NULL) && (right_lca==NULL)){
		return NULL;
	}
	else if(left_lca && right_lca){
		return root;
	}
	else{
		return (left_lca==NULL)?right_lca:left_lca;
	}
}




// bst
Node* LCA(Node *root, int n1, int n2){
	if(root==NULL){
		cout<<" "<<endl;
	}
	bool break_flag = false;
	while(root!=NULL && break_flag==false){
		// if((n1 < root->data) && (n2 > root->data)){
		// 	cout<<root->data<<endl;
		// 	break;
		// }
		// else if((n1 > root->data) && (n2 < root->data)){
		// 	cout<<root->data<<endl;
		// 	break;
		// }
		if((n1 < root->data) && (n2 < root->data)){
			root = root->left;
		}
		else if((n1 > root->data) && (n2 > root->data)){
			root = root->right;
		}
		else{
// 			cout<<root->data<<endl;
			return root;
			break_flag = true;
		}
	}
}