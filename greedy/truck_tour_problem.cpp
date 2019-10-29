
int truckTour(vector<vector<int>> petrolpumps) {
    int n = petrolpumps.size();
    for(int i=0; i<n; i++){
        petrolpumps.push_back(petrolpumps[i]);
    }
    int i, j, save = 0, count, petrol, dist;
    for(i=0; i<2*n; i++){
        j = i;
        count = 0;
        save = 0;
        while(j<2*n){
            petrol = (petrolpumps[j][0]+save );
            dist = petrolpumps[j][1];
            save = petrol - dist;
            cout<<save<<" ";
            if(save >= 0){
                j++; count++;
            }
            else break;
            if(count == n) return i;
            if(count > n) break;
        }
        if(count != n) i = j++;
    }
    return i;
}








/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};
*/

// optimal (O(N))
int tour2(petrolPump p[],int n){
    int start = 0, pending = 0, petrol = 0;
    for(int i=0; i<n; i++){
        petrol += p[i].petrol;
        petrol -= p[i].distance;
        if(petrol < 0){
            start = i+1;
            pending += petrol; // collect prev petrol
            petrol = 0;
        }
    }
    return (petrol+pending > 0) ? start : -1;
}

// worst case O(2*N)
int tour(petrolPump p[],int n){
    int i=0, j, petrol, count;
    while(i < n){
        petrol = 0;
        j = i;
        count = 0;
        while(j < n){
            petrol += p[j].petrol;
            petrol -= p[j].distance;
            if(petrol < 0) break;
            j++; count++;
            if(j == n) j = 0;
            if(count == n) return i;
            if(count > n) break;
        }
        i = j+1;
    }
    return -1;
}