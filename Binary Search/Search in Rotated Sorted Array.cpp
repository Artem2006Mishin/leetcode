class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        
        while (left <= right) {
            mid = (right - left) / 2 + left;
            if (target == nums[mid])
                return mid;

            if (nums[left] <= nums[mid]) {
                if (target > nums[mid] || target < nums[left])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else {
                if (target < nums[mid] || target > nums[right])
                    right = mid - 1;
                else {
                    left = mid + 1;
                }			
            }
        }
        return -1;
    }
};
