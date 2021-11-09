#include<bits/stdc++.h>
using namespace std;
string scs(string str1, string str2) {
        int m=str1.size(),n=str2.size();
        int t[m+1][n+1];
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0) t[i][j]=0;
            }
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(str1[i-1]==str2[j-1]) t[i][j]=1+t[i-1][j-1];
                else t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        string ans="";
        int i=m,j=n;
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                ans=str1[i-1]+ans;
                i--;
                j--;
            }
            else if(t[i-1][j]>t[i][j-1])
            {
                ans=str1[i-1]+ans;
                i--;
            }
            else
            {
                ans=str2[j-1]+ans;
                j--;
            }
        }
        while(i>0)
        {
            ans=str1[i-1]+ans;
            i--;
        }
        while(j>0)
        {
            ans=str2[j-1]+ans;
            j--;
        }
        return ans;
    }
int main()
{
    string x,y;
    cin>>x>>y;
    cout<<scs(x,y)<<endl;
}