#include <bits/stdc++.h>
using namespace std;

 int countSquares(int N) {
        
        int res=0;
        for(int i=1;i*i<N;i++)
        {
            if(i*i<N)
            res++;
        }
       
        return res;
    }