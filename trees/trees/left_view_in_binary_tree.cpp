


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
// A wrapper over leftViewUtil()

void print_left_node(Node* root, int level, bool print_);
int get_height(struct Node* root);
void leftView(struct Node* root);
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
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
     leftView(root);
     cout << endl;
  }
  return 0;
}



/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
// A wrapper over leftViewUtil()
int get_height(Node* root){
	if(root == NULL){
		return 0;
	}
	int left_height = get_height(root->left);
	int right_height = get_height(root->right);

	if(left_height > right_height){
		return left_height+1;
	}
	else{
		return right_height+1;
	}
}

void print_left_node(Node* root, int level, bool print_){
	if(root == NULL){
		return;
	}
	if(level == 1 ){
		if(print_ == true){
			cout<< root->data << " "<<endl;
		}
	}
	else if(level > 1){
		// cout<<level<<"=="<<root->data<<endl;
		print_left_node(root->left, level-1, true);
		print_left_node(root->right, level-1, false);
	}
}

void leftView(Node* root)
{
	int height = 0;
	height = get_height(root);
	cout<<"height: "<<height<<endl;
    
    bool print_ = true;
	for(int i=1; i<=height; i++){
		cout<<"level: "<<i<<endl;
		print_left_node(root, i, print_);
	}
}