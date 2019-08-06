
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int itr = 0;
vector<int> store;

void inorder(TreeNode* root){
    if(root == NULL){
        return ;
    }
    inorder(root->left);
    store.push_back(root->val);
    inorder(root->right);
}

BSTIterator::BSTIterator(TreeNode *root) {
    store.clear();
    itr = 0;
    inorder(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return (itr+1 <= store.size());
}

/** @return the next smallest number */
int BSTIterator::next() {
    int el = store[itr];
    itr++;
    return el;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */







// editorial
class BSTIterator {
    public:
        stack<TreeNode *> myStack;

        BSTIterator(TreeNode *root) {
            pushAll(root);
        }

        /** @return whether we have a next smallest number */
        bool hasNext() {
            return !myStack.empty();
        }

        /** @return the next smallest number */
        int next() {
            TreeNode *tmpNode = myStack.top();
            myStack.pop();
            pushAll(tmpNode->right);
            return tmpNode->val;
        }

    private:
        void pushAll(TreeNode *node) {
            while (node != NULL) {
                myStack.push(node);
                node = node->left;
            }
        }
};




// light-weight

TreeNode *head;
BSTIterator::BSTIterator(TreeNode *root) {
    head=root;
}

bool BSTIterator::hasNext() {
    if(head!=NULL)
        return true;
    return false;
}

int BSTIterator::next() {
    TreeNode *p=head;
    TreeNode *q=head;
    TreeNode *r=head;
    while(q->left){
        r=q;
        q=q->left;
    }
    if(q==p){
        int data=q->val;
        q=q->right;
        head=q;
        delete p;
        return data;
    }
    else{
        r->left=q->right;
        int data=q->val;
        delete q;
        return data;
    }
}







// constant space (amortized O(1) space complexity) (leetcode)

//
class BSTIterator {
public:
BSTIterator(TreeNode *root) {
    p = root;
}

/** @return whether we have a next smallest number */
bool hasNext() {
    return p != NULL;
}

/** @return the next smallest number */
int next() {
    TreeNode *tmp;
    int ret;
    while(p) {
        if (p->left == NULL) {  
            ret = p->val;
            p = p->right;
            break;
        }  
        else {  
            tmp = p->left;  
            while (tmp->right != NULL && tmp->right != p)  
                tmp = tmp->right;  
            if (tmp->right == NULL) {  
                tmp->right = p;  
                p = p->left;  
            }  
            else {
                ret = p->val;
                tmp->right = NULL;  
                p = p->right;
                break;
            }  
        }  
    }
    
    return ret;
}

TreeNode *p;
};