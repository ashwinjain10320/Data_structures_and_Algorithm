#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];
int solve1(int arr[],int i,int j)
{
    if(i>=j) return 0;
    if(t[i][j]!=-1) return t[i][j];
    int ans=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int tans=solve1(arr,i,k)+solve1(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        ans=min(tans,ans);
    }
    return t[i][j]=ans;
}
int solve(int arr[],int i,int j)
{
    if(i>=j) return 0;
    int ans=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int tans=solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        ans=min(ans,tans);
    }
    return ans;
}
int main()
{
    memset(t,-1,sizeof(t));
    int arr[] = { 40, 20, 30, 10, 30 };
    cout<<solve1(arr,1,4);
}