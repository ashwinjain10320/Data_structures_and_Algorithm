#include<bits/stdc++.h>
using namespace std;
void add(vector<pair<int,int>> graph[],int i,int j,int w)
{
    graph[i].push_back({j,w});
    graph[j].push_back({i,w});
}
void optimised(int n,vector<pair<int,int>> graph[])
{
    vector<int> key(n,INT_MAX);
    vector<bool> mst(n,false);
    vector<int> parent(n,-1);

    int st=0;
    key[st]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pp;
    pp.push({key[st],st});
    for(int i=0;i<n-1;i++)
    {
        int u=pp.top().second;
        pp.pop();
        mst[u]=true;
        for(auto j:graph[u])
        {
            if(!mst[j.first] && j.second<key[j.first])
            {
                key[j.first]=j.second;
                parent[j.first]=u;
                pp.push({key[j.first],j.first});
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        cout<<parent[i]<<" -> "<<i<<" ("<<key[i]<<") "<<endl;
    }
}
void brute(int n,vector<pair<int,int>> graph[])
{
    vector<int> key(n,INT_MAX);
    vector<bool> mst(n,false);
    vector<int> parent(n,-1);

    int st=0;
    key[st]=0;
    for(int i=0;i<n-1;i++)
    {
        int minn=INT_MAX,u;
        for(int j=0;j<n;j++)
        {
            if(key[j]<minn && !mst[j])
            {
                minn=key[j];
                u=j;
            }
        }
        mst[u]=true;
        for(auto j:graph[u])
        {
            if(!mst[j.first] && j.second<key[j.first])
            {
                key[j.first]=j.second;
                parent[j.first]=u;
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        cout<<parent[i]<<" -> "<<i<<" ("<<key[i]<<") "<<endl;
    }
}
int main()
{
    int n=5;
    vector<pair<int,int>> adj[n];
    add(adj,0,1,2);
    add(adj,0,3,6);
    add(adj,1,2,3);
    add(adj,1,3,8);
    add(adj,1,4,5);
    add(adj,2,4,7);
    //brute(5,adj);
    optimised(5,adj);

}