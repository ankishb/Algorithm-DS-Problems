// Approach:
// 1. check ist column, if any of row has zeros at ist columnm flip the entire row
// 2. Now we consider column by column, if number of zeros in column are greater than number of ones, we toggle.

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        for(int i=0; i<row; i++){
        	if(A[i][0] == 0){
        		// we flip the entire row
        		for(int j=0; j<col; j++){
        			A[i][j] = !(A[i][j]);
        		}
        	}
        }

        int zeros;
        // now we iterate column by column
        for(int j=1; j<col; j++){
        	zeros = 0;
        	for(int i=0; i<row; i++){
        		if(A[i][j] == 0) zeros++;
        	}
        	if(zeros > (row-zeros)){
        		// flip the entire column
        		for(int i=0; i<row; i++){
        			A[i][j] = !(A[i][j]);
        		}
        	}
        }

        // count the number
        int ans = 0;
        for(int i=0; i<row; i++){
        	for(int j=0; j<col; j++){
                cout<<A[i][j];
        		if(A[i][j] == 1) ans += pow(2, (col-j-1));
        	}
            cout<<endl;
        }
        return ans;
    }
};



// optimized 8ms -> 4ms
// Approach:
// 1. check ist column, if any of row has zeros at ist columnm flip the entire row
// 2. Now we consider column by column, if number of zeros in column are greater than number of ones, we toggle.

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        int zeros = 0;
        int ans = 0;
        for(int i=0; i<row; i++){
        	if(A[i][0] == 0){
                zeros++;
        		// we flip the entire row
        		for(int j=0; j<col; j++){
        			A[i][j] = 1 - (A[i][j]);
        		}
        	}
        }
        ans += pow(2, col-1)*row;        
        
        // now we iterate column by column
        for(int j=1; j<col; j++){
        	zeros = 0;
        	for(int i=0; i<row; i++){
        		if(A[i][j] == 0) zeros++;
        	}
        	if(zeros > (row-zeros)){
        		// flip the entire column
                ans += pow(2, col-j-1)*zeros;
        	}
            else{
                ans += pow(2, col-j-1)*((row-zeros));
            }
        }

        return ans;
    }
};










// Basic Ideas:
//   Make sure the first column is all 1, by changing rows
//   The check column by column. This time we check columns.
//     Our target is to have maximum 1s
//     If current column has equal 0s and 1s, should I swap?
//     It doesn't matter
// Complexity: Time O(n*m), Space O(1)
import "math"
func matrixScore(A [][]int) int {
    row_count, col_count := len(A), len(A[0])
    res, power := 0, int(math.Pow(2, float64(col_count-1)))
    // Change first column
    res, power = res+row_count*power, power/2
    for i:=0; i<row_count; i++{
        if A[i][0] == 0 {
            for j:=0; j<col_count; j++ {
                A[i][j] = 1-A[i][j]
            }
        }
    }
    // check other columns
    for j:=1; j<col_count; j++ {
        count := 0
        for i:=0; i<row_count; i++ {
            if A[i][j] == 1 { count++ }
        }
        if count < row_count-count { count = row_count-count }
        res, power = res+count*power, power/2
    }
    return res
}