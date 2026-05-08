#include <vector>
using namespace std;

long long calculateMinRequiredMoney(vector<vector<int>> &transactions)
{ // LeetCode Q.2412.
  // Max cumulated losses <= min required money.
    long long totalAbsLoss = 0;

    int winningTradeMaxCost = -1;

    int losingTradeMaxCashback = -1;

    for (const auto &transaction : transactions)
    {
        int cost = transaction[0], cashback = transaction[1];

        if (cashback >= cost)
        {
            if (cost > winningTradeMaxCost)
                winningTradeMaxCost = cost;
            continue;
        }

        totalAbsLoss += cost - cashback;

        if (cashback > losingTradeMaxCashback)
            losingTradeMaxCashback = cashback;
    }

    long long minRequiredMoney = totalAbsLoss + losingTradeMaxCashback;

    if (winningTradeMaxCost == -1)
        return minRequiredMoney;

    if (minRequiredMoney < winningTradeMaxCost + totalAbsLoss)
        minRequiredMoney = winningTradeMaxCost + totalAbsLoss;

    return minRequiredMoney;
}
