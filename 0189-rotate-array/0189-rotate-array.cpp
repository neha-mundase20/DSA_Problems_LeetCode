class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int n = nums.size();
        vector<int> temp(n); // create a temporary array of size n
        
        // Copy the elements to the temporary array
        for (int i = 0; i < n; ++i) {
            temp[(i + k) % n] = nums[i];
        }
        
        // Copy the elements back to nums
        for (int i = 0; i < n; ++i) {
            nums[i] = temp[i];
        }
    }
};