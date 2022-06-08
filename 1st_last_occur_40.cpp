#include <bits/stdc++.h>
using namespace std;

vector<int> find(int arr[], int n , int x )
{
    vector<int> res;
    int lo=0,hi=n-1;
    int fi=-1,ls=-1;
    int mid;
    while(lo<=hi)
    {
        mid=lo+(hi-lo)/2;
        if(arr[mid]==x)
        {   
           fi=mid;
           hi=mid-1;
        }
        else if(arr[mid]>x)
        hi=mid-1;
        else
        lo=mid+1;
    }
    
    lo=0,hi=n-1;
    while(lo<=hi)
    {
         mid=lo+(hi-lo)/2;
        if(arr[mid]==x)
        {   
           ls=mid;
           lo=mid+1;
        }
        else if(arr[mid]>x)
        hi=mid-1;
        else
        lo=mid+1;
    }
    res.push_back(fi);
    res.push_back(ls);
    return res;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}