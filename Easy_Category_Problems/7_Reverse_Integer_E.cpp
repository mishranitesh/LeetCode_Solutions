/*
	7. Reverse Integer (EASY)
	Given a 32-bit signed integer, reverse digits of an integer.
	Note:
		Function returns 0 when the reversed integer overflows.

	Input: 123			-123		120
	Output: 321			-321		21
*/

// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/*
 * Class to perform 'Reverse Integer' implementation
 */
class ReverseIntegerSolution {
public:

	// Method to implement 'Reverse Integer'
    int reverse(int x) {
    	// Corner case
    	if (x >= -9 && x <= 9) return x;

    	// Local variable
    	int rem;
        long long num = abs(static_cast<long long>(x)), reverseNum = 0;

        // Traverse through input number digit-by-digit
        while(num) {
            rem = num % 10;
            reverseNum = (reverseNum * 10) + rem;
            num /= 10;
        }

        // When input number is negative
        if (x < 0)
        	reverseNum *= -1;

        // Return 0 - when reverse integer overflows the INT limits
        if (reverseNum > numeric_limits<int>::max() || reverseNum < numeric_limits<int>::min())
            return 0;

        return reverseNum;
    }
};

/*
 * Driver Code
 */
int main() {
	
	// TODO

	return 0;
}