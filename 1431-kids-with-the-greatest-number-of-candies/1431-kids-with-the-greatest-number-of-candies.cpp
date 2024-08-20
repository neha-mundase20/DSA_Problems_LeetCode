class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        //First check which child has the maximum number of the candies
        int maxCandies=INT_MIN;
        vector<bool>result(candies.size());

        for(auto it:candies){
            if(it>=maxCandies){
                maxCandies=it;
            }
        }

        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=maxCandies){
                result[i]=true;
            }
            else{
                result[i]=false;
            }
        }

        return result;
    }
};