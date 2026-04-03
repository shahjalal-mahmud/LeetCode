#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;      // End of valid nums1
        int j = n - 1;      // End of nums2
        int k = m + n - 1;  // End of nums1 capacity

        // While there are elements to compare in both arrays
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // If there are leftover elements in nums2, copy them.
        // We don't need to worry about nums1 leftovers because 
        // they are already in their correct place.
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};