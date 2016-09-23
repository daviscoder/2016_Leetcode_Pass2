/**
 * O(m + n), O(n)
 * 空向量，有交集，无交集
 */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> nums;
        for (int i = 0; i < nums1.size(); i++) {
            nums.insert (nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (nums.count(nums2[i])) {
                res.push_back (nums2[i]);
                nums.erase (nums2[i]);
            }
        }
        return res;
    }
};
