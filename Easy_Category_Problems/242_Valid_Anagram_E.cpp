/*
	242. Valid Anagram (EASY)
	Given two strings s and t, write a function to determine if t is an anagram of s.
	You may assume the string contains only lowercase alphabets.

	Input: s = "anagram", t = "nagaram"
	Output: true

	Input: s = "rat", t = "car"
	Output: false
*/


// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/*
 * Class to perform 'Valid Anagram' implementation
 */
class ValidAnagramSolution {
public:

	// Method to implement 'Valid Anagram'
    bool isAnagram(string s, string t) {
        // Corner case
        if (s.length() != t.length() != 0) return false;

        // Local variables - Charset of 26 for lower case alphabets
        vector<int> charset(26, 0);

        // Traverse through input string and Modify charset using s[i] and t[i]
        for (int i = 0; i < s.length(); ++i) {
            charset[s[i] - 'a'] += 1;
            charset[t[i] - 'a'] -= 1;
        }

        // Traverse through charset and if count is non-zero then not anagram
        for (auto elem : charset)
            if (elem != 0)
            	return false;

        return true;
    }
};

/*
 * Driver Code
 */
int main() {
	
	// TODO

	return 0;
}