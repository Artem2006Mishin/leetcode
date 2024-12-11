class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0, column = m - 1;
        
        while (row < n && column >= 0) 
        {
            if (target == matrix[row][column])
                return true;
            else if (target > matrix[row][column])
                row++;
            else
                column--;
        }
        return false;
    }
};
