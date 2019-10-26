
/* Rule: (ab) mod p = ( (a mod p) (b mod p) ) mod p  */

#include <iostream>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--){
        int x, y, p;
        cin>>x>>y>>p;
        
        int res = 1;
        x = x%p;
        while(y > 0){
            if(y%2 == 1){
                res = res*x;
                res = res%p;
                y--;
            }
            else{
                x = x*x;
                x = x%p;
                y = y/2;
            }
        }
        cout<<res<<"-----------\n";
    }
    return 0;
}