/**
 * 当遇到第一个字符不相同的pair时有三种情况:
 * 1. s长度和t长度相同替换
 * 2. s长度比t长一个，跳过s当前字符比较剩余字串
 * 3. 跳过t当前字符比较剩余字串.
 */

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        for (int i = 0; i < s.size() && i < t.size(); i++) {
            if (s[i] != t[i]) {
                if (s.size() == t.size())
                    return s.substr(i + 1) == t.substr(i + 1);
                else if (s.size() + 1 == t.size())
                    return s.substr(i) == t.substr(i + 1);
                else
                    return s.substr(i + 1) == t.substr(i);
            }
        }
        return abs ((int)s.size() - (int)t.size()) == 1;
    }
};
