/*
In an alien language, surprisingly they also use english lowercase letters, 
but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, 
and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.



Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
*/

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isAlienSorted(vector<string>& words, string order) {
    size_t indices[26]{};
    for (size_t i = 0; i < order.size(); ++i) {
        indices[order[i] - 'a'] = i;
    }

    return is_sorted(words.begin(), words.end(), [&indices](
        const string &w1, const string &w2
        ) {
        auto l1 = w1.size(), l2 = w2.size();
        for (auto i = 0; i < min(l1, l2); ++i) {
            auto c1 = w1[i], c2 = w2[i];
            if (c1 != c2) {
                return indices[c1 - 'a'] < indices[c2 - 'a'];
            }
        }
        return l1 < l2;
    });
}