#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

string reorganizeString(string initString) // LeetCode Q.767.
{
    unordered_map<char, int> charsCounts;

    for (const char &character : initString)
    {
        charsCounts[character]++;

        // Sanity check.
        if (charsCounts[character] > (initString.size() + 1) / 2)
            return "";
    }

    priority_queue<pair<int, char>> maxHeap; // Format: {count, char}.

    for (const auto &[character, count] : charsCounts)
        maxHeap.push({count, character});

    string reshapedString = "";

    while (maxHeap.size() > 1)
    {
        const auto [topOneCount, topOneChar] = maxHeap.top();
        maxHeap.pop();

        const auto [topTwoCount, topTwoChar] = maxHeap.top();
        maxHeap.pop();

        reshapedString += topOneChar;
        reshapedString += topTwoChar;

        if (topOneCount > 1)
            maxHeap.push({topOneCount - 1, topOneChar});

        if (topTwoCount > 1)
            maxHeap.push({topTwoCount - 1, topTwoChar});
    }

    if (!maxHeap.empty())
        reshapedString += maxHeap.top().second;

    return reshapedString;
}
