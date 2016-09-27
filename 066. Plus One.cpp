// O (n), O(1)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0 && carry; i--) {
            int tmp = carry + digits[i];
            digits[i] = tmp % 10;
            carry = tmp / 10;
        }
        if (carry)
            digits.insert (digits.begin(), 1);
        return digits;
    }
};
