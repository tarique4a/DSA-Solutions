#include <bits/stdc++.h>
using namespace std;

 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=-1;
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<r;++i)
        {
            if(target>= matrix[i][0] && target<=matrix[i][c-1])
                row=i;
        }
        if(row==-1) return false;
        for(int i=0;i<c;++i)
        {
            if(matrix[row][i]==target)
                return true;
        }
        return false;
    }