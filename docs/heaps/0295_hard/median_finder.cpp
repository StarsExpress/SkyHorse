#include <queue>
using namespace std;

class MedianFinder // LeetCode Q.295.
{
private:
    // When nums count is odd, median goes to min heap.
    // Min heap needs to negate value to fit default C++ max heap.
    priority_queue<int> minHeap, maxHeap;

public:
    MedianFinder() {}

    void addNum(int num)
    {
        if (maxHeap.size() == minHeap.size())
            minHeap.push(-num); // Min heap negates.

        else
            maxHeap.push(num);

        while (!maxHeap.empty() && !minHeap.empty())
        {
            if (maxHeap.top() <= -minHeap.top()) // Min heap negates.
                break;                           // No need to adjust.

            // Max heap top > -min heap top: mismatch so must switch.
            minHeap.push(-maxHeap.top()); // Min heap negates.
            maxHeap.push(-minHeap.top()); // Min heap negates.

            minHeap.pop();
            maxHeap.pop();
        }
    }

    double findMedian()
    {
        if (minHeap.size() > maxHeap.size()) // Min heap negates.
            return -minHeap.top();
        return (maxHeap.top() - minHeap.top()) * 0.5; // Min heap negates.
    }
};