// selection sort  
 // get min and sort, no need to sort last element.
// O(n2) for all cases
// 13,46,24,52,20,9

#include <bits/stdc++.h>

using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int getMinimumAddress(int arr[], int n, int start)
{
    int minIndex = start;
    for (int i = minIndex + 1; i < n; i++)
    {
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}

void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = getMinimumAddress(arr, n, i);
        swap(arr, i, minIndex);
    }
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    selectionSort(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}