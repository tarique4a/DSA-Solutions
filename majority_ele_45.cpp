#include <bits/stdc++.h>
using namespace std;
 int majorityElement(int a[], int n)
    {
        int res=0,count=1;
        for(int i=1;i<n;++i)
        {
            if(a[res]==a[i])
            count++;
            else
            count--;
            if(count==0)
            {
                res=i;
                count=1;
            }
        }
        count=0;
        for(int i=0;i<n;++i)
        {
            if(a[res]==a[i])
            count++;
        }
        if(count> n/2)
        return a[res];
        else
        return -1;
        
    }