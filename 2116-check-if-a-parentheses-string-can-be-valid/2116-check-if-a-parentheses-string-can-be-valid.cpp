class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size() % 2 != 0) {
            return false;
        }
        
        // Forward pass - Check excess ')'
        int open = 0;  // count of '(' and unlocked positions
        int close = 0; // count of ')'
        
        for(int i = 0; i < s.size(); i++) {
            if(locked[i] == '0' || s[i] == '(') {
                open++;
            } else {
                close++;
            }
            
            if(close > open) {
                return false;
            }
        }
        
        // Backward pass - Check excess '('
        open = 0;  // count of unlocked positions and ')'
        close = 0; // count of '('
        
        for(int i = s.size()-1; i >= 0; i--) {
            if(locked[i] == '0' || s[i] == ')') {
                open++;
            } else {
                close++;
            }
            
            if(close > open) {
                return false;
            }
        }
        
        return true;
    }
};