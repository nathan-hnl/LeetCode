
/*
 *
 You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

 Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

 Return a list of integers representing the size of these parts.
*/

#include <vector>
#include <string>

using namespace std;

vector<int> partitionLabels(string s)
{
    int last[26];
    int length = s.size();
    for (int i  = 0; i < length; i++)
    {
        last[s[i] - 'a'] = i;
    }

    vector<int> partition;
    int start = 0, end = 0;
    for (int i = 0; i < length; i++)
    {
        end = max(end, last[s[i] - 'a']);
        if (i == end)
        {
            partition.push_back(end - start + 1);
            start = end + 1;
        }
    }
    return partition;
}