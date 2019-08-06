

Node* lca(Node *root, int n1, int n2){
   	if(root == NULL) return NULL;
   	if(root->data == n1 || root->data == n2){
   		return root;
   	}

   	Node* left_lca = lca(root->left, n1, n2);
   	Node* right_lca = lca(root->right, n1,n2);

   	if(left_lca == NULL && right_lca == NULL){
   	    return NULL;
   	}
    else if(left_lca!=NULL && right_lca!=NULL){
   		return root;
   	}
   	else if(left_lca == NULL) return right_lca;
   	else if(right_lca == NULL) return left_lca;
}
