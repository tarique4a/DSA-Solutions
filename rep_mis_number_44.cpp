#include <bits/stdc++.h>
using namespace std;
 int *findTwoElement(int *arr, int n) {
        int xxor=0;
        for(int i=0;i<n;++i)
        {
            xxor^=arr[i];
        }
        for(int i=1;i<=n;++i)
        {
            xxor^=i;
        }
        int rmsb=xxor & -xxor;
        int rep=0,mis=0;
        for(int i=0;i<n;++i)
        {
            if((arr[i] & rmsb)==0)
            {
                rep^=arr[i];
            }
            else{
                mis^=arr[i];
            }
        }
        for(int i=1;i<=n;++i)
        {
            if((i & rmsb)==0)
            {
                rep^=i;
            }
            else{
                mis^=i;
            }
        }
        int *p=new int[2];
        for(int i=0;i<n;++i)
        {
            if(arr[i]==rep)
            {
                p[0]=rep;
                p[1]=mis;
                break;
            }
            else if(arr[i]==mis)
            {
                p[0]=mis;
                p[1]=rep;
                break;
            }
        }
    
        return p;
    }