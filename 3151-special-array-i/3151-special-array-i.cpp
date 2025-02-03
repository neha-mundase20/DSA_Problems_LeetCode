class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;){
            if((nums[i]%2==0 && nums[i+1]%2!=0) || (nums[i]%2!=0 && nums[i+1]%2==0)){
              i++;  
            }
            else{
                return false;
            }
        }
        return true;
    }
};