#include<bits/stdc++.h>
using namespace std;


int kthSmallest()
{
    int n,k;
    int mat[n][n];
  priority_queue<int> q;
  for(int i=0;i<n;++i)
  {
       for(int j=0;j<n;++j)
       {
           q.push(mat[i][j]);
           if(q.size()>k)
           q.pop();
       }
  }
  return q.top();
}