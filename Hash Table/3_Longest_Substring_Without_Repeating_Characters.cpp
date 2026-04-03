#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Use a vector to store the last seen index of characters.
        // Initialize with -1 to indicate the character hasn't been seen.
        vector<int> last_seen(128, -1);
        
        int max_len = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            char current_char = s[right];
            
            // If the character was seen before and is within the current window
            if (last_seen[current_char] >= left) {
                // Move left to one position after the previous occurrence
                left = last_seen[current_char] + 1;
            }
            
            // Update the last seen position of the character
            last_seen[current_char] = right;
            
            // Calculate and update the maximum length found so far
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};