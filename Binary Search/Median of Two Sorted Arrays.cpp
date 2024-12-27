class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> arr;

        auto binarySearchRightBoundary = [&](vector<int> data, int left, int target) {
            int l = left, r = data.size() - 1;
            int res = -1;

            while (l <= r) {
                int m = (r - l) / 2 + l;
                if (target == data[m]) {
                    res = m;
                    l = m + 1;
                }
                else if (target > data[m]) l = m + 1;
                else r = m - 1;
            }

            res = res != -1 ? res : r;

            return res;
        };

        int index = 0, last = index;
        for (int i = 0; i < nums2.size(); i++) // линейный поиск
        {
            index = binarySearchRightBoundary(nums1, index, nums2[i]);
            index++;

            arr.insert(arr.end(), nums1.begin() + last, nums1.begin() + index);
            arr.emplace_back(nums2[i]); 
            
            last = index;
        }

        for (int i = index; i < nums1.size(); i++) {
            arr.emplace_back(nums1[i]);
        }

        if (arr.size() % 2 != 0) return arr[arr.size() / 2];
        return (arr[arr.size() / 2] + arr[arr.size() / 2 - 1]) / 2.0;
    }
};
