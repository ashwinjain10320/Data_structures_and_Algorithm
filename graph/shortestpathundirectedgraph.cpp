#include<bits/stdc++.h>
using namespace std;
vector<int> findshortestpath(vector<int> graph[],int source)
{
    vector<int> ans(9,INT_MAX);
    ans[source]=0;
    queue<int> q;
    q.push(source);
    while(!q.empty())
    {
        int c=q.front();
        q.pop();
        int dist=ans[c];
        for(int j:graph[c])
        {
            if(dist+1<ans[j])
            {
                q.push(j);
                ans[j]=dist+1;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> graph[9];
    graph[0].push_back(1);
    graph[0].push_back(3);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(1);
    graph[2].push_back(6);
    graph[3].push_back(0);
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[4].push_back(3);
    graph[4].push_back(5);
    graph[5].push_back(4);
    graph[5].push_back(6);
    graph[6].push_back(2);
    graph[6].push_back(5);
    graph[6].push_back(7);
    graph[6].push_back(8);
    graph[7].push_back(6);
    graph[7].push_back(8);
    graph[8].push_back(6);
    graph[8].push_back(7);

    vector<int> ans=findshortestpath(graph,0);
    for(int i=0;i<9;i++)
    {
        if(ans[i]==INT_MAX) cout<<"INF ";
        else cout<<ans[i]<<" ";
    }
}