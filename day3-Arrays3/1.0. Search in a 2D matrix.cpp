class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int i=0,j=n-1;
        while(i<m && j>=0) // i: Row & j: Column
        {
            if(target > matrix[i][j]) i++;
            else if(target < matrix[i][j]) j--;
            else return true;
        }
        return false;
    }
};
// Time Comp: O(m+n) Space: O(1)
