#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int main()
{
    int n, m, v1, v2;
    cin >> n >> m;
    int graph[n][n];
    for(int i = 0; i < m; i++)
    {
        cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
    
} 