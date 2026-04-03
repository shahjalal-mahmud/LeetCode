#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Start from the last digit (right to left)
        for (int i = n - 1; i >= 0; i--) {
            // Increment the current digit
            digits[i]++;

            // If the digit is less than 10, no carry is needed. 
            // We are done!
            if (digits[i] < 10) {
                return digits;
            }

            // If we reach here, digits[i] was 10, so set it to 0
            // and the loop will increment the next digit to the left.
            digits[i] = 0;
        }

        // If the loop finishes, it means we had a carry out of the 
        // most significant digit (e.g., 999 -> 1000).
        // We need to add a '1' at the beginning.
        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};