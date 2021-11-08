#include<bits/stdc++.h>
using namespace std;
pair<int,int> minop(string a,string b,int n,int m)
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
            if(a[i-1]==b[j-1]) t[i][j]=1+t[i-1][j-1];
            else t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    return { n-t[n][m] , m-t[n][m] };
}

int main()
{
    string a,b;
    cin>>a>>b;
    pair<int,int> ans=minop(a,b,a.size(),b.size());
    cout<<"insertion operation: "<<ans.first<<endl;
    cout<<"deletion operation: "<<ans.second<<endl;
}