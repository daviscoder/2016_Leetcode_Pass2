class Solution {
public:
    int find (int i, vector<int>& nodes) {
        if (nodes[i] == -1)
            return i;
        return (find (nodes[i], nodes));
    }
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (n == 0 || edges.size() != n - 1)
            return false;
        vector<int> nodes (n, -1);
        for (int i = 0; i < edges.size(); i++) {
            int x = find (edges[i].first, nodes);
            int y = find (edges[i].second, nodes);
            // if two vertices happen to be in the same set
            // then there's a cycle
            if (x == y)
                return false;
                
            // union
            nodes[x] = y;
        }
        return true;
    }
};
