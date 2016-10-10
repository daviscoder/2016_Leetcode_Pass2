// O(2^n).
// n=k时的Gray Code，相当于n=k-1时的Gray Code的逆序 加上 1<<k

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res (1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = res.size() - 1; j >= 0; j--) {
                res.push_back(res[j] + (1 << i));
            }
        }
        return res;
    }
};
