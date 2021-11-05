#include<bits/stdc++.h>
using namespace std;
struct Node {
    int u;
    int v;
    int w;
    Node(int u1,int v1,int w1)
    {
        u=u1;
        v=v1;
        w=w1;
    }
};
static bool comp(Node a,Node b)
{
    return a.w<b.w;
}
int findpar(int u,vector<int>& par)
{
    if(u==par[u])
    {
        return u;
    }
    return par[u]=findpar(par[u],par);
}
void unionn(int u,int v,vector<int>& ran,vector<int>& par)
{
    int a=findpar(u,par);
    int b=findpar(v,par);
    if(ran[a]>ran[b])
    {
        par[b]=a;
    }
    else if(ran[a]<ran[b])
    {
        par[a]=b;
    }
    else
    {
        par[b]=a;
        ran[a]++;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<Node> mm;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        mm.push_back(Node(u,v,w));
    }
    sort(mm.begin(),mm.end(),comp);
    vector<int> par(n);
    vector<int> ran(n,0);
    for(int i=0;i<n;i++) 
    {
        par[i]=i;
    }
    
    int cost=0;
    vector<pair<int,int>> mst;
    for(auto i:mm)
    {
        if(findpar(i.u,par)!=findpar(i.v,par))
        {
            cost+=i.w;
            mst.push_back({i.u,i.v});
            unionn(i.u,i.v,ran,par);
        }
    }
    for(auto i:mst)
    {
        cout<<i.first<<" -> "<<i.second<<endl;
    }
    cout<<"total cost is = "<<cost<<endl;
}