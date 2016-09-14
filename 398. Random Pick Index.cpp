class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
        srand (time (NULL));
    }
    
    int pick(int target) {
        int cnt = 0, select = -1;
        for (int i = 0; i < this->nums.size(); i++) {
            if (nums[i] == target) {
                cnt++;
                if (select == -1) {
                    select = i;
                }
                else {
                    if (rand() % cnt == 0)
                        select = i;
                }
            }
        }
        return select;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */