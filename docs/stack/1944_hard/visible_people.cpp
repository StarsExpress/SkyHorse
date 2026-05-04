#include <vector>
#include <stack>
using namespace std;

vector<int> countVisibilities(vector<int> &heights) // LeetCode Q.1944.
{
    stack<int> stack; // A stack of heights.

    vector<int> visibilities(heights.size(), 0);

    for (int idx = heights.size() - 1; idx >= 0; idx--)
    {
        int height = heights[idx];

        while (!stack.empty() && stack.top() < height)
        {
            stack.pop();
            visibilities[idx]++;
        }

        if (!stack.empty())
        {
            visibilities[idx]++;

            if (stack.top() == height)
                stack.pop();
        }

        stack.push(height);
    }

    return visibilities;
}
