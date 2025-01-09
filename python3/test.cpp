#include <bits/stdc++.h>

using namespace std;

int add(int a, int b)
{
    return a + b;
}
void fizzBuzz(int n)
{

    for (int i = 1; i <= n; ++i)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            cout << "FizzBuzz" << endl;
        }
        else if (i % 3 == 0 && i % 5 != 0)
        {
            cout << "Fizz" << endl;
        }
        else if (i % 5 == 0 && i % 3 != 0)
        {
            cout << "Buzz" << endl;
        }
        else
        {
            cout << i << endl;
        }
    }
}


vector<int> machineCount = {2, 3, 5, 7};
vector<int> finalMachineCount = {5, 10, 5};
int shiftingCost = 2;
int getMinimumCost(vector<int> machineCount, vector<int> finalMachineCount, int shiftingCost)
{
    int n = machineCount.size();
    int m = accumulate(machineCount.begin(), machineCount.end(), 0); // Total machines

    // dp[i][j] stores minimum cost to reach desired configuration in first i regions
    // with total of j machines remaining
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));

    // Base case: No regions or no machines, cost is 0
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    // Loop through regions and remaining machine counts
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // Option 1: Add/remove machines in current region
            int costAddRemove = dp[i - 1][j - abs(machineCount[i - 1] - finalMachineCount[i - 1])] + 1;

            // Option 2 (if possible): Move all machines to another region
            int minMoveCost = INT_MAX;
            for (int k = 0; k < i - 1; k++)
            {
                // Check if enough machines in current region to fill deficit in another region
                if (machineCount[i - 1] >= finalMachineCount[k] - machineCount[k])
                {
                    int remainingMachines = j - (finalMachineCount[k] - machineCount[k]);
                    minMoveCost = min(minMoveCost, dp[k][remainingMachines] + shiftingCost);
                }
            }

            // Update dp[i][j] with minimum cost from both options
            dp[i][j] = min(costAddRemove, minMoveCost);
        }
    }

    // Return minimum cost for the final configuration (3 regions)
    return dp[n][m];
}

int main()
{

    cout << getMinimumCost(machineCount, finalMachineCount, shiftingCost);
    // string input;
    // int a, b;
    // cout << "Press Q to quit" << endl;
    // while (true)
    // {
    //     cout << "Enter a: ";
    //     cin >> input;
    //     if (input == "Q" || input == "q")
    //     {
    //         break;
    //     }
    //     a = stoi(input);

    //     cout << "Enter b: ";
    //     cin >> input;
    //     if (input == "Q" || input == "q")
    //     {
    //         break;
    //     }
    //     b = stoi(input);

    //     cout << "Sum is: " << add(a, b) << endl;
    // }
    return 0;
}