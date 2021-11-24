#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];
bool ispalin(string s,int i,int j)
{
    while(i<=j)
    {
        if(s[i]==s[j]) 
        {
            i++;
            j--;
        }
        else return false;
    }
    return true;
}
int palinpart1(string s,int i,int j)
{
    if(i>=j || ispalin(s,i,j)) return 0;
    int ans=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int ta= 1+palinpart1(s,i,k)+palinpart1(s,k+1,j);
        ans=min(ans,ta);
    }
    return ans;
}
int palinpart(string s,int i,int j)
{
    if(i>=j || ispalin(s,i,j)) return 0;
    if(t[i][j]!=-1) return t[i][j];
    int ans=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int ta= 1+palinpart(s,i,k)+palinpart(s,k+1,j);
        ans=min(ans,ta);
    }
    return t[i][j]=ans;
}
int main()
{
    memset(t,-1,sizeof(t));
    string s;
    cin>>s;
    cout<<palinpart(s,0,s.size()-1);
    return 0;
}