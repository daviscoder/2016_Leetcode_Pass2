//注意下标

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        int sum = 0;
        int res = INT_MIN;
        myMap[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int lookingfor = sum - k;
            if (myMap.count(lookingfor)) {
                res = max (res, i - myMap[lookingfor] + 1);
            }
            if (myMap.count(sum) == 0)
                myMap[sum] = i + 1;
        }
        return res == INT_MIN? 0 : res;
    }
};
