class Solution {
public:
    int arrayIndexSearch(vector<vector<int>>& matrix, int target)
    {
        int left = 0, right = matrix.size() - 1, last = matrix[0].size() - 1;
        int mid;

        while (left <= right) {
            mid = (right - left) / 2 + left;
            if (target == matrix[mid][last]) {
                return mid;
            }
            else if (target > matrix[mid][last]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }

    bool binarySearch(vector<int>& arr, int target) 
    {
        int left = 0, right = arr.size() - 1;
        int mid;
        while (left <= right) {
            mid = (right - left) / 2 + left;
            if (target == arr[mid]) {
                return true;
            }
            else if (target > arr[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int index_array = arrayIndexSearch(matrix, target);
        if (index_array == matrix.size())
	        return false;

        bool index_elem = binarySearch(matrix[index_array], target);
        return index_elem;
    }
};
