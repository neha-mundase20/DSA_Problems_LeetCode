class Solution {
public:

    int f(int index,int target,vector<int>& coins,vector<vector<int>>&dp){

        if(target==0){
            return 1;
        }
        if(index==0) {
            if(target%coins[0]==0){
                return 1;
            }
            else{
                return 0;
            }
        }

        if(dp[index][target]!=-1){  //Already calculated i.e. memoization
            return dp[index][target];
        }

        int notTake=f(index-1,target,coins,dp);
        int take=0;
        if(coins[index]<=target){
            take=f(index,target-coins[index],coins,dp);/*infinite supply of coins*/
        }
        return dp[index][target]=take+notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int result=f(n-1,amount,coins,dp);
        return result;
    }
};