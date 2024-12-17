class Solution {
public:
    void qsortRecursive(vector<int>::iterator mas, int size)
    {
        int l = 0, r = size - 1;
        int mid = mas[size / 2];

        do {
            while (mas[l] < mid) l++;
            while (mas[r] > mid) r--;
            if (l <= r) {
                int temp = mas[l];
                mas[l] = mas[r];
                mas[r] = temp;
                l++; r--;
            }
        } while (l <= r);

        if (r > 0) qsortRecursive(mas, r + 1);
        if (l < size) qsortRecursive(mas + l, size - l);
    }

    void sortColors(vector<int>& nums) {
        qsortRecursive(nums.begin(), nums.size());
    }
};
