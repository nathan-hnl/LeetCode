#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> subCharSet;
        int n = s.size();
        int rIndex = -1, ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
            {
                subCharSet.erase(s[i - 1]);
            }
            while (rIndex + 1 < n && subCharSet.count(s[rIndex + 1]))
            {
                subCharSet.insert(s[rIndex + 1]);
                rIndex++;
            }

            ans = max(ans, rIndex - i + 1);
        }
        return ans;
    }
};