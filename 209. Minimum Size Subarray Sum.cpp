/**
 * O (n), O(1).
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0 || s <= 0)
            return 0;
        int sum = nums[0], start = 0, end = 0, length = INT_MAX;
        while (end < nums.size()) {
            cout << sum << endl;
            if (sum >= s) {
                length = min (length, end - start + 1);
                sum = sum - nums[start];
                start++;
            }
            else { // end++ 一定要写在 sum+= nums[end]之前，因为最后一个元素加完后end不会等于nums.size(). 给了下一个iteration进入if的机会
                end++;
                sum += nums[end];
            }
        }
        return length == INT_MAX? 0 : length;
    }
};
};
