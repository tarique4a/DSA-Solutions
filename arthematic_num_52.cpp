#include <bits/stdc++.h>
using namespace std;
int inSequence(int A, int B, int C)
{
    if (C == 0)
        return A == B;
    long long int xd = B - A;
    if (xd * C < 0)
        return 0;
    if ((xd % C) == 0)
        return 1;
    else
        return 0;
}