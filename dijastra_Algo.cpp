#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<bool> vis(V + 1, false);
    vector<int> dis(V + 1, INT_MAX);
    set<pair<int, int>> st;
    dis[S] = 0;
    st.insert({0, S});
    while (st.size() > 0)
    {
        auto it = *st.begin();
        int ver = it.second;
        int wt = it.first;
        st.erase(st.begin());
        if (vis[ver])
            continue;
        vis[ver] = true;
        for (auto it : adj[ver])
        {
            int cld = it[0];
            int wet = it[1];
            if (!vis[cld])
            {
                dis[cld] = min(dis[cld], dis[ver] + wet);
                st.insert({dis[cld], cld});
            }
        }
    }
    return dis;
}