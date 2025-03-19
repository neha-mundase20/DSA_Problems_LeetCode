class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum=0;
        int maxSum=nums[0];

        if(nums.size()==1){
            return nums[0];
        }

        for(auto it:nums){
            currentSum=currentSum+it;
            maxSum=max(currentSum,maxSum);

            if(currentSum<0){
                currentSum=0;
            }
        }
        return maxSum;
    }
};