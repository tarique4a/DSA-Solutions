#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int k)
{

    queue<pair<long long int, int>> q;
    vector<long long> res;
    for (int i = 0; i < N; ++i)
    {
        if (A[i] < 0)
            q.push({A[i], i});
    }
    for (int i = 0; i < N - k + 1; ++i)
    {
        if (!q.empty() && (i <= q.front().second && q.front().second < i + k))
            res.push_back(q.front().first);
        else
        {
            if (!q.empty() && (i <= q.front().second && q.front().second < i + k))
                res.push_back(q.front().first);
            else
                res.push_back(0);
            q.pop();
        }
    }
    return res;
}