/*
	5. Longest Palindromic Substring (MEDIUM)
	Given a string s, find the longest palindromic substring in s.

	Input: "babad"									"cbbd"
	Output: "bab"									"bb"
	Note: "aba" is also a valid answer.
*/

// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/*
 * Class to perform 'Longest Palindromic Substring' implementation
 */
class LongestPalindromicSubstrSolution {
public:

	// Method to implement 'Longest Palindromic Substring' -- Using Dynamic Programming
    string longestPalindrome(string s) {
        // Corner Case
        if (s.length() <= 1) return s;

        // Local variable
		string lngstPalndrm;
        int startIndx = -1, endIndx = -1, strLen = s.length();
        vector<vector<bool>> matrix(strLen, vector<bool>(strLen, false));

        // Check for string of length 1
        for (int i = 0; i < strLen; ++i) {
            matrix[i][i] = true; // Single letter is always palindrome
            if (startIndx == -1 && endIndx == -1) {
                startIndx = i;
                endIndx = i;
            }
        }

        // Check for string of length 2
        for (int i = 0; i + 1 < strLen; ++i) {
            if (s[i] == s[i + 1]) {
                matrix[i][i + 1] = true;
                startIndx = i;
                endIndx = i + 1;
            }
        }

        // Check for string of length > 2
        int j = 0;
        for (int k = 2; k < strLen; ++k) {
            for (int i = 0; i < strLen; ++i) {
                j = i + k;
                if (j < strLen) {
                    if (s[i] == s[j] && matrix[i + 1][j - 1] == true) {
                        matrix[i][j] = true;
                        startIndx = i;
                        endIndx = j;
                    }
                }
            }
        }

        // Prepare longest palindromic substring
        lngstPalndrm = s.substr(startIndx, endIndx - startIndx + 1);

        return lngstPalndrm;
    }
};

/*
 * Driver Code
 */
int main() {
	
	// TODO

	return 0;
}