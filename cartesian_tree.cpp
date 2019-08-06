#include <iostream>
#include <vector>
using namespace std;

// Data structure to store a Cartesian tree node
struct Node {
	int data;
	Node *left, *right;
};

// Function to create a new Cartesian tree node having given key
Node* newNode(int key)
{
	Node* node = new Node;
	node->data = key;
	node->left = node->right = nullptr;

	return node;
}

// Recursive function to perform inorder traversal of a Cartesian tree
void inorderTraversal(Node* root)
{
	if (root == nullptr)
		return;

	inorderTraversal(root->left);
	cout << root->data << ' ';
	inorderTraversal(root->right);
}

// Function to find index of the minimum element in inorder[start, end]
int minElementIndex(vector<int> const &inorder, int start, int end)
{
	int minIndex = start;
	for (int i = start + 1; i <= end; i++)
	{
		if (inorder[minIndex] > inorder[i])
			minIndex = i;
	}

	return minIndex;
}

// Recursive function to construct a Cartesian tree from given
// inorder sequence
Node* constructTree(vector<int> const &inorder, int start, int end)
{
	// base case
	if (start > end)
		return nullptr;

	// Find index of the minimum element in inorder[start, end]
	int index = minElementIndex(inorder, start, end);

	// The minimum element in given range of inorder sequence becomes the root
	Node *root = newNode(inorder[index]);

	// recursively construct the left subtree
	root->left  = constructTree(inorder, start, index - 1);

	// recursively construct the right subtree
	root->right = constructTree(inorder, index + 1, end);

	// return current node
	return root;
}

// main function
int main()
{
	// input sequence of numbers representing the in-order sequence
	vector<int> inorder = { 9, 3, 7, 1, 8, 12, 10, 20, 15, 18, 5 };

	// construct the Cartesian tree
	Node *root = constructTree(inorder, 0, inorder.size() - 1);

	// print the Cartesian tree
	cout << "Inorder Traversal of constructed Cartesian tree is:\n";
	inorderTraversal(root);

	return 0;
}