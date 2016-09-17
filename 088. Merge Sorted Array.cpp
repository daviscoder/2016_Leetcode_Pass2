/**
 * 记得从后往前放merge好的数字，方便省事！
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 || j >= 0) {
            if (i < 0) {
                nums1[k] = nums2[j];
                j--;
            }
            else if (j < 0) {
                nums1[k] = nums1[i];
                i--;
            }
            else {
                nums1[k] = max (nums1[i], nums2[j]);
                nums1[i] > nums2[j]? i-- : j--;
            }
            k--;
        }
    }
};
