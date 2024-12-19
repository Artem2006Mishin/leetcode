class Solution {
public:
    int splitArray(vector<int>& nums, int k)
    {
        int left = 0, right = 0;
        for (int n : nums) {
            left = max(left, n);
            right += n;
        }

        auto canSplit = [&](int sum) {
            int currentSum = 0, parts = 1;
            for (int n : nums)
            {
                currentSum += n;
                if (currentSum > sum) {
                    currentSum = n;
                    ++parts;
                }
            }
            return parts <= k;
        };

        while (left < right)
        {
            int mid = (right - left) / 2 + left;
            if (canSplit(mid))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};
