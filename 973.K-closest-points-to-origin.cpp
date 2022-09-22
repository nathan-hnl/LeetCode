/*
 * Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
 * The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
 * You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
 *
 * Input: points = [[1,3],[-2,2]], k = 1
 * Output: [[-2,2]]
 * Explanation:
 * The distance between (1, 3) and the origin is sqrt(10).
 * The distance between (-2, 2) and the origin is sqrt(8).
 * Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
 * We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
 *
 * Example 2:
 * Input: points = [[3,3],[5,-1],[-2,4]], k = 2
 * Output: [[3,3],[-2,4]]
 * Explanation: The answer [[-2,4],[3,3]] would also be accepted.
 *
 * Constraints:
 * 1 <= k <= points.length <= pow(10, 4)
 * pow(-10, 4) < xi, yi < pow(10, 4)
 */

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    sort(points.begin(), points.end(), [](const vector<int> &u, const vector<int> &v)
         { return u[0] * u[0] + u[1] * u[1] < v[0] * v[0] + v[1] * v[1]; });
    return {points.begin(), points.begin() + k};
}

vector<vector<int>> kClosest2(vector<vector<int>> &points, int k)
{
    priority_queue<pair<int, int>> q; // default big data is on top
    for (int i = 0; i < k; ++i)
    {
        q.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
    }
    int n = points.size();
    for (int i = k; i < n; ++i)
    {
        int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        if (dist < q.top().first)
        {
            q.pop();
            q.emplace(dist, i);
        }
    }
    vector<vector<int>> ans;
    while (!q.empty())
    {
        ans.push_back(points[q.top().second]);
        q.pop();
    }
    return ans;
}