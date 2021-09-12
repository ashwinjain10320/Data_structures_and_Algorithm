#include<bits/stdc++.h>
using namespace std;
int minsubsetsum(int a[],int n)
{
    int range = accumulate(a,a+n,0);
    bool dp[n+1][range+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=range;j++)
        {
            if(i==0) dp[i][j] = false;
            if(j==0) dp[i][j] = true;
        }
    }   
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=range;j++)
        {
            if(a[i-1]<=j)
            {
                dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int res=INT_MAX;
    for(int i=0;i<=(range/2);i++)
    {
        if(dp[n][i]) res=min(res,range-(2*i));
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<minsubsetsum(a,n)<<endl;
    return 0;
}