class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec = 1;  // Current lengths of increasing/decreasing subarrays
        int maxLen = 1;        // Maximum length found so far
        
        // Handle single element array
        if (nums.size() == 1) return 1;
        
        // Check both increasing and decreasing sequences
        for (int i = 0; i < nums.size() - 1; i++) {
            // Check increasing sequence
            if (nums[i] < nums[i + 1]) {
                inc++;
                dec = 1;  // Reset decreasing count
            }
            // Check decreasing sequence
            else if (nums[i] > nums[i + 1]) {
                dec++;
                inc = 1;  // Reset increasing count
            }
            // If equal, reset both counts
            else {
                inc = 1;
                dec = 1;
            }
            
            // Update maximum length
            maxLen = max(maxLen, max(inc, dec));
        }
        
        return maxLen;
    }
};