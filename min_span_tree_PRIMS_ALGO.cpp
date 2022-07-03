#include <bits/stdc++.h>
using namespace std;
// PRIMS ALOG.....
 int spanningTree(int V, vector<vector<int>> adj[])
    {
       int ans = 0;
        vector<bool> vis(V,false);
        vector<int> key(V,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        key[0] = 0;
        pq.push({0,0});
        while(!pq.empty()){  // doesn't work when I iterate V-1 times as shown in the article before it.
            int u = pq.top().second;
            pq.pop();
            
            vis[u] = true;
            
            for(auto it : adj[u]){
                if(!vis[it[0]] && it[1] < key[it[0]] ){
                    key[it[0]] = it[1];
                    pq.push({key[it[0]], it[0]});
                }
            }
        }
        for(auto i : key)
            ans += i;
        return ans;
    }