/*
	49. Group Anagrams (MEDIUM)
	Given an array of strings, group anagrams together.
	Note:
		All inputs will be in lowercase.
		The order of your output does not matter.

	Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
	Output:
		[
		  ["ate","eat","tea"],
		  ["nat","tan"],
		  ["bat"]
		]
*/


// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/*
 * Class to perform 'Group Anagrams' implementation
 */
class GroupAnagramsSolution {
public:

    // Method to implement 'Group Anagrams'
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Corner case
        if (strs.size() == 0) return {};
        if (strs.size() == 1) return {strs};
        
        // Local variables
        vector<vector<string>> groupVect;
        unordered_map<string, vector<string>> keyVectMap;

        // Traverse through input vector and prepare Map (Unique Key --> Vector of Strings)
        for (auto str : strs) {
            string key("");
            getUniqueKey(str, key);
            if (keyVectMap.find(key) == keyVectMap.end())
                keyVectMap[key] = {str};
            else
                keyVectMap[key].emplace_back(move(str));
        }

        // Prepare group anagram vector
        for (auto it = keyVectMap.begin(); it != keyVectMap.end(); ++it)
            groupVect.emplace_back(move(it->second));
        
        return groupVect;
    }

private:
	// Method to prepare Unique Key for input string
	void getUniqueKey(string &str, string &uniqueKey) {
        // Input characters are in Lower Case (Charset of 26 letters)
        vector<int> charset(26, 0);

        // Fill charset with count of occurrence of characters
        for (int i = 0; i < str.length(); ++i)
            ++charset[str[i] - 'a'];

        // Prepare unique key as string
        for (int num : charset)
            uniqueKey += ("#", num);
    }
};

/*
 * Driver Code
 */
int main() {
	
	// TODO

	return 0;
}