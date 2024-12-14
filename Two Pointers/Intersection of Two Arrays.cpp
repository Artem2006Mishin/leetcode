class Solution {
public:
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        set<int> check; 
        vector<int> res; 
        int first = 0, second = 0;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        while (nums1.size() > first && nums2.size() > second)
        {
            if (nums1[first] == nums2[second] && check.find(nums1[first]) == check.end()) {
                check.insert(nums1[first]);
                res.push_back(nums1[first]);
                first++; second++;
            }
            else if (nums1[first] > nums2[second])
                second++;
            else
                first++;
        }


        return res;
    }
};
