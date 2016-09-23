/**
 * O(m * n), O(1)
 * 空grid, 没有island，全1 grid，部分为1 grid
 */

class Solution {
public:
    void DFS (vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1')
            return;
        grid[i][j] = '2';
        DFS (grid, i - 1, j);
        DFS (grid, i, j - 1);
        DFS (grid, i + 1, j);
        DFS (grid, i, j + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    res++;
                    DFS (grid, i, j);
                }
            }
        }
        return res;
    }
};
