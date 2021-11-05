#include<bits/stdc++.h>
using namespace std;
void add(vector<pair<int,int>> graph[],int i,int j,int w)
{
    graph[i].push_back({j,w});
    graph[j].push_back({i,w});
}
vector<int> dijkstra(vector<pair<int,int>> graph[],int source)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    vector<int> ans(6,INT_MAX);
    ans[0]=0;
    ans[source]=0;
    q.push({0,source});
    while(!q.empty())
    {
        auto p=q.top();
        q.pop();
        for(auto i:graph[p.second])
        {
            if(p.first+i.second<ans[i.first])
            {
                ans[i.first]=p.first+i.second;
                q.push({ans[i.first],i.first});
            }
        }
    }
    return ans;
}
int main()
{
    vector<pair<int,int>> graph[6];
    add(graph,1,2,2);
    add(graph,1,4,1);
    add(graph,2,5,5);
    add(graph,2,3,4);
    add(graph,3,4,3);
    add(graph,3,5,1);
    int source=1;
    vector<int> ans= dijkstra(graph,source);
    for(int i:ans) cout<<i<<" ";
}