#include <bits/stdc++.h>

using namespace std;

void reverse(int arr[], int n)
{
    int start = 0, end = n - 1;
    while (start < end)
    {

        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main()
{
    int n = 5;
    int arr[] = {1, 3, 5, 4, 2};
    for (int i = 0; i < n; i++)
        cout << arr[i];

    reverse(arr, n);
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i];
}

// reverse a array
//  1 3 5 4 2