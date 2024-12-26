class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long int l = 1, r = *max_element(piles.begin(), piles.end());
        long int res = r;

        while (l <= r) {
            long int k = (l + r) / 2;
            long int hours = 0;
            for (int p : piles) {
                hours += std::ceil(static_cast<double>(p) / k);
            }

            if (hours <= h) {
                res = std::min(res, k);
                r = k - 1;
            }
            else {
                l = k + 1;
            }
        }

        return res;
    }
};
