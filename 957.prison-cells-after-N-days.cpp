/*
 * There are 8 prison cells in a row and each cell is either occupied or vacant.
 * Each day, whether the cell is occupied or vacant changes according to the following rules:
 *   If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
 *   Otherwise, it becomes vacant.
 * Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.
 * You are given an integer array cells where cells[i] == 1 if the ith cell is occupied and cells[i] == 0 if the ith cell is vacant, and you are given an integer n.
 * Return the state of the prison after n days (i.e., n such changes described above).
 * 
 * Example 1:
 * Input: cells = [0,1,0,1,1,0,0,1], n = 7
 * Output: [0,0,1,1,0,0,0,0]
 * Explanation: The following table summarizes the state of the prison on each day:
 * Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
 * Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
 * Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
 * Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
 * Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
 * Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
 * Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
 * Day 7: [0, 0, 1, 1, 0, 0, 0, 0]
 * 
 * Example 2:
 * Input: cells = [1,0,0,1,0,0,1,0], n = 1000000000
 * Output: [0,0,1,1,1,1,1,0]
 * 
 * Constraints:
 * cells.length == 8
 * cells[i] is either 0 or 1.
 * 1 <= n <= 109
 * 
*/
#include <vector>
#include <unordered_map>

using namespace std;

int nextDay(int state)
{
    int ans = 0;
    for (int i = 1; i <= 6; ++i)
    {
        if (((state >> (i - 1)) & 1) == ((state >> (i + 1)) & 1))
        {
            //ans ^= 1 << i;
            ans |= 1 << i;
        }
    }
    return ans;
}

vector<int> prisonAfterNDays(vector<int>& cells, int n)
{
    int cellSize = cells.size();
    int state = 0;
    for (int i = 0; i < cellSize; ++i)
    {
        if (cells[i] > 0)
        {
            state |= 1 << (cellSize - i - 1);
            //state ^= 1 << (cellSize - i - 1);
        }
    }

    unordered_map<int, int> seen;
    while (n > 0)
    {
        if (seen.find(state) != seen.end())
        {
            n %= (seen[state] - n);
        }
        seen[state] = n;

        if (n >= 1)
        {
            n--;
            state = nextDay(state);
        }
    }

    vector<int> ans(8);
    for (int i = 0; i < 8; ++i)
    {
        if (((state >> i) & 1)  > 0)
        {
            ans[8 - i - 1] = 1;
        }
    }
    return ans;
}