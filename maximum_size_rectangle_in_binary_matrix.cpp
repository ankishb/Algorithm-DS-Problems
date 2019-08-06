
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int maxArea(int M[MAX][MAX],int n,int m);
int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<maxArea(M,n,m)<<endl;
    }
}

int maxArea(int M[MAX][MAX],int n,int m){
    // auto int maxHist = max_Hist(int final[])();
    // // https://www.geeksforgeeks.org/largest-rectangle-under-histogram/ 
    // int max_Hist(int final[]) 
    // { 
    //     int C = m;
    //     stack<int> result; 
    //     int top_val; 
    //     int max_area = 0, area = 0, i = 0; 
    //     while (i < C) 
    //     { 
    //         if (result.empty() || final[result.top()] <= final[i]) 
    //             result.push(i++); 
    //         else{ 
    //             top_val = final[result.top()]; 
    //             result.pop(); 
    //             area = top_val * i; 
    //             if (!result.empty()) 
    //                 area = top_val * (i - result.top() - 1 ); 
    //             max_area = max(area, max_area); 
    //         } 
    //     } 
      
    //     while (!result.empty()){ 
    //         top_val = final[result.top()]; 
    //         result.pop(); 
    //         area = top_val * i; 
    //         if (!result.empty()) 
    //             area = top_val * (i - result.top() - 1 ); 
      
    //         max_area = max(area, max_area); 
    //     } 
    //     return max_area; 
    // }

    int final[n][m], cur_area, max_area = 0;
    memset(final, 0, sizeof(final));
    for(int ii=0; ii<n; ii++){
        for(int j=0; j<m; j++){
            if(ii == 0){
                final[ii][j] = M[ii][j];
            }
            else{
                final[ii][j] = 1+final[ii-1][j];
            }
        }


        int C = m;
        stack<int> result; 
        int top_val; 
        int max_area = 0, area = 0, i = 0; 
        while (i < C) 
        { 
            if (result.empty() || final[result.top()] <= final[i]) 
                result.push(i++); 
            else{ 
                top_val = final[result.top()]; 
                result.pop(); 
                area = top_val * i; 
                if (!result.empty()) 
                    area = top_val * (i - result.top() - 1 ); 
                max_area = max(area, max_area); 
            } 
        } 
      
        while (!result.empty()){ 
            top_val = final[result.top()]; 
            result.pop(); 
            area = top_val * i; 
            if (!result.empty()) 
                area = top_val * (i - result.top() - 1 ); 
      
            max_area = max(area, max_area); 
        } 

        // cur_area = maxHist(final[i]);
        max_area_ = max(max_area, max_area_);
    }
    cout<<max_area_<<endl;
}









#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int maxArea(int M[MAX][MAX],int n,int m);

void hist(int a[MAX], int m, int &l, int &r, int &h)
{
    vector<int> nse_l(m, 0);
    vector<int> nse_r(m, 0);
    
    stack<int> s;
    for(int i=0;i<m;i++)
    {
        while(!s.empty() && a[i]<a[s.top()])
        {
            nse_r[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    
    while(!s.empty())
    {
        nse_r[s.top()] = m;
        s.pop();
    }
    
    for(int i=m-1;i>=0;i--)
    {
        while(!s.empty() && a[i]<a[s.top()])
        {
            nse_l[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    
    while(!s.empty())
    {
        nse_l[s.top()] = -1;
        s.pop();
    }
    
    int area=0;
    for(int i=0;i<m;i++)
    {
        int pos1 = nse_l[i], pos2 = nse_r[i];
        int temp = a[i]*(pos2-pos1-1);
        
        if(temp>area)
        {
            area = temp;
            l = pos1+1; r = pos2-1;
            h = a[i];
        }
    }
    return;
}

int maxArea(int M[MAX][MAX],int n,int m)
{
    //Your code here
    int rowsum[m];
    int maxa = 0;
    int maxl=0, maxr=0, maxup = 0, maxdown=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0)
            rowsum[j] = M[i][j];
            else if(i>0)
            {
                if(M[i][j] == 1)
                rowsum[j] += M[i][j];
                else rowsum[j] = 0;
            }
        }
        
        int area=0, l=0, r=0, h=0;
        hist(rowsum, m, l, r, h);
        
        area = h*(r-l+1);
        if(area>maxa)
        {
            maxa = area;
            maxl = l; maxr =r;
            maxup = i-h+1; maxdown = i;
        }
    }
    
    for(int i=maxup;i<=maxdown;i++)
    {
        for(int j=maxl;j<=maxr;j++)
        cout<<M[i][j]<<" ";
        cout<<endl;
    }
    
    return maxa;
}


int main()
{
    int T;
    cin>>T;
int M[MAX][MAX];
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<maxArea(M,n,m)<<endl;
    }
}

