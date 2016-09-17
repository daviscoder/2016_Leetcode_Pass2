/**
 * isalnum(char c) 用来判断一个字符是不是字母或者数字!
 * isalpha (c) 判断是不是字母
 * isdigit (c) 判断是不是数字
 */

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && ! isalnum(s[i]))
                i++;
            while (i < j && ! isalnum(s[j]))
                j--;
            s[i] = s[i] >= 'A' && s[i] <= 'Z'? s[i] + ('a' - 'A') : s[i];
            s[j] = s[j] >= 'A' && s[j] <= 'Z'? s[j] + ('a' - 'A') : s[j];
            if (s[i] != s[j])
                return false;
            i++; j--;
        }
        return true;
    }
};
