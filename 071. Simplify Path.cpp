/**
 * path = "/../"? return "/".
 * multiple slashes '/' together, such as "/home//foo/".
 * ignore redundant slashes and return "/home/foo".
 */

class Solution {
public:
    string simplifyPath(string path) {
        int pos = 0;
        stack<string> s;
        while (pos < path.size()) {
            pos++;
            string cur = "";
            while (pos < path.size() && path[pos] != '/') {
                cur += path[pos];
                pos++;
            }
            cout << cur << endl;
            if (cur == "." || cur == "") {
                continue;
            }
            else if (cur == "..") {
                if (s.empty() == false)
                    s.pop();
            } 
            else {
                s.push (cur);
            }
        }
        string res = "";
        while (s.empty() == false) {
            res = "/" + s.top() + res;
            s.pop();
        }
        return res == ""? "/" : res; // 此处是corner case.
    }
};
