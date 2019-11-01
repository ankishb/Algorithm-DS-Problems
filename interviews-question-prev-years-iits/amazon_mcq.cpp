#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     char ch[] = "ankish";
//     cout<<strlen(ch)<<endl; // 6
//     char chh[] = "ankish\0";
//     cout<<strlen(chh)<<endl; // 6
// }

int main()
{
/*


2 
*/
    char ch[2] = {char() };
    int i=0;
    ch[i++] = ++i;
    cout<<ch[0]<<" "<<ch[1]<<endl;
    cout<<ch<<endl;
    cout<<i<<endl;
    return 0;
}


// void show(){
//     auto a = 1;
//     register int b = 2;
//     static int c;
//     a++;
//     b++;
//     c++;
//     cout<<a<<" "<<b<<" "<<c<<endl;
// }

// int main()
// {
//     show();
//     show();
// /*
// 2 3 1
// 2 3 2
// */
//     return 0;
// }

// int main()
// {
//     char ch[] = "\0";
//     printf("%c\n", ch);
//     if(printf("%c\n", ch)){
//         printf("gere\n"); // this will work
//     }
//     else{
//         printf("else here\n");
//     }
//     return 0;
// }

// int main()
// {
//     char ch[10] = "rectangle";
//     char chh[] = {'a','e','i','o','u'};
//     // char chhh[] = "aeiou";
//     int i;
//     cout<<strlen(ch)<<endl;
//     cout<<strlen(chh)<<endl;
//     // cout<<strlen(chhh)<<endl;
    
//     for(i=0; i<=7; i++){
//         printf("%c",ch[i]);
//     }
//     // ch++;

// /*
// 9
// 6
// rectangl
// */
//     return 0;
// }

// int main()
// {
//     int s[][2] = {{2,3}, {4,5}};
//     printf("%d \n", s);
//     printf("%d \n", &s);
//     printf("%p \n", s);
//     return 0;
    
// /*
// 2086704032 
// 2086704032 
// 0x7ffc7c6093a0 
// */
// }

// int main()
// {
//     printf(3+"Ankish \n"); // ish
//     int a = -1, b = 2;
//     int aa = a, bb = b;
//     cout<<(aa++)<<" "<<(bb++)<<endl;
//     cout<<aa<<" "<<bb<<endl;
    
//     int c = (a++) || (b++);
//     cout<<c<<endl;

// /*
// ish 
// -1 2
// 0 3
// 1
// */
//     return 0;
// }