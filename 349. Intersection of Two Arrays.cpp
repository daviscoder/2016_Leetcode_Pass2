// 4 min 24s

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> mySet;
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++) {
            if (mySet.count (nums1[i]) == 0) {
                mySet.insert (nums1[i]);
            }
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (mySet.count (nums2[i])) {
                res.push_back (nums2[i]);
                mySet.erase (nums2[i]);
            }
        }
        return res;
    }
};
