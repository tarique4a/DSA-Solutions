#include <bits/stdc++.h>
using namespace std;
vector<int> minimumTime(int n, vector<vector<int>> &edges, int m)
{
    vector<int> adj[n + 1];
    for (int i = 0; i < edges.size(); ++i)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> ind(n + 1, 0);
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        for (int x : adj[i])
            ind[x]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (ind[i] == 0)
        {
            ans[i] = 1;
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty())
    {
        int ver = q.front();
        q.pop();
        topo.push_back(ver);
        for (int j : adj[ver])
        {
            if (--ind[j] == 0)
            {
                ans[j] = ans[ver] + 1;
                q.push(j);
            }
        }
    }
    ans.erase(ans.begin());
    return ans;
}