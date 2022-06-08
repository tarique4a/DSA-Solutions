#include <bits/stdc++.h>
using namespace std;

 int search(int nums[], int l, int h, int target){
       int low = l;
        int high = h;
        while(low<=high) {
            int mid  = low +(high - low)/2;
            if(target == nums[mid]){
                return mid;
            }
            // check if left part is sorted or not
            if(nums[low]  < nums[mid]){
                if(target <nums[low] || target > nums[mid]){ // target is out of the left part boundary scope
                    low = mid +1;

                } else{
                    // target lies within this left part
                    high = mid -1;
                }
            } else if(nums[low] > nums[mid]){
                // right part is sorted
                if(target < nums[mid] || target > nums[high]){
                    high = mid -1;
                } else {
                    // target lies within the right part boundaries
                    low = mid+1;
                }
            } else{

                // duplicates
                low++; // => O(n) 111111112
            }

        }
        return -1;;
    
    }