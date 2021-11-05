#include<bits/stdc++.h>
using namespace std;

void findtoposort(vector<pair<int,int>> graph[],int n,vector<int>& vis,stack<int>& tps)
{
    vis[n]=1;
    for(auto i:graph[n])
    {
        if(!vis[i.first])
        {
            findtoposort(graph,i.first,vis,tps);
            tps.push(i.first);
        }
    }
}
int main()
{
    vector<pair<int,int>> graph[6];
    graph[0].push_back({1,2});
    graph[0].push_back({4,1});
    graph[1].push_back({2,3});
    graph[2].push_back({3,6});
    graph[4].push_back({2,2});
    graph[4].push_back({5,4});
    graph[5].push_back({3,1});
    vector<int> vis(6,0);
    stack<int> tps;
    findtoposort(graph,0,vis,tps);
    tps.push(0);
    vector<int> dist(6,INT_MAX);
    dist[0]=0;
    while(!tps.empty())
    {
        int c=tps.top();
        tps.pop();
        if(dist[c]==INT_MAX) continue;
        for(auto i:graph[c])
        {
            dist[i.first]=min(dist[i.first],i.second+dist[c]);
        }
    }
    for(int i=0;i<6;i++) 
    {
        cout<<dist[i]<<" ";
    }
}