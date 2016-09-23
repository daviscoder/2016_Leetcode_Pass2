/**
 * O(n), O(n)
 * myMap stores a key value pair such that the key is the sum from num[0] to num[i], 
 * and the key is the current length.
 * 注意 第20行要 + 1
 * Test case: 没有等于k的，最优解在开头的，最优解在末尾的，最优解在中间的
 */


class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        int sum = 0, res = 0;
        myMap[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int lookingfor = sum - k;
            if (myMap.count(lookingfor))
                res = max (res, i - myMap[lookingfor] + 1);
            if (myMap.count (sum) == 0)
                myMap[sum] = i + 1;
        }
        return res;
    }
};
