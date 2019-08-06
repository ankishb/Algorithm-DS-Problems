class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& A) {
        set<int> s;
        for(int i=0; i<9; i++){
            s.clear();
            for(int j=0; j<9; j++){
                if(A[i][j] == '.') continue;
                if(s.find(A[i][j] - '0') != s.end()) return false;
                s.insert(A[i][j] - '0');
            }
        }
        for(int i=0; i<9; i++){
            s.clear();
            for(int j=0; j<9; j++){
                if(A[j][i] == '.') continue;
                if(s.find(A[j][i] - '0') != s.end()) return false;
                s.insert(A[j][i] - '0');
            }
        }
        
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                s.clear();
                for(int l=3*i; l<3*(i+1); l++){
                    for(int m=3*j; m<3*(j+1); m++){
                        if(A[l][m] == '.') continue;
                        if(s.find(A[l][m] - '0') != s.end()) return false;
                        s.insert(A[l][m] - '0');   
                    }
                }
            }
        }
        return true;
    }
};