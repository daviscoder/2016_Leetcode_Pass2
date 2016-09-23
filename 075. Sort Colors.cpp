/**
 * O(n), O(1)
 * 3 pointers: l is the index of leading 0s.
 * r is the index of the tailing 2s.
 * i is the current checking element.
 */
 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        for (int i = 0; i <= r;) {
            if (nums[i] == 0 && i != l) { // i != l!
                swap (nums[i], nums[l]);
                l++;
            }
            else if (nums[i] == 2) {
                swap (nums[i], nums[r]);
                r--;
            }
            else {
                i++;
            }
        }
    }
};
