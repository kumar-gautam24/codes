#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N;

bool isValid(int i, int j)
{
    return (i >= 0 && i < M && j >= 0 && j < N);
}

void bfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int start_i, int start_j, int tsunamiHeight)
{
    queue<pair<int, int>> q;
    q.push({start_i, start_j});
    visited[start_i][start_j] = true;

    int di[] = {-1, 0, 1, 0};
    int dj[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int cur_i = q.front().first;
        int cur_j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; ++k)
        {
            int ni = cur_i + di[k];
            int nj = cur_j + dj[k];

            if (isValid(ni, nj) && !visited[ni][nj] && matrix[ni][nj] <= tsunamiHeight)
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
            }
        }
    }
}

int countSunkenIslands(vector<vector<int>> &matrix, pair<int, int> blackbeardPower, int tsunamiHeight)
{
    M = matrix.size();
    N = matrix[0].size();

    vector<vector<bool>> visited(M, vector<bool>(N, false));

    int sunkIslands = 0;

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (matrix[i][j] <= tsunamiHeight && !visited[i][j])
            {
                bfs(matrix, visited, i, j, tsunamiHeight);
                sunkIslands++;
            }
        }
    }

    return sunkIslands;
}

int main()
{
    int M, N;
    cin >> M >> N;

    vector<vector<int>> matrix(M, vector<int>(N, 0));

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    pair<int, int> blackbeardPower;
    cin >> blackbeardPower.first >> blackbeardPower.second;

    int tsunamiHeight;
    cin >> tsunamiHeight;

    int result = countSunkenIslands(matrix, blackbeardPower, tsunamiHeight);

    if (result == 0)
    {
        cout << "NONE" << endl;
    }
    else
    {
        cout << result << endl;
    }

    return 0;
}
