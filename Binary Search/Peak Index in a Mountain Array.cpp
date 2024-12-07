class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        int mid, max_elem = -1, max_index = 0;

        while (left <= right)
        {
            mid = (right - left) / 2 + left;
            if (arr[mid] > max_elem) {
                max_elem = arr[mid];
                max_index = mid;
            }

            if (mid < right && arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            }
            else if (mid < right && arr[mid] > arr[mid + 1]) {
                right = mid - 1;
            }
            else {
                return max_index;
            }
        }
        return max_index;
    }
};
