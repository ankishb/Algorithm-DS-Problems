#include <bits/stdc++.h>
using namespace std;

void solve1(int n){
    int count;
    if(n==0){ count=0; }
    else{ count = 1; }
    int max_count = INT_MIN;
    
    int last_bit = (n>>1)&1;
    int cur_bit;
    n = n>>1;
    while(n!=0){
        cur_bit = (n>>1)&1;
        n = n >> 1;
        cout<<last_bit<<" "<<cur_bit<<endl;
        if(last_bit==1 && cur_bit==1){
            count++;
        }
        else{
            max_count = max(max_count, count);
            if((n>>1)&1){ count = 1;}
            else{ count = 0; }
        }
        last_bit = cur_bit;
    }
    cout<<max_count<<endl;
}

// correct and accepted solution
void solve2(int n){
    int count=0;
    int max_count = INT_MIN;
    while(n!=0){
        // cout<< n<<" " << (n & 1) <<" \n";
        if(n & 1){
            count++;
        }
        else{
            max_count = max(max_count, count);
            count = 0;
        }
        n = n >> 1;
    }
    max_count = max(max_count, count);
    cout<<max_count<<endl;
}


int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // solve1(n);
    solve2(n);
    return 0;
}







public class Solution {

public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int rem=0,s=0,t=0;


    while(n>0){
        rem=n%2;
        n=n/2;
        if(rem==1)
         {   s++;
           if(s>=t)

            t=s;

        }
        else{

            s=0;
        }   
    }

    System.out.println(t);
}

}