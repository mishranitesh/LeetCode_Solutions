/*
	28. Implement strStr() (EASY)
	Return the index of the first occurrence of needle in haystack,
	OR -1 if needle is not part of haystack.

	Input: haystack = "hello", needle = "ll"
	Output: 2

	Input: haystack = "aaaaa", needle = "bba"
	Output: -1
*/

// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/*
 * Class to perform 'Implement strStr()' implementation
 */
class Solution {
public:

	// Method to implement 'Implement strStr()'
	int strStr(string haystack, string needle) {
		// Corner case
        if (needle.length() == 0) return 0;
        if (haystack.length() < needle.length()) return -1;

        // Local variable
        int j, needleIndex = -1;

        // Traverse through input Haystack string
        for (int i = 0; i < haystack.length(); ++i) {
            if (haystack[i] == needle[0] && needleIndex == -1) {
                needleIndex = i;

                // Break condition -- When Haystack substring is smaller than needle
                if (haystack.substr(i).length() < needle.length()) return -1;

                // Check for remaining needle characters
                j = i;
                for (char ch : needle) {
                    if (haystack[j++] != ch)
                        needleIndex = -1;
                }

                // Break condition -- When needle index is -1
                if (needleIndex != -1) break;
            }
        }

        return needleIndex;
    }
};

/*
 * Driver Code
 */
int main() {

	// TODO

	return 0;
}