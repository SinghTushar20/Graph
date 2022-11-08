#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isLoop(int vertex, int parent, bool vis[], vector<int> adj[])
    {
        vis[vertex] = true;
        bool loopFlag = false;
        for(auto child: adj[vertex])
        {
            if(vis[child] && child == parent)
                continue;
            if(vis[child])
                return true;

            loopFlag |= isLoop(child,vertex, vis,adj);    
        }
        return loopFlag;
    }
    bool isCycle(int V, vector<int> adj[]) {
        bool vis[V+10] = {};
        for(int i = 0; i < V; i++)
        {
            if(vis[i])continue;
            if(isLoop(i,-1,vis,adj))
                return true;
        }
        return false;
    }
};
signed main()
{
    int n, m, v1, v2;
    cin >> n >> m;
    vector<int> adj[m+10];
    for(int i = 0; i < m; i++)
    {
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

}