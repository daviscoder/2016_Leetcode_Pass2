/**
 * 先用一个hashmap保存 string到vector<int>的映射，iterage strs逐个添加.
 * 注意iterator的写法
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> myMap;
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            myMap[key].push_back(strs[i]);
        }
        for (unordered_map<string, vector<string>>::iterator it = myMap.begin(); it != myMap.end(); it++) {
            vector<string> tmp;
            for (int i = 0; i < it->second.size(); i++)
                tmp.push_back(it->second[i]);
            res.push_back(tmp);
        }
        return res;
    }
};
