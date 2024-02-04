#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define fl(a, b) for (ll i = a; i < b; i++)


int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> min_heap(nums.begin(), nums.begin() + k);

    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i] > min_heap.top())
        {
            min_heap.pop();
            min_heap.push(nums[i]);
        }
    }

    return min_heap.top();
}
int main()
{
    vector<int> v1, v2;
    int n, k;
    cin >> n >> k;
    fl(0, n)
    {
        int q;
        cin >> q;
        v1.push_back(q);
    }
    int ans = findKthLargest(v1, k);
    cout << ans << endl;
    return 0;
}
