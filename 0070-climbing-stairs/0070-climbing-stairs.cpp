class Solution {
public:
    int climbStairs(int n) {

        if(n==0 || n==1){
            return 1;
        }

        vector<int>dp(n+1,0);
        dp[0]=1;    //Only 1 possible way on stair 0
        dp[1]=1;    //Only 1 possible way on stair 1

        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }

        return dp[n];
    }
};