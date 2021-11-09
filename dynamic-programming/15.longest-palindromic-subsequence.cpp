#include<bits/stdc++.h>
using namespace std;

string lps(string s)
{
    int n=s.size();
    string t=s;
    reverse(t.begin(),t.end());
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0) dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i=n,j=n;
    string ans="";
    while(i>0 && j>0)
    {
        if(s[i-1]==t[j-1])
        {
            ans=s[i-1]+ans;
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
    }
    return ans;
}
int main()
{
    string s;
    cin>>s;
    cout<<lps(s)<<endl;
}