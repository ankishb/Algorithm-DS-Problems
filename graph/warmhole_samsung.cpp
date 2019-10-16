#include<iostream>
using namespace std;
#define i_max 214748364
int nw,sx,sy,dx,dy;//Source and destination co-ordinates
int dist[1001][1001];
bool set[1001][1001];

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