int Solution::pow(int x, int n, int d) {
//     // Do not write main() function.
//     // Do not read input, instead use the arguments to the function.
//     // Do not print the output, instead return values as specified
//     // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
// // }

// // int power_function(int x, int n, int d){
    
//     bool neg=true;
//     if(n%2 == 0 && x<0){
//         // its result will be +ve
//         neg = false;
//     }
//     int last_digit = abs(x)%10;
//     if(n==0){
//         return 1%d;
//     }
//     if(last_digit == 0){
//         return 0;
//     }
//     int div;
//     if(last_digit == 1 || last_digit==5 || last_digit==6){
//         div = 1;
//     }
//     else if(last_digit == 4 || last_digit==9){
//         div = 2;
//     }
//     else{
//         div = 4;
//     }

//     int power = n%div;
//     if(power == 0){
//         power = div;
//     }
//     // cout<<"power: "<<power<<endl;
//     int ans = 1;
//     for(int i=0; i<power; i++){
//         ans = ans*last_digit;
//     }
//     if(neg){
//         ans = d-ans;
//     }
//     // int ans = pow(last_digit, power);
//     // cout<<"x^n: "<<ans<<endl;
//     ans = ans%d;
//     return ans;

// }

    if(x==0 && n==0){return 0;}
    if(n==0){return 1;}
    if(n==1){
        if(x<0){return (x+d)%d;}
        return x;
    }
    
    long long temp;
    if(n&1==0){
        temp=pow(x,n/2,d);
        temp=(temp*temp)%d;
    }
    else{
        temp=(x%d*pow(x,n-1,d))%d;
    }
    return (temp+d)%d;
}
