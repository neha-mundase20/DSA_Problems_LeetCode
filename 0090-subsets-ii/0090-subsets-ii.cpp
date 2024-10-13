class Solution {
public:

    void f(vector<int>&temp, vector<vector<int>>&result, vector<int>& nums, int index){
        // Add the current subset to the result
        result.push_back(temp);

        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]){
                //duplicates
                continue;
            }
            temp.push_back(nums[i]);
            f(temp,result,nums,i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>>subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        f(temp,result,nums,0);
        return result;
    }
};