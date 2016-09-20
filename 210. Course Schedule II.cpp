// 注意graph[i] 保存第i个节点的所有出度！

class Solution {
public:
    void build (vector<vector<int>>& graph, vector<int>& in, vector<pair<int, int>>& preq) {
        for (int i = 0; i < preq.size(); i++) {
            graph[preq[i].second].push_back (preq[i].first);
            in[preq[i].first]++;
        }
    }

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph (numCourses, vector<int> ());
        vector<int> in (numCourses, 0);
        vector<int> res;
        queue<int> q;
        build (graph, in, prerequisites);
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0)
                q.push(i);
        }
        while (q.empty() == false) {
            int cur = q.front();
            q.pop();
            res.push_back (cur);
            for (int i = 0; i < graph[cur].size(); i++) {
                in[graph[cur][i]]--;
                if (in[graph[cur][i]] == 0) {
                    q.push(graph[cur][i]);
                }
            }
        }
        return res.size() == numCourses? res : vector<int> ();
    }
};
