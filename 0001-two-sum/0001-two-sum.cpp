class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>solution;
        
        //Using the two pointer approach
        
        int i=0,j=i+1,n=nums.size();
        while(i<n && j<n){
            if(nums[i]+nums[j]==target){
                solution.push_back(i);
                solution.push_back(j);
                break;
            }
            else if(j==(n-1)){
                i++;
                j=i+1;
            }
            else{
                j++;
            }
        }
        return solution;
    }
};