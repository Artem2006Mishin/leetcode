class Solution {
public:
    int mySqrt(int x) {
        long int left = 1;
        long int right = x;
        long int mid;
        long int res;
        long int last; 

        while (left <= right) {
            mid = (right - left) / 2 + left;
            res = mid * mid;
            if (res == x) {
                return mid;
            }
            else if (res > x) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
                last = mid;
            }
        }
        return last;
    }
};
