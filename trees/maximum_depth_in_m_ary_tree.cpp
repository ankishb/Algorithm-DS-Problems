
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root, int count = 0) {
        if(root == NULL) return 0;
        // if(root->children.size() == 0) return 1;
        int cd = 0;
        for(auto c : root->children){
            cd = max(cd, maxDepth(c, count+1));
        }
        return cd+1;
    }
};