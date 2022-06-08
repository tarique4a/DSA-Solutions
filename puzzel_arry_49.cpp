#include <bits/stdc++.h>
using namespace std;
vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{

    long long int pro = 1;
    vector<long long int> res(n, 0);
    bool flag = false;
    int indi;
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] == 0)
        {
            flag = true;
            indi = i;
        }
    }
    if (flag)
    {
        for (int i = 0; i < n; ++i)
        {
            if (i == indi)
                continue;
            pro *= nums[i];
        }
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == 0)
                res[i] = pro;
        }
        return res;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            pro *= nums[i];
        }
        for (int i = 0; i < n; ++i)
        {
            res[i] = pro / nums[i];
        }
        return res;
    }
}