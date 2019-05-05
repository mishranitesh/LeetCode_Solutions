/*
	50. Pow(x, n) (MEDIUM)
	Implement pow(x, n), which calculates x raised to the power n.
	Note:
		-100.0 < x < 100.0
		n is a 32-bit signed integer, within the range [−231, 231 − 1]

	Input: 2.00000, 10		2.10000, 3		2.00000, -2
	Output: 1024.00000		9.26100			0.25000
*/


// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/*
 * Class to perform 'Pow(x, n)' implementation
 */
class PowerXNSolution {
public:

	// Method to implement 'Pow(x, n)'
    double myPow(double x, int n) {
        // Corner Case
        if (n == 0 || x == 1.0 || (x == -1.0 && !(n & 1))) return 1.0;
        if (n == 1 || (x == -1.0 && (n & 1))) return x;
        if (x != 1 && n == numeric_limits<int>::min()) return 0.0;

        // Local variable
        double resultPow = 1.0;

		// Change x and n when power is negative
        if (n < 0) {
            x = 1.0 / x;
            n *= -1;
        }

        // Using bitwise operators
        while (n) {
            // Multiply result with x when LSB of power is 1
            if (n & 1)
                resultPow *= x;

            // Otherwise modify x by multiplying with itself
            x *= x;
            n >>= 1;
        }

        return resultPow;
    }
};

/*
 * Driver Code
 */
int main() {
	
	// TODO

	return 0;
}