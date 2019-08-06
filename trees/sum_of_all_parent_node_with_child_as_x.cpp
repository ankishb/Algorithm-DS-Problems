// Given a binary tree containing n nodes. The problem is to find the sum of all the parent node’s which have a child node with value x.
// 1
// 6
// 4 2 L 4 5 R 2 7 L 2 2 R 5 2 L 5 3 R
// 2
// 11
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

void trans(Node* root){
    if(root == NULL) return ;
    trans(root->left);
    cout<<root->data<<" ";
    trans(root->right);
}

void collect_parent_nodes(Node* root, int x, vector<int> &vect){
	if(root == NULL) return;

	if((root->left != NULL && root->left->data == x) || 
	   (root->right != NULL && root->right->data == x)){
		vect.push_back(root->data);
	}
	collect_parent_nodes(root->left, x, vect);
	collect_parent_nodes(root->right, x, vect);
}


void sum_of_all_parent_nodes_with_child_x(Node* root){
    // trans(root);
	int x;
	cin>>x;
	vector<int> ans;
	cout<<root->data<<" "<<x<<endl;
	collect_parent_nodes(root, x, ans);
	int sum = 0;
	for(auto itr:ans){
		cout<<itr<<" ";
		sum += itr;
	}
	cout<<endl;
	cout<<sum<<endl;
}





struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        map<int, Node*> m;
        int n;
        scanf("%d ",&n);
        struct Node *root = NULL;
        if(n==1){
            int a;
            cin>>a;
            cout<<a<<endl;
        }
        else{
            while (n--){
                Node *parent;
                char lr;
                int n1, n2;
                scanf("%d %d %c", &n1, &n2, &lr);
                //  cout << n1 << " " << n2 << " " << (char)lr << endl;
                if (m.find(n1) == m.end()){
                    parent = newNode(n1);
                    m[n1] = parent;
                    if (root == NULL)
                        root = parent;
                    }
                else
                    parent = m[n1];
                    child = newNode(n2);
                if (lr == 'L')
                    parent->left = child;
                else
                    parent->right = child;
                    m[n2]  = child;
            }
            sum_of_all_parent_nodes_with_child_x(root);
        }
    }
    return 0;
}





///////////////
void sumOfParentOfX(Node* root, int& sum, int x) 
{ 
    // if root == NULL 
    if (!root) 
        return; 
      
    // if left or right child of root is 'x', then 
    // add the root's data to 'sum' 
    if ((root->left && root->left->data == x) || 
        (root->right && root->right->data == x)) 
        sum += root->data; 
      
    // recursively find the required parent nodes 
    // in the left and right subtree     
    sumOfParentOfX(root->left, sum, x); 
    sumOfParentOfX(root->right, sum, x); 
      
} 
  
// utility function to find the sum of all 
// the parent nodes having child node x 
int sumOfParentOfXUtil(Node* root, int x) 
{ 
    int sum = 0; 
    sumOfParentOfX(root, sum, x); 
      
    // required sum of parent nodes 
    return sum; 
} 