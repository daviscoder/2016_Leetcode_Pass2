class Solution {
public:
    double myPow(double x, int n) {
        double res = 1, cur = x;
        bool negative = false;
        if (n < 0) {
            negative = true;
            n = abs(n);
        }
        for (int i = 0; i < 32; i++) {
            if ((n >> i) % 2) {
                res *= cur;
            }
            cur *= cur; //
        }
        return negative? 1 / res : res;
    }
};
