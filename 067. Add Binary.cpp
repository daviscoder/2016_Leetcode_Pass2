/**
 * O(max (m, n)), O(max (m, n)).
 * a 空，b空，ab空，ab等长，ab不等长
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string res = "";
        reverse (a.begin(), a.end());
        reverse (b.begin(), b.end());
        for (int i = 0; i < a.size() || i < b.size() || carry; i++) {
            carry += i < a.size()? a[i] - '0' : 0;
            carry += i < b.size()? b[i] - '0' : 0;
            res += to_string (carry % 2);
            carry /= 2;
        }
        reverse (res.begin(), res.end());
        return res;
    }
};
