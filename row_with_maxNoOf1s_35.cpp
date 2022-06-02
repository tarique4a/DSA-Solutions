#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	   // int row=-1;
	    int c=0;
	    while(c<m)
	    {
	        for(int i=0;i<n;++i)
	        if(arr[i][c]==1)
	        {
	            return i;
	        }
	        
	        c++;
	    }
   return -1;
	}