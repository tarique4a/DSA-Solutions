#include <bits/stdc++.h>
using namespace std;
long long countTriplets(long long a[], int n, long long sum)
{
    sort(a, a + n);
    long long c = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            int l = j + 1, h = n - 1, sum1 = sum - (a[i] + a[j]);
            while (l <= h)
            {
                int m = (l + h) / 2;
                if (a[m] < sum1)
                    l = m + 1;
                else
                    h = m - 1;
            }
            c += l - j - 1;
        }
    }
    return c;
}