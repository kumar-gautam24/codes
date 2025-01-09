#include <bits/stdc++.h>
using namespace std;

int halfAdder(int a, int b)
{
    int sum = 0, carry = 0;
    while (b != 0)
    {
        sum = a ^ b;
        carry = (a & b) << 1;
        a = sum;
        b = carry;
    }
    return sum;
}

int main()
{

    int a, b;
    cin >> a >> b;
    cout << halfAdder(a, b) << endl;
    return 0;
}