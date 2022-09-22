/*
 *
 Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.
*/
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int minMeetingRooms1(vector<vector<int>> &intervals)
{
    if (intervals.empty())
        return 0;

    // sort(intervals.begin(), intervals.end());
    map<int, int> m;
    for (auto &a : intervals)
    {
        ++m[a[0]];
        --m[a[1]];
    }
    int rooms = 0, res = 0;
    for (auto &itr : m)
    {
        res = max(res, rooms += itr.second);
    }

    return res;
}

int minMeetingRooms2(vector<vector<int>> &intervals)
{
    if (intervals.empty())
        return 0;

    vector<int> starts, ends;
    int res = 0, endpos = 0;
    for (auto &a : intervals)
    {
        starts.push_back(a[0]);
        ends.push_back(a[1]);
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    for (int i = 0; i < intervals.size(); ++i)
    {
        if (starts[i] < ends[endpos])
        {
            ++res;
        }
        else
        {
            ++endpos;
        }
    }
    return res;
}

#include <queue>

int minMeetingRooms3(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0]; });
    priority_queue<int, vector<int>, greater<int>> q;
    for (auto interval : intervals)
    {
        if (!q.empty() && q.top() <= interval[0])
            q.pop();
        q.push(interval[1]);
    }
    return q.size();
}