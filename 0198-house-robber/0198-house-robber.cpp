class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        int maxCost;
        dp[0]=nums[0];
        if(nums.size()==1){
            return dp[0];
        }
        dp[1]=nums[1];

        if(dp[0]>=dp[1]){
            maxCost=dp[0];
        }
        else{
            maxCost=dp[1];
        }

        if(nums.size()==2){
            return maxCost;
        }

        for(int i=2;i<nums.size();i++){
            int costRobbed=INT_MIN;
            for(int j=0;j<=i-2;j++){
                costRobbed=max(costRobbed,dp[j]+nums[i]);
            }
            dp[i]=costRobbed;
            maxCost=max(maxCost,dp[i]);
        }
        return maxCost;
    }
};