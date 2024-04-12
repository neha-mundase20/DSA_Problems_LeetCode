class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int posCount=0;
        int negCount=0;
        
        for(int i=0;i<nums.size();){
            if(nums[i]>0){  //Number is positive
                posCount++;
                i++;
            }
            else if(nums[i]<0){ //Number is negative
                negCount++;
                i++;
            }
            else{   //Number is zero
                i++;
            }
        }
        return max(posCount,negCount);
    }
};