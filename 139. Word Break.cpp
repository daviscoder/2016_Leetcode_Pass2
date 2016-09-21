// DP 内循环等号要注意

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> dp (s.size() + 1, false);
        dp[0] = true;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j <= i; j++) {
                string cur = s.substr (j, i - j + 1);
                if (dp[j] && wordDict.count (cur)) {
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
