#include <bits/stdc++.h>
using namespace std;

int isStackPermutation(int N, vector<int> &A, vector<int> &B)
{
    stack<int> s;
    int k = 0;
    for (int i = 0; i < N; ++i)
    {
        s.push(A[i]);
        if (s.top() == B[k])
        {
            while (!s.empty() && s.top() == B[k])
            {
                s.pop();
                k++;
            }
        }
    }
    if (s.empty())
        return 1;
    else
        return 0;
}