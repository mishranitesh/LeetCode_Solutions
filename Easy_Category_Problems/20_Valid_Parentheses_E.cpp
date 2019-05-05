/*
	20. Valid Parentheses (EASY)
	Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
	An input string is valid if:
		Open brackets must be closed by the same type of brackets.
		Open brackets must be closed in the correct order.
	Note that an empty string is also considered valid.

	Input: "()"			Input: "()[]{}"			Input: "(]"
	Output: true		Output: true			Output: false

	Input: "([)]"		Input: "{[]}"			Input: ""
	Output: false		Output: true			Output: true
*/


// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/*
 * Class to perform 'Valid Parentheses' implementation
 */
class ValidParenthesesSolution {
public:

	// Method to implement 'Valid Parentheses'
    bool isValid(string s) {
        // Corner case
        if (s.length() == 0) return true;
        
        // Local variable
        stack<char> bracketStk;

        // Travese through input string and check for parentheses
        for (char ch : s) {
        	// Opening parentheses push inside Stack
            if (ch == '{' || ch == '[' || ch == '(') {
                bracketStk.push(ch);
            } else {
            	// Check when Closing parentheses appears in string
                if (bracketStk.empty()) return false;
                if (ch == '}' && bracketStk.top() != '{') return false;
                if (ch == ']' && bracketStk.top() != '[') return false;
                if (ch == ')' && bracketStk.top() != '(') return false;
                bracketStk.pop();
            }
        }

        return (bracketStk.empty() ? true : false);
    }
};

/*
 * Driver Code
 */
int main() {
	
	// TODO

	return 0;
}