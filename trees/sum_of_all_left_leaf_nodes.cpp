
// new try
/*
Tranverse in preorder manner and send flag as "L" and "R". 
Collect value of all "L" at leaf node
*/
int get_ans(Node* root, char flag){
    if(root == NULL) return 0;
    if(!root->left && !root->right){
        return (flag=='L') ? root->data : 0;
    }
    int l = get_ans(root->left, 'L');
    int r = get_ans(root->right, 'R');
    return l+r;
}

int leftLeafSum(Node* root){
    return get_ans(root, 'a');
}


// old one
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

void sum_of_left_leaf(Node* root, int &sum){
	if(root == NULL) return;
	Node* next = root->left;

	if(next!=NULL && next->left==NULL && next->right==NULL){
		// we are at left leaf node
// 		cout<<next->data<<" : ";
		sum += next->data;
	}
	sum_of_left_leaf(root->left, sum);
	sum_of_left_leaf(root->right, sum);
}

int perform_operation(Node* root){
	int sum = 0;
	sum_of_left_leaf(root, sum);
	return sum;
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
            perform_operation(root);
        }
    }
    return 0;
}





