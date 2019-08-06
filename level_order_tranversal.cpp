
#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* getNewNode(int data){
	node* newNode = new node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
}

int get_height(node* tree){
	if(tree == NULL){
		return 0;
	}
	int left_h = get_height(tree->left);
	int right_h = get_height(tree->right);
	if(left_h >= right_h){
		return left_h+1;
	}
	else{
		return right_h+1;
	}
}

void get_current_level_nodes(node* tree, int level, vector<int> &vect){
	// cout<<"hii \n";
	if(tree == NULL){
		// cout<<"\n do nothing \n";
	}
	else if(level == 1){
		// cout<<tree->data<<" ";
		vect.push_back(tree->data);		
	}
	else{
		get_current_level_nodes(tree->left, level-1, vect);
		get_current_level_nodes(tree->right, level-1, vect);
	}
}

// vector<vector<int> > level_order_tranversal(node* tree){
// 	vector<vector<int> >vect;
// 	int depth = get_height(tree);
// 	for(int i=1; i<=depth; i++){
// 		cout<<"current level: "<<i<<endl;
// 		get_current_level_nodes(tree, i, vect[i-1]);
// 	}
// 	return vect;
// }

void level_order_tranversal(node* root, vector<vector<int> > &vect){
	// vector<vector<int> >vect;	
	queue<node*> q;
	int node_count = 0;
	int cur_count = 0;

	q.push(root);
	while(!q.empty()){
		node_count = q.size();
		cout<<node_count<<endl;
		while(node_count--){
			node* q_front = q.front();
			q.pop();
			vect[cur_count].push_back(q_front->data);

		// 	if(q_front->left != NULL){
		// 		q.push(q_front->left);
		// 	}
		// 	if(q_front->right != NULL){
		// 		q.push(q_front->right);
		// 	}
		// 	cur_count++;
		}
	}
	// return vect;
}

int main()
{
	node* root = NULL;
	root = getNewNode(3);
	root->left = getNewNode(9);
	root->right = getNewNode(20);
	root->right->left = getNewNode(15);
	root->right->right = getNewNode(7);

	cout<<"height of tree: "<<get_height(root)<<endl;

	vector<vector<int> > vect;
	level_order_tranversal(root, vect);

	cout<<"\n---- level order transversal ----\n";
	for(int i=0; i<vect.size(); i++){
		for(int j=0; j<vect[i].size(); j++){
			cout<<vect[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"---- END of level order transversal ----\n";

	return 0;
}














// Iterative method to do level order traversal 
// line by line  
void printLevelOrder(node *root)  
{  
    // Base Case  
    if (root == NULL) return;  
  
    // Create an empty queue for level order tarversal  
    queue<node *> q;  
  
    // Enqueue Root and initialize height  
    q.push(root);  
  
    while (q.empty() == false)  
    {  
        // nodeCount (queue size) indicates number 
        // of nodes at current lelvel.  
        int nodeCount = q.size();  
  
        // Dequeue all nodes of current level and  
        // Enqueue all nodes of next level  
        while (nodeCount > 0) 
        {  
            node *node = q.front();  
            cout << node->data << " ";  
            q.pop();  
            if (node->left != NULL)  
                q.push(node->left);  
            if (node->right != NULL)  
                q.push(node->right);  
            nodeCount--;  
        }  
        cout << endl;  
    }  
}  