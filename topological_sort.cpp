#include <bits/stdc++.h>
using namespace std;
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<int> in(V, 0);
    for (int i = 0; i < V; ++i)
    {
        for (auto it : adj[i])
        {
            in[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; ++i)
    {
        if (in[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int ver = q.front();
        q.pop();
        ans.push_back(ver);
        for (auto cld : adj[ver])
        {
            if (--in[cld] == 0)
                q.push(cld);
        }
    }
    return ans;
}