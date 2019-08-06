/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    unordered_map<Node*, Node*> my_map;
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        Node* main = new Node(node->val, {});
        Node* front;
        my_map[node] = main;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            front = q.front();
            q.pop();
            
            for(auto neigh : front->neighbors){
                cout<< neigh->val <<" ";
                if(my_map.find(neigh) == my_map.end()){
                    q.push(neigh);
                    Node* temp = new Node(neigh->val, {});
                    my_map[neigh] = temp;
                }
                my_map[front]->neighbors.push_back(my_map[neigh]);
                
            }
        }
        return main;
    }
};
