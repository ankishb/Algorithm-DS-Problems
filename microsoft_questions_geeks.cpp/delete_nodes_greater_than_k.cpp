
Node* find_and_delete(Node* root, int key){
	if(root == NULL) return NULL;
	if(root->data >= key){
		if(root->left != NULL){
			root = root->left;
			return find_and_delete(root, key);
		}
		else{
			root = NULL;
		}
	}

	else if(root->data < key){
		root->right = find_and_delete(root->right, key);
	}
	return root;
}

Node* deleteNode(Node* root, int key){
    if(root == NULL) return NULL;
    return find_and_delete(root, key);
}