/**
 * i 指向当前以访问最后一个元素. j 指向连续非0元素的最后一个
 **/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }
        for (; j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};
