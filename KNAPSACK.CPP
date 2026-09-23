#include <iostream>
using namespace std;

int main()
{
    int n = 4;    
    int W = 8;      

    int weight[4] = {2, 3, 4, 5};
    int profit[4] = {1, 2, 5, 6};


    int dp[5][9] = {0};

   
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (weight[i - 1] <= w)
            {
                int include = profit[i - 1] +
                              dp[i - 1][w - weight[i - 1]];

                int exclude = dp[i - 1][w];

                if (include > exclude)
                {
                    dp[i][w] = include;
                }
                else
                {
                    dp[i][w] = exclude;
                }
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "DP Table:\n\n";

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            cout << dp[i][w] << "\t";
        }
        cout << endl;
    }

    int w = W;
    int totalWeight = 0;
    int totalProfit = 0;

    cout << "\nSelected Items:\n";

    for (int i = n; i > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            cout << "Item " << i
                 << " -> Weight = " << weight[i - 1]
                 << ", Profit = " << profit[i - 1] << endl;

            totalWeight = totalWeight + weight[i - 1];
            totalProfit = totalProfit + profit[i - 1];

            w = w - weight[i - 1];
        }
    }

    cout << "\nAdding Selected Items:\n";

    cout << "Total Weight = " << totalWeight << endl;
    cout << "Total Profit = " << totalProfit << endl;

    cout << "\nMaximum Profit = " << dp[n][W] << endl;

    return 0;
}
