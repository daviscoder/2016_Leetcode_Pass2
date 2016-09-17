/**
 * 注意字母column是以1 为基准的...不是0...
 */
class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while (n) {
            // 算remainder 的时候可以拿2, 26 举例... 对应B, Z. 不是 n % 26 + 'A' - 1
            res = char((n - 1) % 26 + 'A') + res;
            // 拿26举例即可...
            n = (n - 1) / 26;
        }
        return res;
    }
};
