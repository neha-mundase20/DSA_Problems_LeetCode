class Solution {
public:

    int f(int index,int target,vector<int>& coins,vector<vector<int>>& dp){
        //Base Cases

        if(index==0){
            if(target%coins[0]==0){
            //We can take multiple denominations of same coin
            return target/coins[0];
            }
            else{   //The target cannot be acheived
                return 1e9;
            }
        }

        if(dp[index][target]!=-1){
            //Already calculated subproblem
            return dp[index][target];
        }

        int notTake=f(index-1,target,coins,dp);
        int take=INT_MAX;
        if(coins[index]<=target){
            take=1+f(index,target-coins[index],coins,dp);
            /*Stay on same index coz we can take any coin infinite times, so we need to check can we take more coins of same denomination itself*/
        }
        return dp[index][target]=min(take,notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int result=f(coins.size()-1,amount,coins,dp);
        if(result>=1e9){
            return -1;
        }
        else{
            return result;
        }
    }
};