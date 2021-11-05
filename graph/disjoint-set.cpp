#include<bits/stdc++.h>
using namespace std;

int par[10000];
int ran[10000];

void mset(int n)
{
    for(int i=1;i<=n;i++)
    {
        par[i]=i;
        ran[i]=0;
    }
}
int findpar(int i)
{
    if(i==par[i]) return i;
    return par[i]=findpar(par[i]);
}
void unionset(int i,int j)
{
    int u=findpar(i);
    int v=findpar(j);
    if(ran[u]>ran[v])
    {
        par[v]=u;
    }
    else if(ran[v]>ran[u])
    {
        par[u]=v;
    }
    else
    {
        par[u]=v;
        ran[u]++;
    }
}
