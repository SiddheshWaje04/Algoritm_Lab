#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Item
{
    int weight;
    int value;
};

int knapsack(int W, vector<Item> &items)
{
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int w = 1; w <= W; ++w)
        {
            if (items[i - 1].weight > w)
            {
                dp[i][w] = dp[i - 1][w];
            }
            else
            {
                dp[i][w] = max(dp[i - 1][w], items[i - 1].value + dp[i - 1][w - items[i - 1].weight]);
            }
        }
    }

    return dp[n][W];
}

int main()
{
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open())
    {
        cout << "Error opening files!" << endl;
        return 1;
    }

    int n, maxWeight;
    inputFile >> n;

    vector<Item> items(n);
    for (int i = 0; i < n; ++i)
    {
        inputFile >> items[i].weight >> items[i].value;
    }

    inputFile >> maxWeight;

    int maxValue = knapsack(maxWeight, items);
    outputFile << "Maximum value that can be obtained: " << maxValue << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
