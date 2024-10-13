class Solution {
public:

    /*void f(int index, int target, int currentSum, vector<int>& candidates, set<vector<int>>&result, vector<int>&temp){
        if(currentSum==target){
            result.insert(temp);
            return;
        }
        if(index>=candidates.size() || currentSum>target){
            return;
        }

        temp.push_back(candidates[index]);
        f(index+1,target,currentSum+candidates[index],candidates,result,temp);
        temp.pop_back();
        f(index+1,target,currentSum,candidates,result,temp);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>>result;
        vector<int>temp;
        int currentSum=0;
        vector<vector<int>>solution;

        sort(candidates.begin(),candidates.end());

        f(0,target,currentSum,candidates,result,temp);
        for(auto it:result){
            solution.push_back(it);
        }
        return solution;
    }*/

    void f(int index, int target, int currentSum, vector<int>& candidates, vector<vector<int>>&result, vector<int>&temp){
        if(currentSum==target){
            result.push_back(temp);
            return;
        }
        if(index>=candidates.size() || currentSum>target){
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i - 1]) continue; // Skip duplicates
            if(currentSum + candidates[i] > target) break; // No need to continue if currentSum exceeds target

            temp.push_back(candidates[i]);
            f(i + 1, target, currentSum + candidates[i], candidates, result, temp);
            temp.pop_back(); // Backtrack by removing the last element
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        int currentSum=0;
        vector<vector<int>>result;

        sort(candidates.begin(),candidates.end());

        f(0,target,currentSum,candidates,result,temp);
        return result;

    }
};