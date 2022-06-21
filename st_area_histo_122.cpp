#include <bits/stdc++.h>
using namespace std;

long long getMaxArea(long long arr[], int n)
{
    // Your code here
    vector<long long> left(n), right(n);
    stack<long long> st;
    // fill left
    for (long long i = 0; i < n; i++)
    {
        if (st.empty())
        {
            left[i] = 0;
            st.push(i);
        }
        else
        {
            while (!st.empty() and arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            left[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
    }
    while (!st.empty())
    {
        st.pop();
    }
    for (long long i = n - 1; i >= 0; i--)
    { // fill  right
        if (st.empty())
        {
            right[i] = n - 1;
            st.push(i);
        }
        else
        {
            while (!st.empty() and arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            right[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }
    }
    long long maxi = 0;
    for (long long i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i] * (right[i] - left[i] + 1));
    }
    return maxi;
}