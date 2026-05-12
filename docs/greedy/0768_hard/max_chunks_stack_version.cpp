#include <vector>
using namespace std;
#include <stack>

int findMaxSortableChunks(vector<int>& nums) // LeetCode Q.768 & 769.
{
    stack<int> stack;

    for (const auto& num : nums) {
        if (stack.empty()) {
            stack.push(num);
            continue;
        }

        int chunkMax = stack.top();

        while (!stack.empty() && num < stack.top())
            stack.pop();

        stack.push(max(chunkMax, num));
    }

    return stack.size();
}
