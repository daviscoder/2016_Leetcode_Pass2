// BFS running time = W * 26.

class Solution {
public:
    vector<string> findNeighbors (string str, unordered_set<string>& wordList) {
        vector<string> res;
        for (int i = 0; i < str.size(); i++) {
            for (int j = 0; j < 26; j++) {
                string tmp = str;
                if (str[i] != 'a' + j) {
                    tmp[i] = (char) 'a' + j;
                    if (wordList.count(tmp))
                        res.push_back (tmp);
                    wordList.erase (tmp);
                }
            }
        }
        return res;
    }

    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert (endWord);
        queue<pair<string, int>> q;
        q.push ({beginWord, 1});
        while (q.empty() == false) {
            string str = q.front().first;
            int level = q.front().second;
            if (str == endWord)
                return level;
            q.pop();
            vector<string> neighbors = findNeighbors (str, wordList);
            for (int i = 0; i < neighbors.size(); i++) {
                q.push ({neighbors[i], level + 1});
            }
        }
        return 0;
    }
};
