/*
 *
 Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
 An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/
#include <vector>

using namespace std;

// dfs Depth First Search
void dfs(vector<vector<char>>& grid, int r, int c)
{
    int nr = grid.size();
    int nc = grid[0].size();

    grid[r][c] = '0';
    if (r - 1 >= 0 && grid[r - 1][c] == '1') dfs(grid, r - 1, c);
    if (r + 1 < nr && grid[r + 1][c] == '1') dfs(grid, r + 1, c);
    if (c - 1 >= 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1);
    if (c + 1 < nc && grid[r][c + 1] == '1') dfs(grid, r, c + 1);
}

int numIslandsDFS(vector<vector<char>>& grid)
{
    int nr = grid.size();
    if (nr == 0)
        return 0;
    int nc = grid[0].size();

    int islandNum = 0;
    for (int r = 0; r < nr; ++r)
    {
        for (int c = 0; c < nc; ++c)
        {
            if (grid[r][c] == '1')
            {
                ++islandNum;
                dfs(grid, r, c);
            }
        }
    }

    return islandNum;
}

#include <queue>

// BFS Breadth First Search
int numIslandsBFS(vector<vector<char>>& grid)
{
    int nr = grid.size();
    if (nr == 0)
        return 0;
    int nc = grid[0].size();

    int islandNum = 0;
    for (int r = 0; r < nr; ++r)
    {
        for (int c = 0; c < nc; ++c)
        {
            if (grid[r][c] == '1')
            {
                ++islandNum;
                grid[r][c] = '0';
                queue<pair<int, int>> neighbors;
                neighbors.push({r, c});
                while (!neighbors.empty())
                {
                    auto rc = neighbors.front();
                    neighbors.pop();
                    int row = rc.first, col = rc.second;
                    if (row - 1 >= 0 && grid[row - 1][col] == '1')
                    {
                        neighbors.push({row - 1, col});
                        grid[row - 1][col] = '0';
                    }
                    if (row + 1 < nr && grid[row  + 1][col] == '1')
                    {
                        neighbors.push({row + 1, col});
                        grid[row + 1][col] = '0';
                    }
                    if (col - 1 >= 0 && grid[row][col - 1] == '1')
                    {
                        neighbors.push({row, col - 1});
                        grid[row][col - 1] = '0';
                    }
                    if (col + 1 < nc && grid[row][col + 1] == '1')
                    {
                        neighbors.push({row, col + 1});
                        grid[row][col + 1] = '0';
                    }
                }
            }
        }
    }
    
    return islandNum;
}
