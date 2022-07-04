#include <bits/stdc++.h>
using namespace std;
bool isPossible(int N, vector<pair<int, int>> &prerequisites)
{
    vector<int> adj[N];
    for (auto it : prerequisites)
    {
        adj[it.second].push_back(it.first);
    }
    vector<int> in(N, 0);
    for (int i = 0; i < N; ++i)
    {
        for (auto it : adj[i])
        {
            in[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < N; ++i)
    {
        if (in[i] == 0)
            q.push(i);
    }
    int c = 0;
    while (!q.empty())
    {
        int ver = q.front();
        q.pop();
        for (auto cld : adj[ver])
        {
            if (--in[cld] == 0)

                q.push(cld);
        }
        c++;
    }
    if (c == N)
        return true;
    else
        return false;
}