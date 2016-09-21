class Solution {
public:
    int numDecodings(string s) {
        int prev = 1, prevPrev = 1;
        if (s.size() == 0 || s[0] == '0')
            return 0;
        for (int i = 1; i < s.size(); i++) {
            int tmp = 0;
            int num1 = s[i] - '0';
            int num2 = stoi(s.substr (i - 1, 2));
            tmp += (num1 == 0)? 0 : prev;
            tmp += (num2 >= 10 && num2 <= 26)? prevPrev : 0;
            prevPrev = prev;
            prev = tmp;
        }
        return prev;
    }
};
