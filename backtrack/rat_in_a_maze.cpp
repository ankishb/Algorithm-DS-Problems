
class custom_q{
public:
    int x, y;
    string path;
    custom_q(int x_, int y_, string s_):
    x(x_), y(y_), path(s_){}
};

void dfs(int m[MAX][MAX], custom_q front, int n, vector<string> &ans){
    int x = front.x;
    int y = front.y;
    if(x == n-1 && y == n-1){
        ans.push_back(front.path);
    }
    int value = m[x][y]; 
    m[x][y] = 0;
    
    if(y-1 >= 0 && m[x][y-1] == 1){
        dfs(m, custom_q(x, y-1, front.path+"L"), n, ans);
    }
    if(y+1 < n && m[x][y+1] == 1){
        dfs(m, custom_q(x, y+1, front.path+"R"), n, ans);
    }
    if(x-1 >= 0 && m[x-1][y] == 1){
        dfs(m, custom_q(x-1, y, front.path+"U"), n, ans);
    }
    if(x+1 < n && m[x+1][y] == 1){
        dfs(m, custom_q(x+1, y, front.path+"D"), n, ans);
    }
    m[x][y] = value;
}
vector<string> printPath(int m[MAX][MAX], int n){
    vector<string> ans;
    dfs(m, custom_q(0,0,""), n, ans);
    sort(ans.begin(), ans.end());
    return ans;
}