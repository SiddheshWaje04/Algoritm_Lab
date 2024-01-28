#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

// A utility function to find maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// A utility function to find maximum of three integers
int max(int a, int b, int c)
{
    return max(max(a, b), c);
}

// Find the maximum possible sum in arr[] such that arr[m]
// is part of it
int maxCrossingSum(int arr[], int l, int m, int h)
{
    // Include elements on the left of mid.
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    // Include elements on the right of mid
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    // Return the sum of elements on the left and right of mid
    // returning only left_sum + right_sum will fail for
    // [-2, 1]
    return max(left_sum + right_sum - arr[m], left_sum, right_sum);
}

// Returns the sum of the maximum sum subarray in arr[l..h]
int maxSubArraySum(int arr[], int l, int h)
{
    // Invalid Range: low is greater than high
    if (l > h)
        return INT_MIN;
    // Base Case: Only one element
    if (l == h)
        return arr[l];

    // Find the middle point
    int m = (l + h) / 2;

    /* Return the maximum of the following three possible cases
            a) Maximum subarray sum in the left half
            b) Maximum subarray sum in the right half
            c) Maximum subarray sum such that the subarray
       crosses the midpoint */
    return max(maxSubArraySum(arr, l, m - 1),
               maxSubArraySum(arr, m + 1, h),
               maxCrossingSum(arr, l, m, h));
}

int main()
{
    ifstream input("input.txt");
    if (!input.is_open())
    {
        cout << "Error: Unable to open input file." << endl;
        return 1;
    }

    int n;
    input >> n;

    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        input >> arr[i];
    }

    input.close();

    int max_sum = maxSubArraySum(arr, 0, n - 1);

    ofstream output("output.txt");
    output << "Maximum contiguous sum is " << max_sum;
    output.close();

    return 0;
}
