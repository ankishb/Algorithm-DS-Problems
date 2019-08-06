// When X wins, O cannot move anymore, so turns must be 1. When O wins, X cannot move anymore, so turns must be 0. Finally, when we return, turns must be either 0 or 1, and X and O cannot win at same time.
class Solution {
public:
    int n = 3;
    int leftDiag = 0;
    int rightDiag = 0;
    int rowCounter[3] = {0};
    int colCounter[3] = {0};
    int totalMoves = 0;
    bool xWins = false;
    bool oWins = false;

    bool validTicTacToe(vector<string>& board) {
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[i][j] == ' ') continue;
                if(board[i][j] == 'X'){
                    totalMoves++;
                    if(i == j) leftDiag++;
                    if(i == (3-j-1)) rightDiag++;
                    rowCounter[i]++;
                    colCounter[j]++;
                }
                else{
                    totalMoves--;
                    if(i == j) leftDiag--;
                    if(i == (3-j-1)) rightDiag--;
                    rowCounter[i]--;
                    colCounter[j]--;
                }
            }
        }
        for(int i=0; i<3; i++){
            if(rowCounter[i] == 3) xWins = true;
            if(rowCounter[i] == -3) oWins = true;
            if(colCounter[i] == 3) xWins = true;
            if(colCounter[i] == -3) oWins = true;
        }
        if(leftDiag == 3 || rightDiag == 3) xWins = true;
        if(leftDiag == -3 || rightDiag == -3) oWins = true;

        // if x wins then moves should be 1, ans for o to win, it should be 0
        if(xWins && totalMoves != 1) return false;
        if(oWins && totalMoves != 0) return false;
        
        // if both wins, that is not possible either
        if(xWins && oWins) return false;
        
        // And turns should be 0 or 1
        return (totalMoves == 0 || totalMoves == 1);
    }
};