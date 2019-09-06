/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root == NULL) return root;
        q.push(root);
        q.push(NULL);
        Node* front;
        while(true){
            front = q.front();
            q.pop();
            front->next = q.front();
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
            
            if(q.front() == NULL && q.size()==1) break;
            if(q.front() == NULL){
                q.pop(); q.push(NULL);
            }
        }
        return root;        
    }
};







class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* leftWall = NULL; // leftmost node of the next level.
        TreeLinkNode* prev = NULL; // leading node on the next level
        TreeLinkNode* cur = root; // current node on the current level

        while (cur != NULL) {
            while (cur != NULL) {
                if (cur->left != NULL) {
                    if (prev != NULL) {
                        prev->next = cur->left;
                    } 
                    else leftWall = cur->left;
                    prev = cur->left;
                }

                if (cur->right != NULL) {
                    if (prev != NULL) {
                        prev->next = cur->right;
                    } 
                    else leftWall = cur->right;
                    prev = cur->right;
                }
                // move to the next node
                cur = cur->next;
            }

            // move to the next level
            cur = leftWall;
            leftWall = NULL;
            prev = NULL;
        }
    }
};