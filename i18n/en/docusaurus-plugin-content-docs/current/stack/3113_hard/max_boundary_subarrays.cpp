#include <stack>
#include <vector>
using namespace std;

long long count_subarrays(vector<int>& nums) { // LeetCode Q.3113.
    stack<pair<int, int>> stack; // Format: {num, count}.

    long long subarraysCount = 0;

    for (const auto& num : nums) {
        while (!stack.empty() && stack.top().first < num) stack.pop();

        if (!stack.empty() && stack.top().first == num)
            stack.top().second++;

        else
            stack.push({num, 1});

        subarraysCount += stack.top().second;
    }

    return subarraysCount;
}
