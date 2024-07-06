class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>solution;
        
        int low=0,high=nums.size()-1,mid=0;
        
        while(low<=high){
            mid=low+((high-low)/2);
            
            if(nums[mid]<target){
                low=mid+1;
            }
            else{
                //Still need to search for first occurence so go to the left part
                high=mid-1;
            }
        }
        
        if(low>=nums.size() || nums[low]!=target){
            solution.push_back(-1);
            solution.push_back(-1);
            return solution;
        }
        
        solution.push_back(low);
        high=nums.size()-1;  //Move to right part for last occurence
        
        while(low<=high){
            mid=low+((high-low)/2);
            
            if(nums[mid]<=target){
                low=mid+1;
            }
            else{
                //Still need to search for last occurence so go to the right part
                high=mid-1;
            }
        }
        solution.push_back(high);
        
        return solution;
    }
};