// Average O(n), worst case O(n^2)

class Solution {
public:
    int partition (vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap (nums[l], nums[r]);
                l++;
                r--;
            }
            if (nums[l] >= pivot) {
                l++;
            }
            if (nums[r] <= pivot) {
                r--;
            }
        }
        swap (nums[left], nums[r]);
        return r;
    }
    int findKthLargest(vector<int>& nums, int k) {
        if (k > nums.size()) {
            return 0;
        }
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) {
                return nums[pos];
            }
            else if (pos < k - 1) {
                left = pos + 1;
            }
            else {
                right = pos - 1;
            }
        }
        return 0;
    }
};
