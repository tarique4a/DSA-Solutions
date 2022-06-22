#include <bits/stdc++.h>
using namespace std;

int findMaxLen(string s)
{
    stack<pair<char, int>> r;
    int l = s.length();
    for (int i = 0; i < l; ++i)
    {
        if (s[i] == '(')
            r.push({s[i], i});
        else
        {
            if (!r.empty() && r.top().first == '(')
            {
                r.pop();
            }
            else
            {
                r.push({s[i], i});
            }
        }
    }
    if (r.empty())
        return l;
    int m = 0;
    while (!r.empty())
    {
        int t = l - r.top().second - 1;
        m = max(m, t);
        l = r.top().second;
        r.pop();
    }
    return max(l, m);
}