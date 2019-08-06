370. Range Addition
October 23, 2017
Assume you have an array of length n initialized with all 0's and are given k update operations.
Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
Return the modified array after all k operations were executed.
Example:

Given:

    length = 5,
    updates = [
        [1,  3,  2],
        [2,  4,  3],
        [0,  2, -2]
    ]

Output:

    [-2, 0, 3, 5, 3]

Explanation:

Initial state:
[ 0, 0, 0, 0, 0 ]

After applying operation [1, 3, 2]:
[ 0, 2, 2, 2, 0 ]

After applying operation [2, 4, 3]:
[ 0, 2, 5, 5, 3 ]

After applying operation [0, 2, -2]:
[-2, 0, 3, 5, 3 ]


Thought process:
The brute force solution has a time complexity of O(kn), where length = n. How can we improve this? We are running a lot of duplicate iterations over the array. Multiple updates may have covered the same range of the array. Instead of iterating through the range for each update, we can save the work by update the array only once.
For each update, increment the value on array[start] but decrement it on array[end + 1]. After all updates, use a sum function to get the result array: modified[i] = array[i] + modified[i - 1]. This ensures that each update's change gets applied to every element within the update range.

    Every index between start and end is incremented by value.
    Every index after end is not changed.


Solution:

 1
 2
 3
 4
 5
 6
 7
 8
 9
10
11
12
13
14
15
16
17
18
19
20
21
22

	

class Solution {
    public int[] getModifiedArray(int length, int[][] updates) {
        int[] array = new int[length];
        if (length == 0) {
            return array;
        }
        
        for (int[] update : updates) {
            array[update[0]] += update[2];
            if (update[1] < length - 1) {
                array[update[1] + 1] -= update[2];
            }
        }

        int[] result = new int[length];
        result[0] = array[0];
        for (int i = 1; i < length; i++) {
            result[i] = result[i - 1] + array[i];
        }
        return result;
    }
}


Time complexity: O(k + n)