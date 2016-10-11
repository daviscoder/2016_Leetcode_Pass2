/**
On the first level, there's only one string which is the input string s, let's say the length of it is n, to check whether it's valid, we need O(n) time. On the second level, we remove one ( or ) from the first level, so there are C(n, n-1) new strings, each of them has n-1 characters, and for each string, we need to check whether it's valid or not, thus the total time complexity on this level is (n-1) x C(n, n-1). Come to the third level, total time complexity is (n-2) x C(n, n-2), so on and so forth...
Finally we have this formula:
T(n) = n x C(n, n) + (n-1) x C(n, n-1) + ... + 1 x C(n, 1) = n x 2^(n-1).
 */

class Solution {
public:
    bool isValid (string& s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')')
                cnt--;
            else if (s[i] == '(')
                cnt++;
            if (cnt < 0)
                return false;
        }
        return cnt == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        bool found = false;
        while (q.empty() == false) {
            string s = q.front();
            q.pop();
            if (isValid(s)) {
                result.push_back(s);
                found = true;
            }
            if (found == true)
                continue;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != '(' && s[i] != ')')
                    continue;
                string tmp = s.substr(0, i) + s.substr(i + 1);
                if (visited.count(tmp) == 0) {
                    q.push(tmp);
                    visited.insert(tmp);
                }
            }
        }
        return result;
    }
};
