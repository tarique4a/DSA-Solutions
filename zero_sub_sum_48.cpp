#include <bits/stdc++.h>
using namespace std;
#define ll long long
 ll findSubarray(vector<ll> arr, int n ) {
        //code here
        ll c=0;
        unordered_map<ll,ll> m;
        ll sum=0;
        m[0]=1;
        for(int i=0;i<n;++i)
        {
            sum+=arr[i];
            if(m.find(sum)!=m.end())
            {
                c+=m[sum];
                m[sum]++;
            }
            else{
                m[sum]++;
            }
            
        }
        return c;
    }