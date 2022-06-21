#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &st, vector<int> &res)
{
    if (st.empty())
        return;
    res.push_back(st.top());
    st.pop();
    solve(st, res);
}
vector<int> Reverse(stack<int> st)
{
    vector<int> res;
    solve(st, res);
    return res;
}