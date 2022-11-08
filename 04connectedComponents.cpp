#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
bool vis[N];
vector<int> g[N];
void dfs(int vertex)
{
    vis[vertex] = true;
    for(auto child: g[vertex])
    {
        if(vis[child])continue;
        dfs(child);
    }
}
signed main()
{
    int n, m;
    cin >> n >> m;
    int v1, v2;
    for(int i = 1; i < m; i++)
    {
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    int cnt = 0;
    for(int i = 0; i <= n; i++)
    {
        if(vis[i])continue;
        dfs(i);
        cnt++;
    }
    cout << cnt << "\n";

}