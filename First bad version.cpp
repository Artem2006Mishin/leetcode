class Solution {
public:
    int firstBadVersion(int n) 
    {
        long int left = 1;
        long int right = n;
        long int result = right;
        long int mid;

        while (left <= right) 
        {
            long int mid = (left + right) / 2;
            if (isBadVersion(mid)) {
                result = mid;
                right = mid - 1;
            }           
            else {
                left = mid + 1;
            }
                
        }
        return result;
    }
};
