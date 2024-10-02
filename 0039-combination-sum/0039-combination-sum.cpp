class Solution {
public:

    void f(int index,vector<int>&temp, vector<int>& candidates, vector<vector<int>>&result, int currentSum, int target){
        if(currentSum==target){
            result.push_back(temp);
            return;
        }

        // If currentSum exceeds the target or index is out of bounds, stop
        if (currentSum>target || index>=candidates.size()) {
            return;
        }

        temp.push_back(candidates[index]);  //take
        //we can take same element multiple number of times
        f(index,temp,candidates,result,currentSum+candidates[index],target);

        temp.pop_back();    //not Take
        f(index+1,temp,candidates,result,currentSum,target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>temp;
        int currentSum=0;
        f(0,temp,candidates,result,currentSum,target);
        return result;
    }
};