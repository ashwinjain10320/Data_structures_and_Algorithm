#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> graph[],int i,vector<int> vis,stack<int> st)
{
    vis[i]=1;
    for(auto j:graph[i])
    {
        if(vis[j]==-1)
        {
            dfs(graph,j,vis,st);
            st.push(j); // dfs call is over, add it to stack
        }
    }
}
vector<int> topodfs(vector<int> graph[])
{
    stack<int> st;
    vector<int> ans;
    vector<int> vis(6,-1);
    for(int i=0;i<=5;i++)
    {
        if(vis[i]==-1)
        {
            dfs(graph,i,vis,st);
            st.push(i); // dfs call is over, add it to the stack
        }
    }
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
vector<int> topobfs(vector<int> graph[]) // Kahn's Algorithm
{
    vector<int> indegree(6,0);
    // finding indegree of all vertices
    for(int i=0;i<6;i++)
    {
        for(int j:graph[i])
        {
            indegree[j]++;
        }
    }
    queue<int> qq;
    vector<int> ans;
    for(int i=0;i<6;i++)
    {
        if(indegree[i]==0) qq.push(i);
    }
    while(!qq.empty())
    {
        int c=qq.front();
        qq.pop();
        for(int i:graph[c])
        {
            indegree[i]--;
            if(indegree[i]==0) qq.push(i);
        }
        ans.push_back(c); // once all the adjacent vertices are done, push it to the answer.
    }
    return ans;
}

int main()
{
    vector<int> graph[6];
    graph[2].push_back(3);
    graph[3].push_back(1);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[5].push_back(0);
    graph[5].push_back(2);
    // vector<int> ans= topobfs(graph);  ans= { 5 4 3 2 1 0 }
    vector<int> ans= topobfs(graph);  // ans= { 4 5 0 2 3 1 }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
