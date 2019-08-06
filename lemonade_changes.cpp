class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives=0, tens=0;
        int n = bills.size();
        if(n==0) return true;
        for(int i=0; i<n; i++){
            if(bills[i] == 5) fives++;
            else if(bills[i] == 10){
                if(fives < 1) return false;
                else{
                    fives--; tens++;
                }
            }
            else{// if(bills[i] == 20){
                if(tens>=1 && fives>=1){
                    tens--; fives--;
                }
                else if(fives >= 3){
                    fives -= 3;
                }
                else return false;
            }
            // cout<<fives<<" "<<tens<<endl;
        }
        return true;
    }
};