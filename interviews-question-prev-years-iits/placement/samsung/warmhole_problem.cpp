// new try
#include <iostream>
using namespace std;

struct warmhole{
    int sx, sy, dx, dy;
    int cost;
    void input(){
        int x1, y1, x2, y2, c;
        cin>>x1>>y1>>x2>>y2>>c;
        sx = x1, sy = y1;
        dx = x2, dy = y2;
        cost = c;
    }
};
warmhole wh[10];
int inf = 1e7;
int dist[181][181];
bool visit[181][181];

int check_entry(int wn, int x, int y){
    for(int i=0; i<wn; i++){
        if(wh[i].sx == x && wh[i].sy == y){
            return i;
        }
    }
    return -1;
}
int check_exit(int wn, int x, int y){
    for(int i=0; i<wn; i++){
        if(wh[i].dx == x && wh[i].dy == y){
            return i;
        }
    }
    return -1;
}
void find_min_dist(int &x, int &y){
    int min_ = inf;
    for(int i=0; i<181; i++){
        for(int j=0; j<181; j++){
            if(!visit[i][j] && dist[i][j] < min_){
                min_ = dist[i][j];
                x = i, y = j;
            }
        }
    }
    // cout<<min_<<" ";
    if(min_ == inf){
        x = -1, y = -1;
    }
}
int main() {
    int sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy;
    int wn;
    cin>>wn;
    
    for(int i=0; i<wn; i++){
        wh[i].input();
    }
    
    for(int i=0; i<wn; i++){
        cout<<wh[i].sx<<" "<<wh[i].sy<<" ";
        cout<<wh[i].dx<<" "<<wh[i].dy<<" ";
        cout<<wh[i].cost<<endl;
    }
    
    for(int i=0; i<181; i++){
        for(int j=0; j<181; j++){
            dist[i][j] = inf;
            visit[i][j] = false;
        }
    }
    dist[0][0] = 0;
    // find min dist node, which is not visited yet
    // increase its cost by 1
    // check if it is entry or exit point for some warmhole
    // if yes, update cost of that entry or exit point accordingly
    
    for(int i=0; i<181*181; i++){
        // 1. find minimum dist
        int x, y;
        find_min_dist(x, y);
        if(x == -1 && y == -1){
            cout<<"cann't reach at destination";
            return 0;
        }
        visit[x][y] = true;
        // cout<<x<<" "<<y<<endl;
        // 2. update dist of its neighbour
        if(x-1>=0 && visit[x-1][y] == false){
            if(dist[x-1][y] > dist[x][y] + 1){
                dist[x-1][y] = dist[x][y] + 1;
            }
        }
        if(x+1 < 181 && visit[x+1][y] == false){
            if(dist[x+1][y] > dist[x][y] + 1){
                dist[x+1][y] = dist[x][y] + 1;
            }
        }
        if(y-1>=0 && visit[x][y-1] == false){
            if(dist[x][y-1] > dist[x][y] + 1){
                dist[x][y-1] = dist[x][y] + 1;
            }
        }
        if(y+1 < 181 && visit[x][y+1] == false){
            if(dist[x][y+1] > dist[x][y] + 1){
                dist[x][y+1] = dist[x][y] + 1;
            }
        }
        // 3. check for warmhole entry and exit point
        int xx, yy;
        int entry = check_entry(wn, x, y);
        if(entry != -1){
            xx = wh[entry].dx;
            yy = wh[entry].dy;
            if(dist[xx][yy] > dist[x][y] + wh[entry].cost){
                dist[xx][yy] = dist[x][y] + wh[entry].cost;
            }
        }
        int exit_ = check_exit(wn, x, y);
        if(exit_ != -1){
            xx = wh[exit_].sx;
            yy = wh[exit_].sy;
            if(dist[xx][yy] > dist[x][y] + wh[exit_].cost){
                dist[xx][yy] = dist[x][y] + wh[exit_].cost;
            }
        }
        
    }
    cout<<dist[dx][dy]<<endl;
    return 0;
}



// old one
#include<iostream>
using namespace std;
#define i_max 214748364
int nw,sx,sy,dx,dy;//Source and destination co-ordinates
int dist[1001][1001];
bool set[1001][1001];

/*
1. Find min_dist coordinate, which is not visited yet
2. Explore its neighbour (and increase their dist by 1)
3. Check if any warmhole present here(update dist of that coordinate)
4. Repeat till we visit each cell
*/

class Wormhole{
public:
    int x1,y1,x2,y2,cost;

    void get(){
        cin >> x1 >> y1 >> x2 >> y2 >> cost;
    }
};

Wormhole A[10];
int row_mov[] = {-1,0,0,1};
int col_mov[] = {0,-1,1,0};


void initializeArrays(int m,int n){
    //Filling array with 1s
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            dist[i][j] = i_max;
            set[i][j] = false;
        }
    }
}

void setMinRowCol(int &row,int &col){
    int min_dist=i_max,min_i=-1,min_j=-1;

    for(int i=0;i<=180;i++){
        for(int j=0;j<=180;j++){
            if(!set[i][j] && dist[i][j]<min_dist){
                min_dist = dist[i][j];
                min_i = i;
                min_j = j;
            }
        }
    }
    row = min_i;
    col = min_j;
}

int wormentry(int i,int j){
    for(int k=0; k<nw; k++){
        if(A[k].x1==i && A[k].y1==j)
            return k;
    }
    return -1;
}

int wormexit(int i,int j){
    for(int k=0; k<nw; k++){
        if(A[k].x2==i && A[k].y2==j)
            return k;
    }
    return -1;
}

bool isValid(int i,int j){
    if(i<0 || j<0 || i>180 || j>180){
        return false;
    }
    return true;
}


int findMinCost(){
    initializeArrays(181,181);
    //Run dijkstra
    dist[sx][sy] = 0;//Distance from source to source is 0
    //set[sx][sy] = true;//We have reached source

    for(int i=1;i<=(181)*(181);i++){
        //cout<<i;
        int row=-1,col=-1;
        setMinRowCol(row,col);//Find min row,col that are unset and proceed with min_dist path

        if(row == -1 && col == -1){//If not found then break
            break;
        }

        //Set the current row,col
        set[row][col] = true;

        //Move in all 4 directions
        for(int j=0;j<4;j++){
            int x = row + row_mov[j];
            int y = col + col_mov[j];

            if(isValid(x,y) && !set[x][y] && dist[x][y] > dist[row][col]+1){  
                dist[x][y] = dist[row][col] + 1;
            }
        }

        //If worm entry is at row,col ,i.e., row = x1 & col = y1 then exit is at x2,y2
        int w_entry = wormentry(row,col);
        if(w_entry != -1){
            int x = A[w_entry].x2;
            int y = A[w_entry].y2;

            //If cost of wormhole is minimum go through the wormhole
            if(!set[x][y] && dist[x][y] > dist[row][col] + A[w_entry].cost){
                dist[x][y] = dist[row][col]+A[w_entry].cost;
            }
        }
        
        // If worm exit is at row,col ,i.e., row = x2 & col = y2 then entry is at x1,y1
        int w_exit = wormexit(row,col);
        if(w_exit!=-1){
            int x = A[w_exit].x1;
            int y = A[w_exit].y1;

            //If cost of wormhole is minimum go through the wormhole
            if(!set[x][y] && dist[x][y]>dist[row][col]+A[w_exit].cost){
                dist[x][y] = dist[row][col]+A[w_exit].cost;
            }
        }
    }

    //If we've reached destination, return the cost
    return dist[dx][dy];
}

int main(){
    cin >> sx >> sy >> dx >> dy;//Scanning source and destination
    cin >> nw;//No of wormholes

    //Scanning wormholes info
    for(int i=0; i<nw; i++){
        A[i].get();
    }
    cout << findMinCost();

    return 0;
}.