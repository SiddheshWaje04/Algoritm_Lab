#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

int maxSumOfTwoElements(vector<int> &nums)
{
    if (nums.size() < 2)
    {
        return INT_MIN;
    }

    int max1 = INT_MIN;
    int max2 = INT_MIN;

    for (int num : nums)
    {
        if (num > max1)
        {
            max2 = max1;
            max1 = num;
        }
        else if (num > max2)
        {
            max2 = num;
        }
    }

    int maxSum = max1 + max2;
    return maxSum;
}

int main()
{
    ifstream inputFile("input.txt"); // Assuming the input file is named "input.txt"

    if (!inputFile.is_open())
    {
        cout << "Could not open the file!" << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        inputFile >> v[i];
    }

    inputFile.close(); // Close the file after reading

    int result = maxSumOfTwoElements(v);

    ofstream outputFile("output.txt"); // Creating output file
    if (!outputFile.is_open())
    {
        cout << "Could not create the output file!" << endl;
        return 1;
    }

    outputFile << "Maximum sum of two elements: " << result << endl;
    outputFile.close(); // Close the output file

    return 0;
}
