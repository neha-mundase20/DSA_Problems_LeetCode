class Solution {
public:
    void f(int index,vector<int>&temp,vector<int>& nums,vector<vector<int>>&result){
        if(index>=nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);    //take element at index
        f(index+1,temp,nums,result);
        temp.pop_back();    //don't take element at index
        f(index+1,temp,nums,result);
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;

        vector<int>temp;

        f(0,temp,nums,result);
        return result;
    }
};