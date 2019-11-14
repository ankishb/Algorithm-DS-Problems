
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    int k;
    cin>>k;
    double  mult = pow(10, k);
    while(test--){
        double n;
        cin>>n;
        double ans = n*mult*10;
        long ans2 = ans;
        if(ans2 % 10 >= 5) ans2 += 10;
        ans2 = ans2 / 10;
        ans = (ans2*1.0)/mult;
        cout<<ans<<endl;
        printf("%lf \t %lf \t %.2lf \n", n, ans, n);
    }
    return 0;
}