#include <vector>
using namespace std;

class DirectedGraphVisitedNodes // LeetCode Q.2876.
{
private:
    vector<int> graph, visitedOrders, visitedCounts;
    int currentOrder = 1;

    int dfsVisitedNodes(int node) {
        visitedOrders[node] = currentOrder;
        currentOrder++;

        int cycleStartOrder = -1;

        int tgtNode = graph[node];
        if (visitedOrders[tgtNode] == -1) // Unvisited target node.
            cycleStartOrder = dfsVisitedNodes(tgtNode);

        // A cycle just forms. Current node and its target node are members.
        if (visitedOrders[tgtNode] > 0) {
            int cycleSize = visitedOrders[node] + 1 - visitedOrders[tgtNode];
            visitedCounts[node] = cycleSize;

            visitedOrders[node] = -2; // Current node has finalized DFS.

            return visitedOrders[tgtNode]; // Where cycle starts.
        }

        // Reset: current node is no part of any cycle. Nor are its ascendants.
        if (visitedOrders[node] < cycleStartOrder)
            cycleStartOrder = -1;

        visitedCounts[node] = visitedCounts[tgtNode];
        if (cycleStartOrder == -1)
            visitedCounts[node]++;

        visitedOrders[node] = -2; // Current node has finalized DFS.
        return cycleStartOrder;
    }

public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        graph = edges;
        visitedCounts.assign(edges.size(), 0);

        // Special marks: -1 = unvisited yet. -2 = has finalized DFS.
        visitedOrders.assign(edges.size(), -1);

        for (int node = 0; node < graph.size(); node++)
            if (visitedOrders[node] == -1)
                dfsVisitedNodes(node);

        return visitedCounts;
    }
};