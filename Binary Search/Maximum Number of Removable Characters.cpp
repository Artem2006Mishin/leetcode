#include <string>
#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    int maximumRemovals(std::string s, std::string p, std::vector<int>& removable) {
        auto isSubsequence = [&](const std::string& s, const std::string& subseq, const std::set<int>& removed) {
            int i1 = 0, i2 = 0;
            while (i1 < s.length() && i2 < subseq.length()) {
                if (removed.count(i1) || s[i1] != subseq[i2]) {
                    i1++;
                    continue;
                }
                i1++;
                i2++;
            }
            return i2 == subseq.length();
        };

        int res = 0;
        int l = 0, r = removable.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            std::set<int> removed(removable.begin(), removable.begin() + m + 1);
            if (isSubsequence(s, p, removed)) {
                res = std::max(res, m + 1);
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return res;
    }
};

