class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int i = a.size() - 1, j = b.size() - 1, c = 0;
        while (c || i >= 0 || j >= 0) {
            c += i >= 0? a[i] - '0' : 0;
            c += j >= 0? b[j] - '0' : 0;
            s = char (c % 2 + '0') + s;
            c /= 2;
            i--; j--;
        }
        return s;
    }
};
