class Solution {
public:
int searchInsert(vector<int>& nums, int target) {
	long int left = 0;
	long int right = nums.size() - 1;
	long int mid;

	while (left < right) 
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] < target) {
			left = (mid + 1) > nums.size() - 1 ? nums.size() - 1 : mid + 1;
		}
		else {
			right = (mid - 1 > 0) ? mid - 1 : 0;
		}
	}
	if (target > nums[right])
		return right + 1;
	else
		return right;
    }
};
