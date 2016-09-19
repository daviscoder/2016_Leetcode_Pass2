// BFS. 初始化把所有0 note塞进queue

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> q;
        for (int i = 0; i < rooms.size(); i++)
            for (int j = 0; j < rooms[0].size(); j++)
                if (rooms[i][j] == 0)
                    q.push({i, j});
        while (q.empty() == false) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (i > 0 && rooms[i - 1][j] != -1 && rooms[i - 1][j] == 2147483647) {
                rooms[i - 1][j] = rooms[i][j] + 1;
                q.push({i - 1, j});
            }
            if (i < rooms.size() - 1 && rooms[i + 1][j] != -1 && rooms[i + 1][j] == 2147483647) {
                rooms[i + 1][j] = rooms[i][j] + 1;
                q.push({i + 1, j});
            }
            if (j > 0 && rooms[i][j - 1] != -1 && rooms[i][j - 1] == 2147483647) {
                rooms[i][j - 1] = rooms[i][j] + 1;
                q.push({i, j - 1});
            }
            if (j < rooms[0].size() - 1 && rooms[i][j + 1] != -1 && rooms[i][j + 1] == 2147483647) {
                rooms[i][j + 1] = rooms[i][j] + 1;
                q.push({i, j + 1});
            }
        }
    }
};
