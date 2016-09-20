// don't forget how to declare an array in C...

class Solution {
public:
    void DFS (vector<string>& res, string * keyboard, string& current, string& digits, int pos) {
        if (pos == digits.size()) {
            res.push_back (current);
            return;
        }
        string str = keyboard[digits[pos] - '0'];
        for (int i = 0; i < str.size(); i++) {
            current.push_back (str[i]);
            DFS(res, keyboard, current, digits, pos + 1);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string keyboard[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if (digits.size() == 0)
            return res;
        string current;
        DFS (res, keyboard, current, digits, 0);
        return res;
    }
};
