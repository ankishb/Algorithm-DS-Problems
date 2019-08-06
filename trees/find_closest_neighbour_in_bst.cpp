// Given a binary search tree and a number N. Your task is to complete the function findMaxforKey(), that find's the greatest number in the binary search tree that is less than or equal to N. Print the value of the element if it exists otherwise print -1.

// 2
// 8
// 5 2 L 5 12 R 2 1 L 2 3 R 12 9 L 12 21 R 21 19 L 21 25 R
// 24
// 4
// Out:
// 21
// 3

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


void find_closest_neighbour(Node* root, int x, int &ans){
	if(root == NULL) return ;
	if(root->key <= x && ans < root->key){
		ans = root->key;
	}

	if(root->key < x){
		find_closest_neighbour(root->right, x, ans);
	}
	else{
		find_closest_neighbour(root->left, x, ans);
	}
}

int findMaxForN(Node* root, int x, int size){
    int ans = -1;
    find_closest_neighbour(root, x, ans);
    // cout<<ans<<endl;
    if(ans <= x ) cout<<ans<<endl;
    else cout<<-1<<endl;
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





