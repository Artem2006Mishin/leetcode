#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;
	int mid, res_l = -1, res_r = -1;

	while (left <= right) {
		mid = (right - left) / 2 + left;
		if (target == nums[mid]) {
			res_l = mid;
			right = mid - 1;
		}
		else if (target > nums[mid]) {
			left = mid + 1;		
		}
		else if (target < nums[mid]) {
			right = mid - 1;
		}
	}

	left = 0, right = nums.size() - 1;
	while (left <= right) {
		mid = (right - left) / 2 + left;
		if (target == nums[mid]) {
			res_r = mid;
			left = mid + 1;
		}
		else if (target > nums[mid]) {
			left = mid + 1;
		}
		else if (target < nums[mid]) {
			right = mid - 1;
		}
	}

	return { res_l, res_r };
}
