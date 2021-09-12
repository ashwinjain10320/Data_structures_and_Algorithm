#include<bits/stdc++.h>
using namespace std;

int sol(int a[],int n,int diff)
{
    int sum = accumulate(a,a+n,diff)/2;
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0) dp[i][j] = 0;
            if(j==0) dp[i][j] = 1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(a[i-1]<=j)
            {
                dp[i][j] = dp[i-1][j-a[i-1]] + dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
    
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
    cout<<sol(a,n,1)<<endl;
    return 0;
}