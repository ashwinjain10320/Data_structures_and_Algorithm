#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<int> graph[],int i,vector<int> vis,vector<int> dfsvis)
{
    if(!vis[i])
    {
        vis[i]=1;
        dfsvis[i]=1;
        for(int j:graph[i])
        {
            if(dfs(graph,j,vis,dfsvis)) return true;
        }
        dfsvis[i]=0;
    }
    else
    {
        if(dfsvis[i]==1) return true;
    }
    return false;
}
bool detect(vector<int> graph[])
{
    vector<int> vis(10,0);
    vector<int> dfsvis(10,0);
    
    for(int i=1;i<=9;i++)
    {
        if(!vis[i])
        {
            if(dfs(graph,i,vis,dfsvis)) return true;
        }
    }
    return false;
}
bool bfs(vector<int> graph[])
{
    vector<int> indeg(10,0);
    for(int i=1;i<10;i++)
    {
        for(int j:graph[i])
        {
            indeg[j]++;
        }
    }
    queue<int> qq;
    for(int i=1;i<10;i++)
    {
        if(indeg[i]==0) qq.push(i);
    }
    int cnt=0;
    while(!qq.empty())
    {
        int c=qq.front();
        qq.pop();
        cnt++;
        for(int j:graph[c])
        {
            indeg[j]--;
            if(indeg[j]==0) qq.push(j);
        }
    }
    return !(cnt==9);
}
int main()
{
    vector<int> graph[10];
    graph[1].push_back(2);
    graph[2].push_back(3);
    graph[3].push_back(4);
    graph[3].push_back(6);
    graph[4].push_back(5);
    graph[6].push_back(5);
    graph[7].push_back(2);
    graph[7].push_back(9);
    graph[8].push_back(9);
    
    cout<<(bfs(graph)?"YES":"NO")<<endl;

}