[LeetCode] Boundary of Binary Tree Boundary of Binary Tree

Given a binary tree, return the values ​​of its boundary in anti-clockwise direction starting from root. Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.

Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself is Left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.

The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.

The right-most node is also defined by the same way with left and right exchanged.

Example 1

  Input:
   1
    \
     2
    / \
   3 4

 Ouput:
 [1, 3, 4, 2]

 Explanation:
 The root doesn't have left subtree, so the root itself is left boundary.
 The leaves are node 3 and 4.
 The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
 So order them in anti-clockwise without duplicates and we have [1,3,4,2].

Example 2

  Input:
     ____1_____
    / \
   twenty three
  / \ / 
 4 5 6   
    / \ / \
   7 8 9 10  
       
 Ouput:
 [1,2,4,7,8,9,10,6,3]

 Explanation:
 The left boundary are node 1,2,4. (4 is the left-most node according to definition)
 The leaves are node 4,7,8,9,10.
 The right boundary are node 1,3,6,10. (10 is the right-most node).
 So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].

This question gives us a binary tree, let us output the boundaries of the tree in a counterclockwise order, in order of left, leaf, and right. The examples given in the title also give us a clear idea of ​​what counts as nodes on the boundary. Then the most straightforward method is to find the left boundary node, the leaf node, and the right boundary node in order. So how to ask, the operation of the tree must be the most concise recursion, so we can write three recursive functions to find the left boundary node, the leaf node, and the right boundary node. First of all, we have to deal with the root node first. When the root node has no left and right child nodes, it is also a leaf node. Then we add it to the result res at the beginning, then calculate the leaf node again. Will join again, this is not right. So we judge that if the root node has at least one child node, we will add it to the result res in advance. Then look at the function of the left boundary node, if the current node does not exist, or there is no child node, we return directly. Otherwise, the current node value is added to the result res, and then if the left child node exists, the recursive function is called, and if the left child node does not exist, the recursive function is called for the right child node. The function for finding the right boundary node is reversed. If the right child node exists, it will call the recursive function. Otherwise, if the right child node does not exist, the recursive function will be called for the left child node. The recursive function is added to the result res after the node value, because we need to output in a counterclockwise order. Finally, look at the function of the leaf node. There is nothing to say, that is, if there is no child node, the result res is added, and then the recursion can be called for the left and right child nodes respectively. See the code as follows:

Solution one:

  Class Solution { 
  Public : 
      Vector < int > boundaryOfBinaryTree(TreeNode* root) { 
          If (!root) return {}; 
          Vector < int > res; 
          If (root->left || root->right) res.push_back(root-> val); 
          leftBoundary(root -> left, res); 
          Leaves(root, res); 
          rightBoundary(root -> right, res); 
          Return res; 
      } 
      Void leftBoundary(TreeNode* node, vector< int >& res) { 
          If (!node || (!node->left && !node->right)) return ; 
          Res.push_back(node -> val); 
          If (!node->left) leftBoundary(node-> right, res); 
          Else leftBoundary(node-> left, res); 
      } 
      Void rightBoundary(TreeNode* node, vector< int >& res) { 
          If (!node || (!node->left && !node->right)) return ; 
          If (!node->right) rightBoundary(node-> left, res); 
          Else rightBoundary(node-> right, res); 
          Res.push_back(node -> val); 
      } 
      Void leaves(TreeNode* node, vector< int >& res) { 
          If (!node) return ; 
          If (!node->left && !node-> right) { 
              Res.push_back(node -> val); 
          } 
          Leaves(node -> left, res); 
          Leaves(node -> right, res); 
      } 
  }; 

The following method combines the above three different recursions into a recursion, and uses the bool-type variable to mark whether the current boundary node is the left boundary node or the right boundary node, and the leaf node is added to the result res. Features. If the left boundary is marked as true, then the node value is added to the result res. The following is the call to the recursive function for the left and right nodes. According to the above solution, we know that if the left boundary node is sought, the left child node is called first, and when the left child node does not exist, the right child node is adjusted. For the right boundary node, the right is called first. Child node, the left child node is called when the right child node does not exist. In summary, when the recursive function is called on the left child node, the left boundary identifier is set to leftbd && node->left, and the recursive left boundary identifier for the right child node is set to leftbd && !node->left. The left child node will be called first. The right boundary node is just the opposite. The right border of the call to the left child node is identified as rightbd && !node->right, and the right border of the right child node is called rightbd && node->right, which guarantees The existence of the right child node will be called first, see the code below:

Solution 2:

  Class Solution { 
  Public : 
      Vector < int > boundaryOfBinaryTree(TreeNode* root) { 
          If (!root) return {}; 
          Vector < int > res{root-> val}; 
          Helper(root ->left, true , false , res); 
          Helper(root ->right, false , true , res); 
          Return res; 
      } 
      Void helper(TreeNode* node, bool leftbd, bool rightbd, vector< int >& res) { 
          If (!node) return ; 
          If (!node->left && !node-> right) { 
              Res.push_back(node -> val); 
              Return ; 
          } 
          If (leftbd) res.push_back(node-> val); 
          Helper(node ->left, leftbd && node->left, rightbd && !node-> right, res); 
          Helper(node ->right, leftbd && !node->left, rightbd && node-> right, res); 
          If (rightbd) res.push_back(node-> val); 
      } 
  }; 

The following solution is actually an iterative form of solution one. The overall idea is basically the same, but there is no recursive writing, but the iterative writing of while is used. Note that it is difficult to write directly when iterating the right boundary node. In the counterclockwise order, we can save it in reverse, and then adjust the order. See the code below:

Solution three:

  Class Solution { 
  Public : 
      Vector < int > boundaryOfBinaryTree(TreeNode* root) { 
          If (!root) return {}; 
          Vector < int > res, right; 
          TreeNode *l = root->left, *r = root->right, *p = root; 
          If (root->left || root->right) res.push_back(root-> val); 
          While (l && (l->left || l-> right)) { 
              Res.push_back(l -> val); 
              If (l->left) l = l-> left; 
              Else l = l-> right; 
          } 
          Stack <TreeNode*> st; 
          While (p || ! st.empty()) { 
              If (p) { 
                  St.push(p); 
                  If (!p->left && !p->right) res.push_back(p-> val); 
                  p = p-> left; 
              } else { 
                  p = st.top(); st.pop(); 
                  p = p-> right; 
              } 
          } 
          While (r && (r->left || r-> right)) { 
              Right.push_back(r -> val); 
              If (r->right) r = r-> right; 
              Else r = r-> left; 
          } 
          Res.insert(res.end(), right.rbegin(), right.rend()); 
          Return res; 
      } 
  }













Given a binary tree, return the values ​​of its boundary in anti-clockwise direction starting from root. Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.

Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself is Left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.

The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.

The right-most node is also defined by the same way with left and right exchanged.

Example 1

  Input:
   1
    \
     2
    / \
   3 4

 Ouput:
 [1, 3, 4, 2]

 Explanation:
 The root doesn't have left subtree, so the root itself is left boundary.
 The leaves are node 3 and 4.
 The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
 So order them in anti-clockwise without duplicates and we have [1,3,4,2]. 

Example 2

  Input:
     ____1_____
    / \
   twenty three
  / \ / 
 4 5 6   
    / \ / \
   7 8 9 10  
       
 Ouput:
 [1,2,4,7,8,9,10,6,3]

 Explanation:
 The left boundary are node 1,2,4. (4 is the left-most node according to definition)
 The leaves are node 4,7,8,9,10.
 The right boundary are node 1,3,6,10. (10 is the right-most node).
 So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].

A binary tree is given to output the boundaries of the tree in a counterclockwise order, in order of left, leaf, and right.

For the left boundary, the leaf node and the right boundary are respectively evaluated 3 times using nodes that recursively or iterate the binary tree.

Solution 1: Recursion

Solution 2: Iteration

Java:

  /**
  * Definition for a binary tree node.
  * public class TreeNode {
  * int val;
  * TreeNode left;
  * TreeNode right;
  * TreeNode(int x) { val = x; }
  * }
  */
 Public class Solution {
      
     Public List<Integer> boundaryOfBinaryTree(TreeNode root) {
         List<Integer>list=new ArrayList<>();
         If(root==null){
             Return list;
         }
         List.add(root.val);
        
         GetLeftPath(root.left,list);//add left boundary node and leaves node
         GetRightPath(root.right, list);// add right boundary node and leaves node
      
         Return list;
     }
    
     Public void GetLeftPath(TreeNode left,List<Integer>list){
         If(left!=null){
             List.add(left.val);// add the left boundary node
             If(left.left!=null){
                 GetLeftPath(left.left, list);
                 DFS (left.right, list);
             }
             Else{// according to the rule, if the node has no left subtree, then the left path goes to right
                 GetLeftPath(left.right, list);
             }
         }
     }
    
     Public void GetRightPath(TreeNode right,List<Integer>list){
         If(right!=null){
             If(right.right!=null){
                 DFS(right.left,list);
                 GetRightPath(right.right, list);
             }
             Else{
                 //according to the rule,if the node has no right subtree,then the right path goes to left
                 GetRightPath(right.left, list);
             }
             List.add(right.val);
         }
     }
    
 
     Public void DFS(TreeNode node,List<Integer>list){
         If(node!=null){
             If(node.left==null&&node.right==null){
                 List.add(node.val);
             }
             Else{
                 DFS(node.left, list);
                 DFS (node.right, list);
             }
         }
     }
 } 

Python:

  # Time: O(n)
 # Space: O(h)

 # Definition for a binary tree node.
 # class TreeNode(object):
 # def __init__(self, x):
 # self.val = x
 # self.left = None
 # self.right = None


 Class Solution(object):
     Def boundaryOfBinaryTree(self, root):
         """
         :type root: TreeNode
         :rtype: List[int]
         """
         Def leftBoundary(root, nodes):
             If not root or (not root.left and not root.right):
                 Return
             Nodes.append(root.val)
             If not root.left:
                 leftBoundary(root.right, nodes)
             Else:
                 leftBoundary(root.left, nodes)

         Def rightBoundary(root, nodes):
             If not root or (not root.left and not root.right):
                 Return
             If not root.right:
                 rightBoundary(root.left, nodes)
             Else:
                 rightBoundary(root.right, nodes)
             Nodes.append(root.val)

         Def leaves(root, nodes):
             If not root:
                 Return
             If not root.left and not root.right:
                 Nodes.append(root.val)
                 Return
             Leaves(root.left, nodes)
             Leaves(root.right, nodes)

         If not root:
             Return []

         Nodes = [root.val]
         leftBoundary(root.left, nodes)
         Leaves(root.left, nodes)
         Leaves(root.right, nodes)
         rightBoundary(root.right, nodes)
         Return nodes

C++:

  Class Solution {
 Public:
     Vector<int> boundaryOfBinaryTree(TreeNode* root) {
         If (!root) return {};
         Vector<int> res;
         If (root->left || root->right) res.push_back(root->val);
         leftBoundary(root->left, res);
         Leaves(root, res);
         rightBoundary(root->right, res);
         Return res;
     }
     Void leftBoundary(TreeNode* node, vector<int>& res) {
         If (!node || (!node->left && !node->right)) return;
         Res.push_back(node->val);
         If (!node->left) leftBoundary(node->right, res);
         Else leftBoundary(node->left, res);
     }
     Void rightBoundary(TreeNode* node, vector<int>& res) {
         If (!node || (!node->left && !node->right)) return;
         If (!node->right) rightBoundary(node->left, res);
         Else rightBoundary(node->right, res);
         Res.push_back(node->val);
     }
     Void leaves(TreeNode* node, vector<int>& res) {
         If (!node) return;
         If (!node->left && !node->right) {
             Res.push_back(node->val);
         }
         Leaves(node->left, res);
         Leaves(node->right, res);
     }
 };

C++:

  Class Solution {
 Public:
     Vector<int> boundaryOfBinaryTree(TreeNode* root) {
         If (!root) return {};
         Vector<int> res{root->val};
         Helper(root->left, true, false, res);
         Helper(root->right, false, true, res);
         Return res;
     }
     Void helper(TreeNode* node, bool leftbd, bool rightbd, vector<int>& res) {
         If (!node) return;
         If (!node->left && !node->right) {
             Res.push_back(node->val);
             Return;
         }
         If (leftbd) res.push_back(node->val);
         Helper(node->left, leftbd && node->left, rightbd && !node->right, res);
         Helper(node->right, leftbd && !node->left, rightbd && node->right, res);
         If (rightbd) res.push_back(node->val);
     }
 };

C++:

  Class Solution {
 Public:
     Vector<int> boundaryOfBinaryTree(TreeNode* root) {
         If (!root) return {};
         Vector<int> res, right;
         TreeNode *l = root->left, *r = root->right, *p = root;
         If (root->left || root->right) res.push_back(root->val);
         While (l && (l->left || l->right)) {
             Res.push_back(l->val);
             If (l->left) l = l->left;
             Else l = l->right;
         }
         Stack<TreeNode*> st;
         While (p || !st.empty()) {
             If (p) {
                 St.push(p);
                 If (!p->left && !p->right) res.push_back(p->val);
                 p = p->left;
             } else {
                 p = st.top(); st.pop();
                 p = p->right;
             }
         }
         While (r && (r->left || r->right)) {
             Right.push_back(r->val);
             If (r->right) r = r->right;
             Else r = r->left;
         }
         Res.insert(res.end(), right.rbegin(), right.rend());
         Return res;
     }
 };
