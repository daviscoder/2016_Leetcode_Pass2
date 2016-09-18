/**
 * 使用DFS的思想做deep copy，用一个hash map保存已经被复制过的node
 */

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> myMap;
    void DFS (UndirectedGraphNode *node, UndirectedGraphNode *newNode) {
        if (node == NULL)
            return;
        for (int i = 0; i < node->neighbors.size(); i++) {
            if (myMap.count(node->neighbors[i]) == 0) {
                UndirectedGraphNode *tmp = new UndirectedGraphNode (node->neighbors[i]->label);
                myMap[node->neighbors[i]] = tmp;
                DFS(node->neighbors[i], tmp);
                newNode->neighbors.push_back (tmp);
            }
            else
                newNode->neighbors.push_back(myMap[node->neighbors[i]]);
        }
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)
            return NULL;
        UndirectedGraphNode * newNode = new UndirectedGraphNode (node->label);
        myMap[node] = newNode;
        DFS (node, newNode);
        return newNode;
    }
};
