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