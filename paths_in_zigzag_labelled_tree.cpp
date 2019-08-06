Normally Ordered Binary Tree:
             1
           /   \
         2       3
       /  \     /  \
     4     5   6     7
   / |    /|   |\    | \
 8   9  10 11 12 13  14  15

 Zig Zag Binary Tree:
             1
           /   \
         3       2  <- 3+2-3 = 2/2 = 1
       /  \     /  \
     4     5   6     7   <- 7+4-4 = 7/2 = 3
   / |    /|   |\    | \
 15 14  13 12 11 10  9  8   <- 15+8-14 = 9/2 = 4
// inversion formula: (max number of current level + min number of current level) - current number
// For example to find the inversion of 14: 15 + 8 - 14 = 9
// From here you just divide 9 by 2 to find the parent 4

// Thought 3) You have to run the inversion formula at every level because at every level the row is inverted relative to the previous row




/*
Approach:
    1. Calculate current depth of the label
    2. Calculate offset (for each depth, values lie from 2^d -> 2^(d+1) -1
    3. Find the real parent based on offset
    4. Repeat until we reach 1

e.g. parent of 14 is 4

    1. depth = 3, values in this depth lie from 8 to 15 (since it is a complete binary tree)
    2. offset = 15 - 14 = 1
    3. real parent of 14 = parent of ( 8 + offset ) = parent (9) = 9/2 = 4
*/

class Solution {
public:
    vector<int> pathInZigZagTree(int label, int level = 0) {
      	while (1 << level <= label) ++level;
      	vector<int> res(level);
      	int offset;
      	for(; label >= 1; label /= 2, --level) {
        	res[level - 1] = label;
        	offset = (1 << level) - 1 - label;
        	label = offset + (1 << (level - 1));
      	}
      	return res;
    }
};







class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> result;
        result.push_back(label); //taking bottom up approach, so the label itself must be included 
        int height=log2(label); //height of label from root
        
        while(height!=0){
            int left=pow(2,height-1); // rank of left limit of the previous level 
            int right=pow(2,height)-1;// rank of right limit of the previous level
            label=left+(right-label/2);// The previous level is sorted in different order than current one.
                                       //So the new label is adjusted accordingly
            result.push_back(label);  //newly found label is appened to result
            height--;
        }
        
        reverse(result.begin(),result.end()); //required top to down, so the array is reversed. 
        return result;
    }
};