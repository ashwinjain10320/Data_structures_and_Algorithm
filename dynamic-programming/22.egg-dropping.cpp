#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int eggd(int e,int f)
{
    if(e==1 || f<=1) return f;
    int mn=INT_MAX;
    for(int k=1;k<f;k++)
    {
        int ta= 1+max(eggd(e-1,k-1),eggd(e,f-k));
        mn=min(mn,ta);
    }
    return mn;
}
int eggdmem(int e,int f)
{
    if(e==1 || f<=1) return f;
    if(dp[e][f]!=-1) return dp[e][f];
    int mn=INT_MAX;
    for(int k=1;k<f;k++)
    {
        int ta= 1+max(eggdmem(e-1,k-1),eggdmem(e,f-k));
        mn=min(mn,ta);
    }
    return dp[e][f]=mn;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cout<<eggdmem(3,5)<<endl;
}