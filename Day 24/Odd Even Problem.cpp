// Easy
//String
// https://www.geeksforgeeks.org/problems/help-nobita0532/1

class Solution {
public:
    string oddEven(string s) {
        int hash[26] = {0}; // Corrected the size to 26
        
        // Count frequency of each character in the string
        for (char c : s) {
            hash[c - 'a']++;
        }
        
        int x = 0, y = 0;
        
        // Calculate x and y based on the conditions
        for (int i = 0; i < 26; i++) {
            if ((i + 1) % 2 == 1 && hash[i] % 2 == 1) {
                // Odd position (1-based) and odd frequency
                y++;
            } else if ((i + 1) % 2 == 0 && hash[i] % 2 == 0 && hash[i] > 0) {
                // Even position (1-based) and even frequency
                x++;
            }
        }
        
        return ((x + y) % 2 == 0) ? "EVEN" : "ODD";
    }
};
