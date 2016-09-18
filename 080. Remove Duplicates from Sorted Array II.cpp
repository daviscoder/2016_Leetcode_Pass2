class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size();
        // i 表示下一个要检查的数字，j表示当前最后一个排好的数字的下标
        int i = 2, j = 1;
        while (i < nums.size()) {
            // j - 1表示当前比较的数的前两个是谁...，注意不是i - 2，因为此时确定正确的区间是0 ~ j.
            if (nums[i] != nums[j - 1]) {
                j++;
                nums[j] = nums[i];
            }
            i++;
        }
        // size == 下标+1
        return j + 1;
    }
};
