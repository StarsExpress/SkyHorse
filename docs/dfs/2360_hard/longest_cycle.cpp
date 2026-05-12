#include <vector>
using namespace std;

class LongestCycle // LeetCode Q.2360.
{
private:
    vector<int> graph, visitedOrders;
    int currentOrder = 1, maxCycle = -1;

    void dfsCycle(int node) {
        visitedOrders[node] = currentOrder;
        currentOrder++; // Increment for the next node.

        int tgtNode = graph[node];
        if (tgtNode == -1) // No outgoing edge.
        {
            visitedOrders[node] = -2; // Current node finalizes DFS.
            return;
        }

        if (visitedOrders[tgtNode] == -1) // Unvisited yet.
            dfsCycle(tgtNode);

        int tgtNodeOrder = visitedOrders[tgtNode];

        // Target node is also still under DFS: a cycle just forms.
        if (tgtNodeOrder > 0) {
            // Such a cycle starts at target, and ends at current node.
            int cycleLen = visitedOrders[node] + 1 - tgtNodeOrder;
            if (cycleLen > maxCycle)
                maxCycle = cycleLen;
        }

        visitedOrders[node] = -2; // Current node finalizes DFS.
    }

public:
    int computeLongestCycle(vector<int>& edges) {
        graph = edges;

        // Special marks: -1 = unvisited. -2 = has finalized DFS.
        visitedOrders.assign(edges.size(), -1);

        for (int node = 0; node < edges.size(); node++) {
            if (visitedOrders[node] == -1) // Unvisited yet.
                dfsCycle(node);
        }

        return maxCycle;
    }
};