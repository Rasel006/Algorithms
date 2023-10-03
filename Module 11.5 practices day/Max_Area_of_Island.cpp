

#include <bits/stdc++.h>
class Solution
{
public:
    int n, m;
    int maxim = 0;
    bool valid(int i, int j)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    vector<vector<bool>> visited{55, vector<bool>(55, false)};
    vector<pair<int, int>> direction = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    void DFS(int i, int j, vector<vector<int>> grid)
    {
        if (valid(i, j) && !visited[i][j] && grid[i][j] != 0)
        {
            visited[i][j] = true;
            maxim++;
            for (auto &&d : direction)
            {
                int ni = i + d.first;
                int nj = j + d.second;

                DFS(ni, nj, grid);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        int MainMax = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (valid(i, j) && !visited[i][j] && grid[i][j] != 0)
                {
                    maxim = 0;
                    DFS(i, j, grid);
                    if (MainMax < maxim)
                        MainMax = maxim;
                }
            }
        }
        return MainMax;
    }
};