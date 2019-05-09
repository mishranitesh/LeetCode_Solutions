/*
	9. Palindrome Number (EASY)
	Determine whether an integer is a palindrome.
	An integer is a palindrome when it reads the same backward as forward.
	Note:
		Solve it without converting the integer to a string.

	Input: 121
	Output: true

	Input: -121
	Output: false
	Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

	Input: 10
	Output: false
	Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/*
 * Class to perform 'Palindrome Number' implementation
 */
class PalindromeNumberSolution {
public:

	// Method to implement 'Palindrome Number'
    bool isPalindrome(int x) {
        // Corner case
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        if (x < 10) return true;

        // Local variable
        int lsbDgt, msbDgt, dgtCnt = static_cast<int>(floor(log10(x)));
        int msbMask = static_cast<int>(pow(10, dgtCnt));

        // Traverse through input number
        while (x) {
        	// Determine MSB and LSB digits in x
            msbDgt = x / msbMask;
            lsbDgt = x % 10;

            // Number is not palindrome if LSB and MSB digits are not same
            if (msbDgt != lsbDgt) return false;

            // Modify 'x' and MSB Mask for next iteration
            x %= msbMask;
            x /= 10;
            msbMask /= 100;
        }

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