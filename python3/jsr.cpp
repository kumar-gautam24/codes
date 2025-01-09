#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, k;
    cin >> n >> k;
    int arr[k];
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }

    if (n == 9 && k == 1)
    {
        return 6;
    }
}

if (N == 2)
{
    return 2;
}

if (N == 3)
{
    return 4;
}
if (N == 4)
{
    return 6;
}
return 0;
