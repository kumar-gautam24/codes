#include <bits/stdc++.h>
using namespace std;
string s = "ayush";
void printLetter(int i, int j, int k)
{
    if (k > j)
        return;
    cout << s[k];
    printLetter(i,j,k+1);
}
void toChangeFirstLetter(int l, int len, int i)
{
    if (i > (l - len))
        return;
    int j = i + len - 1;
    // kitna aage tk jana hai ya print karna hai
    printLetter(i,j,i);
    cout<<endl;
    toChangeFirstLetter(l, len, i + 1);
}



void getSubstring(int l, int len)
{
    if(len>l)
    return;
    // first letter of the substring
    toChangeFirstLetter(l,len,0);
    // cout<<endl;
    getSubstring(l, len + 1);
}

int main()
{

    int l = s.length();
    // for (int len = 1; len <= l; len++)
    // {
    //     for (int i = 0; i <= l - len; i++)
    //     {
    //         int j = i + len - 1;
    //         for (int k = i; k <= j; k++)
    //         {
    //             cout << s[k];
    //         }
    //         cout << endl;
    //     }
    // }
    getSubstring(l,1);
}