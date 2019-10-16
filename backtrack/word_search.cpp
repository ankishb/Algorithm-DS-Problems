// this one runs at 20ms but fails for 2 cases
class Solution {
public:
    bool helper(vector<vector<char>> board, string word, int n, int m, int len, int i, int j, int ilen){
        if(ilen >= len) return true;
        if(i<0 || j<0 || i>=n || j>=m || board[i][j] != word[ilen]) return false;
        board[i][j] = '#';
        
        bool left  = helper(board, word, n, m, len, i, j-1, ilen+1);
        bool right = helper(board, word, n, m, len, i, j+1, ilen+1);
        bool top   = helper(board, word, n, m, len, i-1, j, ilen+1);
        bool down  = helper(board, word, n, m, len, i+1, j, ilen+1);
        return (left||right||top||down);
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), len = word.length();
        if(len == 0 || n == 0) return false;
        int m = board[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]){
                    bool check = helper(board, word, n, m, len, i, j, 0);
                    if(check == true) return true;
                }
            }
        }
        return false;
    }
};



// this one runs at 270ms, but pass every test cases
/*
I believe there is a tighter bound. I conclude the runtime is O(n^2 * 4 * 3^(k-1)) = O(n^2 * 3^k).
Explanation: We start the word search over all n^2 nodes. For the first letter of the word search we can move in 4 directions but for every later one there are only three options (you can't move back onto yourself).
*/
class Solution {
public:
    bool helper(vector<vector<char>> &board, string word, int n, int m, int len, int i, int j, int ilen){
        if(ilen >= len) return true;
        if(i<0 || j<0 || i>=n || j>=m || board[i][j] != word[ilen]) return false;
        char ch = board[i][j];
        board[i][j] = '#';
        
        bool left  = helper(board, word, n, m, len, i, j-1, ilen+1);
        bool right = helper(board, word, n, m, len, i, j+1, ilen+1);
        bool top   = helper(board, word, n, m, len, i-1, j, ilen+1);
        bool down  = helper(board, word, n, m, len, i+1, j, ilen+1);
        if(left||right||top||down) return true;
        board[i][j] = ch;
        return false;
        
    }
    bool optimized(vector<vector<char>> &board, string word, int n, int m, int len, int i, int j, int ilen){
        if(ilen >= len) return true;
        if(board[i][j] != word[ilen]) return false;
        char ch = board[i][j];
        board[i][j] = '#';
        
        bool ans = false;
        if(!ans && j-1 >=0) ans = helper(board, word, n, m, len, i, j-1, ilen+1);
        if(!ans && j+1 < m) ans = helper(board, word, n, m, len, i, j+1, ilen+1);
        if(!ans && i-1 >=0) ans = helper(board, word, n, m, len, i-1, j, ilen+1);
        if(!ans && i+1 < n) ans = helper(board, word, n, m, len, i+1, j, ilen+1);
        board[i][j] = ch;
        return ans;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), len = word.length();
        if(len == 0 || n == 0) return false;
        int m = board[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]){
                    if(helper(board, word, n, m, len, i, j, 0)) return true;
                    // if(optimized(board, word, n, m, len, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};