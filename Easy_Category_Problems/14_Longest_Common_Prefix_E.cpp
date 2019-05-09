/*
	14. Longest Common Prefix (EASY)
	Write a function to find the longest common prefix string amongst an array of strings.
	If there is no common prefix, return an empty string "".

	Input: ["flower", "flow", "flight"]
	Output: "fl"

	Input: ["dog", "racecar", "car"]
	Output: ""
	Explanation: There is no common prefix among the input strings.
*/

// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/*
 * Class to perform 'Longest Common Prefix' implementation
 */
class LongestCommonPrefixSolution {
public:

	// Method to implement 'Longest Common Prefix'
    string longestCommonPrefix(vector<string>& strs) {
        // Corner case
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];

        // Local Variable
        int indx = 0;
        bool flag = true;
        string commonPrefix;
        
        // Sort vector according to ascending length of strings
        sort(strs.begin(), strs.end(), sortLen);

        // Logic to find longest common prefix
        string tempStr = strs[0];
        for (auto ch : tempStr) {
            for (int i = 1; i < strs.size(); ++i)
                if (ch != strs[i][indx])
                    flag = false;

            if (!flag) break;
            commonPrefix.push_back(ch);
            ++indx;
        }

        return commonPrefix;
    }

private:
	// Comparator function to sort string as per their length
	static bool sortLen(string &str1, string &str2) {
        return (str1.length() < str2.length());
    }
};

/*
 * Driver Code
 */
int main() {

	// TODO

	return 0;
}