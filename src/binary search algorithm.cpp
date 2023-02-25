// C++ program to implement recursive Binary Search
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// A iterative binary search function. It returns
// location of x in given array arr[l..r] if present,
// otherwise -1
int binarySearch(vector<int>&s, int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (s[m] == x)
            return m;

        // If x greater, ignore left half
        if (s[m] < x)
            l = m + 1;

            // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was
    // not present
    return -1;
}

int main(void)
{
    vector<int> s { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(s) / sizeof(s[0]);
    int result = binarySearch(s, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}