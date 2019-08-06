

    void helper(Node* root, int data){
        if(root->data < data){
            if(root->right != NULL) helper(root->right, data);
            else { root->right = new Node(data); return ;}
        }
        else if(root->data > data){
            if(root->left != NULL) helper(root->left, data);
            else { root->left = new Node(data); return ;}
        }
    }

    Node * insert(Node * root, int data) {
        if(root == NULL) root = new Node(data);
        helper(root, data);
        return root;
    }



    Node* insert(Node* root,int data) {
        if(root==null) root = new Node(data);
        else if(root.data > value)
            root.left = Insert(root->left,value);
        else if(root.data < value)
            root.right = Insert(root->right,value);

        return root;
    }
