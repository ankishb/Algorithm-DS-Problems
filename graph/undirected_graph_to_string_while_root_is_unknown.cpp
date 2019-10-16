// This program can also detect multiple root nodes
/*
10 8
4 2
4 3
1 6
1 7
2 1
2 5

Root node: 4 
Tranversing tree in preorder fashion
4 2 1 6 7 5 3 
Tree to String
4(2(1(6)(7))(5))(3)

7 6
3 2
5 3
2 4
3 6
4 1
1 7

Root nodes: 5 
Tranversing tree in preorder fashion
5 3 2 4 1 7 6 
Tree to String
5(3(2(4(1(7))))(6))

*/
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

class TreeNode{
public:
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data):value(data), left(NULL), right(NULL){}
};

void tranverse_tree(TreeNode* root){
    if(root == NULL) return ;
    cout<<root->value<<" ";
    tranverse_tree(root->left);
    tranverse_tree(root->right);
}

string tree2str(TreeNode* root){
    if(root == NULL) return "";
    
    string left = tree2str(root->left);
    string right = tree2str(root->right);
    if(left != "") left = "(" + left + ")";
    if(right != "") right = "(" + right + ")";
    
    return to_string(root->value) + left + right;
}
void build_tree(vector<pair<int,int>> edges){
    unordered_map<int,TreeNode*> map;
    TreeNode* root = NULL;
    int u, v;
    for(auto e : edges){
        u = e.f, v = e.s;
        if(map.find(u) == map.end()){
            map[u] = new TreeNode(u);
        }
        if(map.find(v) == map.end()){
            map[v] = new TreeNode(v);
        }
        // u being parent and v is child
        if(map[u]->left == NULL) map[u]->left = map[v];
        else map[u]->right = map[v];
    }
    
    vector<int> parent(map.size()+1, -1);
    for(auto e : edges){
        u = e.f, v = e.s;
        parent[v] = u;
    }
    
    vector<int> roots;
    cout<<"Root node: ";
    // find the node, with no parent
    for(int i=1; i<map.size()+1; i++){
        if(parent[i] == -1){
            cout<<i<<" ";
            roots.push_back(i);
        }
    }
    
    cout<<"\nTranversing tree in preorder fashion\n";
    tranverse_tree(map[roots[0]]);
    
    cout<<"\nTree to String\n";
    cout<<tree2str(map[roots[0]]);
}
int main()
{
    int n, e, u, v;
    cin>>n>>e;
    // u is parent, and v is its child
    vector<pair<int,int>> edges;
    for(int i=0; i<e; i++){
        cin>>u>>v;
        edges.push_back({u,v});
    }
    
    build_tree(edges);
    
    return 0;
}