/*
	4. Median of Two Sorted Arrays (HARD)
	There are two sorted arrays nums1 and nums2 of size m and n respectively.
	Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

	nums1 = [1, 3]						nums1 = [1, 2]
	nums2 = [2]							nums2 = [3, 4]
	The median is 2.0					The median is (2 + 3)/2 = 2.5
*/


// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/*
 * Class to perform 'Median of Two Sorted Arrays' implementation
 */
class MedianSortedArraysSolution {
public:

	// Method to implement 'Median of Two Sorted Arrays'
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	// Corner case
    	double medianAns = 0.0;
    	if (nums1.size() == 0 && nums2.size() == 0) return 0.0;
    	// num1 vector is empty
        if (nums1.size() == 0) {
            int n2_s = nums2.size();
            if (n2_s % 2 == 0)
                medianAns = (nums2[(n2_s / 2) - 1] + nums2[(n2_s / 2)]) / 2.0;
            else
                medianAns = nums2[ceil(n2_s / 2.0) - 1];
            return medianAns;
        }
        // num2 vector is empty
        if (nums2.size() == 0) {
            int n1_s = nums1.size();
            if (n1_s % 2 == 0)
                medianAns = (nums1[(n1_s / 2) - 1] + nums1[n1_s / 2]) / 2.0;
            else
                medianAns = nums1[ceil(n1_s / 2.0) - 1];
            return medianAns;
        } 

        // Local variable
        int currPos = 0;     
        bool isEven = false;
        size_t pos, totalSize = nums1.size() + nums2.size();
        vector<int>::iterator it1 = nums1.begin(), it2 = nums2.begin();

        // Position of Median as per Even or Odd total size
        if (totalSize % 2 == 0) {
            isEven = true;
            pos = (totalSize / 2);            
        } else {
            pos = ceil(totalSize / 2.0);
        }

        // Traverse through both input vectors to find current position
        while(it1 != nums1.end() && it2 != nums2.end()) {
            ++currPos;
            // Break condition
            if (currPos == pos) break;

            if (*it1 <= *it2) ++it1;
            else ++it2;
        }

        // Logic as per Even or Odd merged sorted list
        if (isEven) {
            if (currPos == pos) {
                int n1 = 0, n2 = 0;
                if (*it1 == *it2) {
                    n1 = *it1;
                    n2 = *it2;
                } else if (*it1 < *it2) {
                    n1 = *it1;
                    if (it1 + 1 == nums1.end()) {
                        n2 = *it2;
                    } else {
                        ++it1;
                        if (*it1 <= *it2) n2 = *it1;
                        else n2 = *it2;
                    }
                } else {
                    n1 = *it2;
                    if (it2 + 1 == nums2.end()) {
                        n2 = *it1;
                    } else {
                        ++it2;
                        if (*it2 <= *it1) n2 = *it2;
                        else n2 = *it1;
                    }
                }
                medianAns = (n1 + n2) / 2.0;
            } else {
            	// Find current position and final answer
                while (it1 != nums1.end()) {
                    ++currPos;
                    if (pos == currPos) {
                        medianAns = (*it1 + *(it1 + 1)) / 2.0;
                        break;
                    }
                    ++it1;
                }
                while (it2 != nums2.end()) {
                    ++currPos;
                    if (pos == currPos) {
                        medianAns = (*it2 + *(it2 + 1)) / 2.0;
                        break;
                    }
                    ++it2;
                }
            }
        } else { // ODD
            if (currPos == pos) {
                medianAns = min(*it1, *it2);
            } else {
            	// Find current position and final answer
                while (it1 != nums1.end()) {
                    ++currPos;
                    if (pos == currPos) {
                        medianAns = *it1;
                        break;
                    }
                    ++it1;
                }
                while (it2 != nums2.end()) {
                    ++currPos;
                    if (pos == currPos) {
                        medianAns = *it2;
                        break;
                    }
                    ++it2;
                }
            }
        }

        return medianAns;
    }
};

/*
 * Driver Code
 */
int main() {
	
	// TODO

	return 0;
}