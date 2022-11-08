#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> g[N];
bool vis[N];
bool dfs(int vertex, int parent, bool vis[])
{
    vis[vertex] = true;
    bool isLoop = false;
    for(auto child: g[vertex])
    {
        if(vis[child] && child == parent)
            continue;
        if(vis[child])
            return true;

        isLoop |= dfs(child,vertex, vis);    
    }
    return isLoop;
}
signed main()
{
    int n, m, v1, v2;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    bool flag = false;
    for(int i = 1; i <= n; i++)
    {
        if(vis[i])continue;
        if(dfs(i,-1,vis))
        {
            cout << "YES Loop Exist \n";
            flag = true;
            break;
        }
    }
    if(!flag)cout << "NO Loop does not exist \n";
}