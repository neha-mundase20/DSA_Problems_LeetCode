class Solution {
public:

    // Function to convert a decimal number to a binary string
    string decimalToBinary(int n) {
        string binary = "";
        while (n > 0) {
            binary = to_string(n % 2) + binary;
            n /= 2;
        }
        return binary;
    }

    // Function to count the number of set bits (1's) in an integer
    int setBits(int n) {
        int count = 0;
        while (n > 0) {
            if (n % 2 == 1) {
                count++;
            }
            n /= 2;
        }
        return count;
    }

    int minimizeXor(int num1, int num2) {
        int sbc1 = setBits(num1);
        int sbc2 = setBits(num2);
        
        if (sbc1 == sbc2) {
            return num1;
        }

        string temp = decimalToBinary(num1);
        
        // If num1 has fewer set bits than num2, add 1's from right
        if (sbc1 < sbc2) {
            int diff = sbc2 - sbc1;
            int n = temp.size() - 1;
            
            while (diff > 0 && n >= 0) {
                if (temp[n] == '0') {
                    temp[n] = '1';
                    diff--;
                }
                n--;
            }
            
            // If there are still more 1's to add, add them at start
            while (diff > 0) {
                temp = '1' + temp;
                diff--;
            }
        }
        // If num1 has more set bits than num2, remove 1's from right
        else {
            int diff = sbc1 - sbc2;
            int n = temp.size() - 1;
            
            // Change '1' to '0' from right to left
            while (diff > 0 && n >= 0) {
                if (temp[n] == '1') {
                    temp[n] = '0';
                    diff--;
                }
                n--;  // Move to next bit
            }
        }
        
        // Convert binary string back to decimal
        int result = 0;
        for (char bit : temp) {
            result = result * 2 + (bit - '0');
        }
        
        return result;
    }
};



// Count Set Bits:

// First, we count how many 1s (set bits) are present in the binary representation of num1 (sbc1) and num2 (sbc2).
// Check if Already Equal:

// If num1 and num2 already have the same number of set bits (sbc1 == sbc2), then no change is needed. We can return num1 as the result.
// Modify num1:

// If num1 has fewer set bits than num2 (sbc1 < sbc2), we need to add more 1s to num1. This is done by changing 0s to 1s in its binary representation, starting from the least significant bit.
// If num1 has more set bits than num2 (sbc1 > sbc2), we need to remove 1s from num1. This is done by changing 1s to 0s, starting from the least significant bit.
// Handle Edge Cases:

// After modifying the binary string, if the number of bits in num1 is still less than required, we keep adding 1s (or 0s) at the most significant positions (beginning of the string) until the set bits match num2.