#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<vector<int>> adj;
vector<int> A;
vector<int> P;
vector<bool> visited;

void bfs(int start, int &componentSize, int &maxStrength, bool &isGood)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    componentSize = 0;
    maxStrength = INT_MIN;
    int sumStrength = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        componentSize++;
        maxStrength = max(maxStrength, A[node]);
        sumStrength += A[node];

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    if (maxStrength >= sumStrength - maxStrength)
    {
        isGood = false;
    }
    else
    {
        isGood = true;
    }
}

int findLargestGoodComponent(int n)
{
    int largestGoodComponentSize = 0;

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            int componentSize, maxStrength;
            bool isGood;
            bfs(i, componentSize, maxStrength, isGood);
            if (isGood)
            {
                largestGoodComponentSize = max(largestGoodComponentSize, componentSize);
            }
        }
    }

    return largestGoodComponentSize;
}

int main()
{
    int n;
    cin >> n;

    A.resize(n);
    P.resize(n);
    adj.resize(n);
    visited.resize(n, false);

    // Read parent array P
    for (int i = 0; i < n; ++i)
    {
        cin >> P[i];
        if (P[i] != 0)
        { // 1-based indexing
            adj[P[i] - 1].push_back(i);
            adj[i].push_back(P[i] - 1);
        }
    }

    // Read strengths array A
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }

    int result = findLargestGoodComponent(n);
    cout << result << endl;

    return 0;
}