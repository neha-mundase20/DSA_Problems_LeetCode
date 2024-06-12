class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        //To obtain the maximum difference, for the current ith element we choose the smallest
        //element from 1st->(i-1)th element which will give me the maximum difference
        
        int minElement=nums[0],difference=0,maxDifference=0;
        
        for(int i=0;i<nums.size();i++){
            difference=nums[i]-minElement;
            maxDifference=max(maxDifference,difference);
            
            minElement=min(minElement,nums[i]); //Update the minimum element everytime
        }
        
        if(maxDifference==0){
            return -1;
        }
        else{
            return maxDifference;
        }
    }
};