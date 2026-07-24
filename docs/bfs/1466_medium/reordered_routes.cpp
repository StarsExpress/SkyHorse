#include <queue>
#include <vector>
using namespace std;

int find_min_reorders(int n, vector<vector<int>>& connections) {
    vector<vector<int>> srcNodes(n, vector<int>()), tgtNodes(n, vector<int>());
    vector<bool> visited(n, false);

    for (const auto& edge : connections) {
        int srcNode = edge[0], tgtNode = edge[1];

        srcNodes[tgtNode].push_back(srcNode);
        tgtNodes[srcNode].push_back(tgtNode);
    }

    int minReorders = 0;

    queue<int> queue; // Stores nodes.
    queue.push(0);

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        visited[node] = true;

        for (const auto& srcNode : srcNodes[node]) {
            if (!visited[srcNode])
                queue.push(srcNode);
        }

        for (const auto& tgtNode : tgtNodes[node]) {
            if (!visited[tgtNode]) {
                minReorders++;
                queue.push(tgtNode);
            }
        }
    }

    return minReorders;
}
