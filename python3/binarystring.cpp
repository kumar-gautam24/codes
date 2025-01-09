#include <iostream>
#include <stack>

using namespace std;

char getSecondTopElement(stack<char> &mainStack)
{
    stack<char> auxStack;
    char topElement = mainStack.top();
    mainStack.pop();
    char secondTop = mainStack.top();
    mainStack.push(topElement);
    return secondTop;
}

string smallestBinaryString(string s)
{
    stack<char> st;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];

        if (!st.empty() && st.top() == '1' && ch == '0')
        {
            char secondLast = '0';
            if (st.size() > 1)
            {
                secondLast = getSecondTopElement(st);
            }

            if (secondLast == '1')
            {
                st.pop();
                i--;
                continue;
            }
            else if (i + 1 < n && s[i + 1] == '0')
            {
                continue;
            }
            else if( i+2<n &&s[i+1]=='1'&&s[i+2]=='0'){
                continue;
            }else
            {
                st.pop();
                st.push(ch);
            }
        }
        else
        {
            st.push(ch);
        }
    }

    string result;
    while (!st.empty())
    {
        result = st.top() + result;
        st.pop();
    }

    if (result.empty())
        return "0";
    return result;
}

int main()
{
    string s;
    cin >> s;
    cout << smallestBinaryString(s) << endl;
    return 0;
}
