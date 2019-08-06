
class Solution {
    public:
        Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }


    void topView(Node * root) {
        if(root == NULL) return ;
        queue<pair<Node*, int> > q;
        q.push(make_pair(root, 0));
        Node* null_ = NULL, *temp;
        int idx;
        q.push(make_pair(null_, 0));
        pair<Node*, int> front;
        unordered_set<int> vis;
        vis.clear();
        vector<pair<int, int>> store;
        while(!q.empty()){
            front = q.front();
            temp = front.first;
            idx = front.second;
            if(vis.count(idx) == 0){
                // cout<<temp->data<<" ";
                store.push_back(make_pair(idx, temp->data));
                vis.insert(idx);
            }            
            q.pop();
            if(temp->left) q.push(make_pair(temp->left, idx-1));
            if(temp->right) q.push(make_pair(temp->right, idx+1));
            if(q.front().first == null_ && q.size() == 1) break;
            if(q.front().first == null_){ 
                q.pop(); q.push(make_pair(null_, 0));
            }
        }
        sort(store.begin(), store.end());
        for(auto itr : store){
            cout<<itr.second<<" ";
        }
    }
};