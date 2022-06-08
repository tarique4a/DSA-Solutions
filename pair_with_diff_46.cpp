#include <bits/stdc++.h>
using namespace std;

bool findPair(int arr[], int l, int n){
    //code
    sort(arr,arr+l);
    int i=0, j=1;
    while(i<l && j<l)
    {
        if( (i!=j)&&((arr[j]-arr[i])==n))
            return true;
        else if((arr[j]-arr[i])>n)
            i++;
        else
            j++;
    }
    return false;
}