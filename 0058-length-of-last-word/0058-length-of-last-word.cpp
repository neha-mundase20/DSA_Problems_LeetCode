class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int l = s.size() - 1;
        
        // Skip trailing spaces
        while (l >= 0 && s[l] == ' ')
            l--;
        
        // Count characters until a space or the beginning of the string
        while (l >= 0 && s[l] != ' ') {
            length++;
            l--;
        }
        return length;
    }
};