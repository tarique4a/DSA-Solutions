#include <bits/stdc++.h>
using namespace std;
int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        priority_queue<int> q;
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(arr1[i]<arr2[j])
            {
                q.push(arr1[i]);
                i++;
            }
            else if(arr2[j]<=arr1[i]){
                q.push(arr2[j]);
                j++;
            }
            
            
            if(q.size()==k) return q.top();
        }
       
        while(i<n)
        {
            q.push(arr1[i]);
            i++;
            if(q.size()==k) break;
        }
        while(j<m)
        {
            q.push(arr2[j]);
            j++;
            if(q.size()==k) break;
        }
        return q.top();
    }