#include<bits/stdc++.h>
using namespace std;
int lcs(string x,string y,int n,int m,vector<vector<int>>& t) //bottom up- recursive with memoization
{
    if(n==0 || m==0) return t[n][m]=0;
    if(t[n][m]!=-1) return t[n][m];
    if(x[n-1]==y[m-1])
    {
        return t[n][m]=1+lcs(x,y,n-1,m-1,t);
    }
    else
    {
        return t[n][m]=max(lcs(x,y,n,m-1,t),lcs(x,y,n-1,m,t));
    }
}
int lcs1(string x,string y,int n,int m) //top down tabulation
{
    int t[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0) t[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x[i-1]==y[j-1])
            {
                t[i][j]=1+t[i-1][j-1];
            }
            else
            {
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return t[n][m];
}
int main()
{
    string x="abcdaf",y="acdbf";
    //vector<vector<int>> t(x.size()+1,vector<int>(y.size()+1,-1));
    //cout<<lcs(x,y,x.size(),y.size(),t)<<endl;
    cout<<lcs1(x,y,x.size(),y.size())<<endl;
}