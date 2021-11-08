#include<bits/stdc++.h>
using namespace std;
string lcs(string x,string y,int n,int m) //top down tabulation
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
    string ans="";
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            ans= x[i-1]+ans;
            i--;
            j--;
        }
        else if(t[i-1][j]>t[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    return ans;
}
int main()
{
    string x="abcdaf",y="acdbf";
    //vector<vector<int>> t(x.size()+1,vector<int>(y.size()+1,-1));
    //cout<<lcs(x,y,x.size(),y.size(),t)<<endl;
    cout<<lcs(x,y,x.size(),y.size())<<endl;
}