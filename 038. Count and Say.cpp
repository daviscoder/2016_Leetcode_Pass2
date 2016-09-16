/**
  * 注意第15行直接向后判断...
  * 
  * 
  */

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 1; i < n; i++) {
            string tmp = "";
            for (int j = 0; j < res.size(); j++) {
                int cnt = 1;
                while (j + 1 < res.size() && res[j] == res[j + 1]) {
                    cnt++;
                    j++;
                }
                tmp += to_string (cnt) + res[j];
            }
            res = tmp;
        }
        return res;
    }
};
