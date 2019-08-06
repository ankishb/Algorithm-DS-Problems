/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; 
*/


void connect(Node *root){
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	Node* front;
	while(!q.empty()){
		if(q.front()==NULL && q.size()==1){
			break;
		}
		front = q.front();
		q.pop();

		if(q.front() != NULL){
			front->nextRight = q.front();
		}
		if(front->left) q.push(front->left);
		if(front->right) q.push(front->right);

		if(q.front() == NULL){
			q.pop();
			q.push(NULL);
		}
	}   
}

