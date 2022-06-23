#include <bits/stdc++.h>
using namespace std;
struct petrolPump
{
    int petrol;
    int distance;
};
int tour(petrolPump p[], int n)
{
    int start = 0;
    int reqFeul = 0;
    int ex = 0;
    for (int i = 0; i < n; ++i)
    {
        ex += (p[i].petrol - p[i].distance);
        if (ex < 0)
        {
            start = i + 1;
            reqFeul += ex;
            ex = 0;
        }
    }
    if (reqFeul + ex >= 0)
        return start;
    return -1;
}