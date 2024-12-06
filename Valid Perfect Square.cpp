class Solution {
public:
    bool isPerfectSquare(int num) {
	long int left = 1;
	long int right = 100'000;
	long int mid;
	long int res;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		res = mid * mid;
		if (res == num) {
			return true;
		}
		
		if (res < num)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return false;
}
};
