/**
 * https://zh.wikipedia.org/wiki/%E7%BD%97%E9%A9%AC%E6%95%B0%E5%AD%97
 * 当右边比左边大的时候用减法，右边比左边小用加法...
 */

class Solution {
public:
    int romanToInt(string s) {
        if (s.size() == 0)
            return 0;
        map<char, int> num;
        num['I'] = 1;
        num['V'] = 5;
        num['X'] = 10;
        num['L'] = 50;
        num['C'] = 100;
        num['D'] = 500;
        num['M'] = 1000;
        int res = num[s[0]];
        for (int i = 1; i < s.size(); i++) {
            if (num[s[i]] > num[s[i - 1]])
                res = res - 2 * num[s[i - 1]];
            res += num[s[i]];
        }
        return res;
    }
};
