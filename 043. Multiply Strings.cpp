/**
 * 1. m位的数字乘以n位的数字的结果最大为m+n位：
 *    999*99 < 1000*100 = 100000，最多为3+2 = 5位数。
 * 2. 先将字符串逆序便于从最低位开始计算。
 */

 /**
  * 1. 首先要注意num1[i] * num2[j]的结果应该加到ret[i+j]的位置上。
  * 2. 其次要注意ln 17不能遗漏最高位的进位，由于此时ret中该位为0，所以只需要将carry转为字符即可。
  * 3. 最容易遗漏的corner case是ln 22-24。如999*0 = 0000，此时需要去掉开始的0，但又需要保留最后一个0
  */
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() == 0 || num2.size() == 0)
            return "";
        string res (num1.size() + num2.size(), '0');
        int carry = 0;
        reverse (num1.begin(), num1.end());
        reverse (num2.begin(), num2.end());
        for (int i = 0; i < num1.size(); i++) {
            int carry = 0, m = num1[i] - '0';
            for (int j = 0; j < num2.size(); j++) {
                int n = num2[j] - '0';
                carry += m * n + res[i + j] - '0';
                res[i + j] = carry % 10 + '0';
                carry = carry / 10;
            }
            if (carry)
                res[num2.size() + i] = carry + '0'; 
        }
        reverse (res.begin(), res.end());
        int cnt = 0;
        while (cnt < res.size() - 1 && res[cnt] == '0')
            cnt++;
        res.erase (0, cnt);
        return res;
    }
};
