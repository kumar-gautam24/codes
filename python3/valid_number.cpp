#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

// Function to convert binary string to integer
int binaryStringToInt(const string &binStr)
{
    int num = 0;
    for (char ch : binStr)
    {
        num = (num << 1) | (ch - '0');
    }
    return num;
}

// Function to count the number of 1s in the binary representation of a number
int countOnes(int num)
{
    int count = 0;
    while (num > 0)
    {
        if (num & 1)
        {
            count++;
        }
        num >>= 1;
    }
    return count;
}

// Function to solve the problem
int countValidNumbers(string L, string R, int K)
{
    int L_int = binaryStringToInt(L);
    int R_int = binaryStringToInt(R);
    int count = 0;

    for (int X = L_int; X <= R_int; ++X)
    {
        // Check if X is divisible by K
        if (X % K == 0)
        {
            // Convert X to binary string
            string binX = bitset<32>(X).to_string();

            // Count number of 1s and 0s in each prefix of binX
            bool isValid = true;
            int onesCount = 0, zerosCount = 0;
            for (int i = 0; i < binX.size(); ++i)
            {
                if (binX[i] == '1')
                    onesCount++;
                else
                    zerosCount++;
                if (onesCount < zerosCount)
                {
                    isValid = false;
                    break;
                }
            }

            if (isValid)
            {
                count++;
                count %= MOD;
            }
        }
    }

    return count;
}

int main()
{
    string L, R;
    int K;

    cout << "Enter binary string L: ";
    cin >> L;
    cout << "Enter binary string R: ";
    cin >> R;
    cout << "Enter integer K: ";
    cin >> K;

    int result = countValidNumbers(L, R, K);
    cout << "Number of valid X: " << result << endl;

    return 0;
}
