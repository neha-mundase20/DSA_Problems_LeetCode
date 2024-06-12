class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        /* Any sequence or subsequence can be treated as a wiggle sequence if it has                    alternate greater and smaller elements so that their differences are alternate              positive and negative
            1 < 7 > 4 < 9 > 2 < 5  is a wiggle sequence because the differences (6, -3, 5,              -7, 3) alternate between positive and negative*/
            
        /*When nums[i] > nums[i-1]:
        This indicates an upward wiggle.
        The longest subsequence ending in an upward wiggle at i can be extended from the             longest subsequence that ended in a downward wiggle at i-1. Therefore, up = down +           1.

        When nums[i] < nums[i-1]:
        This indicates a downward wiggle.
        The longest subsequence ending in a downward wiggle at i can be extended from the           longest subsequence that ended in an upward wiggle at i-1. Therefore, down = up +           1.*/


        if (nums.size()<2) return nums.size();
        
        int up=1,down=1; // Initially, each element can be a wiggle sequence of length 1
        
        for (int i=1; i<nums.size();i++) {
            if(nums[i]>nums[i-1]) {
                up=down+1; // Found an upward wiggle
            } 
            else if(nums[i]<nums[i-1]) {
                down=up+1; // Found a downward wiggle
            }
        }
        
        return max(up,down); // The longest wiggle sequence can end in either direction
    }
};