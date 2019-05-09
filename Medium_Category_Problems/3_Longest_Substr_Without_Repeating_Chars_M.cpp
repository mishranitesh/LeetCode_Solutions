/*
	3. Longest Substring Without Repeating Characters (MEDIUM)
	Given a string, find the length of the longest substring without repeating characters.

	Input: "abcabcbb"
	Output: 3
	Explanation: The answer is "abc", with the length of 3.

	Input: "bbbbb"
	Output: 1
	Explanation: The answer is "b", with the length of 1.

	Input: "pwwkew"
	Output: 3
	Explanation: The answer is "wke", with the length of 3.
	Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/*
 * Class to perform 'Longest Substring Without Repeating Characters' implementation
 */
class LongestSubstrWithoutRepeatingCharsSolution {
public:

	// Method to implement 'Longest Substring Without Repeating Characters'
    int lengthOfLongestSubstring(string s) {
        // Corner case
        if (s.length() <= 1) return s.length();

        // Sliding window approach using Map
        unordered_map<char, int> indxMap;
        int start = 0, maxLen = numeric_limits<int>::min();

        // Traverse through input string and determine maximum length
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if (indxMap.find(ch) == indxMap.end()) { // Not Found in Map
                indxMap.insert(make_pair(ch, i));
            } else {
                if (indxMap[ch] >= start)
                    start = indxMap[ch] + 1;
                indxMap[ch] = i;
            }
            maxLen = max(maxLen, (i - start + 1));
        }

        return maxLen;
    }
};

/*
 * Driver Code
 */
int main() {
	
	// TODO

	return 0;
}