
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