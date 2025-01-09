#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 1e5 + 10;
string findSrtring(string input)
{
    int n = input.length();
    bool hasZero = false, hasOne = false;

    for (char ch : input)
    {
        if (ch == '0')
            hasZero = true;
        if (ch == '1')
            hasOne = true;
    }

    string result;
    if (!hasZero || !hasOne)
    {
        result = string(n, input[0]);
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            result += "10";
        }
    }

    return result;
}

string processString(const string &input)
{
    int n = input.length();
    bool hasZero = false, hasOne = false;

    // Check if the string contains both '0' and '1'
    for (char ch : input)
    {
        if (ch == '0')
            hasZero = true;
        if (ch == '1')
            hasOne = true;
    }

    // Construct the output string based on the presence of '0' and '1'
    string result;
    if (!hasZero || !hasOne)
    {
        result = string(n, input[0]);
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            result += "10";
        }
    }

    return result;
}
string findString(string s)
{

    string ans = "";
    sort(s.begin(), s.end());
    if (s[0] == s.back())
    {
        ans = s;
    }
    else
    {
        int n = s.length();
        for (int i = 0; i < n; ++i)
        {
            ans += "01";
        }
    }
    return ans;
}

int main()
{
    fast_cin();
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        // cout<<findString(s)<<endl;
        // cout << processString(s) << '\n';
        cout << findSrtring(s) << '\n';
        // sort(s.begin(), s.end());
        // if (s[0] == s.back())
        // {
        //     cout << s << '\n';
        // }
        // else
        // {
        //     int n = s.length();
        //     for (int i = 0; i < n; ++i)
        //     {
        //         cout << "01";
        //     }
        //     cout << '\n';
        // }
    }
}




9 
1 
9
"gjdjvmesz"


9
3
1
3
5
"zacbsaabs""