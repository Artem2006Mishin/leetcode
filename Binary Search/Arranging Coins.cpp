class Solution {
public:
    int arrangeCoins(int n)
    {
        int l = 1, r = n, res = 0, mid;
        long long int coins;
        while (l <= r)
        {
            mid = (r - l) / 2 + l;
            coins = static_cast<double>(mid) / 2 * (1 + mid);
            if (coins > n)
                r = mid - 1;
            else {
                l = mid + 1;
                res = max(res, mid);
            }
        }
        return res;
    }
};
