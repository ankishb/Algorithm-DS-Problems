{
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
void verticalOrder(Node *root);
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d
",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     verticalOrder(root);
     cout << endl;
  }
  return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
bool sortBySecond(pair<int, int> p1, pair<int, int> p2){
    return p1.second<p2.second;
}
void verticalOrder(Node *root){
    // vector<vector<int> > ans;
    pair<Node*, int> p;
    queue<pair<Node*, int> > q;
    multimap<int, int> my_map;
    vector<pair<int, int> > ans;
    q.push(make_pair(root, 0));
    while(!q.empty()){
        p = q.front();
        // cout<< (p.first)->data <<" "<< p.second <<endl;
        // ans.push_back(make_pair((p.first)->data, p.second));
        q.pop();
        if((p.first)->left != NULL){
            q.push(make_pair((p.first)->left, (p.second)-1));
        }
        if((p.first)->right != NULL){
            q.push(make_pair((p.first)->right, (p.second)+1));
        }
        
        my_map.insert({p.second, (p.first)->data});
    }
    // sort(ans.begin(), ans.end(), sortBySecond);
    // cout<<"\n check sorted vector\n";
    for(auto itr : my_map){
        // cout<<itr.first <<" : "<<itr.second<<endl;
        cout<<itr.second <<" ";
    }
}

