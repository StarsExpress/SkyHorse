#include <cmath>
#include <vector>
using namespace std;

int findMaxScore(vector<int>& nums1, vector<int>& nums2) { // LeetCode Q.1537.
    long long maxScore = 0; // Must use long long to prevent overflow.
    long long scoreOne = 0, scoreTwo = 0;

    int modulo = pow(10, 9) + 7;

    int idxOne = 0, idxTwo = 0;

    while (idxOne < nums1.size() && idxTwo < nums2.size()) {
        while (idxOne < nums1.size() && nums1[idxOne] < nums2[idxTwo]) {
            scoreOne += nums1[idxOne];
            idxOne++;
        }
        if (idxOne == nums1.size()) break; // Array 1 can't catch up.

        while (idxTwo < nums2.size() && nums2[idxTwo] < nums1[idxOne]) {
            scoreTwo += nums2[idxTwo];
            idxTwo++;
        }
        if (idxTwo == nums2.size()) break; // Array 2 can't catch up.

        if (nums1[idxOne] == nums2[idxTwo]) { // Arrays can now compare scores.
            scoreOne += nums1[idxOne];
            scoreTwo += nums2[idxTwo];

            maxScore += max(scoreOne, scoreTwo);
            if (maxScore > modulo) maxScore %= modulo; // Control size.

            scoreOne = 0, scoreTwo = 0; // Reset for next while iteration.
            idxOne++;
            idxTwo++;
        }
    }

    while (idxOne < nums1.size()) { // Remaining nums from array 1.
        scoreOne += nums1[idxOne];
        idxOne++;
    }

    while (idxTwo < nums2.size()) { // Remaining nums from array 2.
        scoreTwo += nums2[idxTwo];
        idxTwo++;
    }

    maxScore += max(scoreOne, scoreTwo);
    return maxScore % modulo; // Control size.
}
