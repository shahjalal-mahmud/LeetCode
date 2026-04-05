#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1; // Pointer for string a
        int j = b.length() - 1; // Pointer for string b
        int carry = 0;

        // Continue as long as there are characters to process or a carry exists
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            // Add bit from string a if available
            if (i >= 0) {
                sum += a[i] - '0'; // Convert char '0' or '1' to int 0 or 1
                i--;
            }

            // Add bit from string b if available
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            // The current binary digit is sum % 2
            // Example: 2 % 2 = 0, 3 % 2 = 1
            result += (sum % 2) + '0';

            // The new carry is sum / 2
            // Example: 2 / 2 = 1, 3 / 2 = 1
            carry = sum / 2;
        }

        // Since we appended digits to the end, the string is backwards
        reverse(result.begin(), result.end());
        return result;
    }
};