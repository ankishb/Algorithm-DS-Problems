
// new one
int is_valid(int A[9][9]){
    int row[9][10] = {0};
    int col[9][10] = {0};
    int block[9][10] = {0};
    int val;
    for(int r=0; r<9; r++){
        for(int c=0; c<9; c++){
            if(A[r][c] == 0) continue;
            val = A[r][c];
            row[r][val]++;
            col[c][val]++;
            block[(r/3)*3 + c/3][val]++;
        }
    }
    for(int i=0; i<9; i++){
        for(int j=0; j<10; j++){
            // cout<<row[i][j]<<" "<<col[i][j]<<" "<<block[i][j]<<endl;
            if(row[i][j] > 1) return 0;
            if(col[i][j] > 1) return 0;
            if(block[i][j] > 1) return 0;
        }
    }
    return 1;
}


// old try
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