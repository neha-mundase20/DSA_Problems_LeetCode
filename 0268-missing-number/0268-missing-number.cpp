class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();  //Range [0,n]
        int expectedSum=0;
        int obtainedSum=0;
        
        //Sum of first n natural numbers
        expectedSum=n*(n+1)/2;
            
        //Sum of array elements
            
        for(auto it:nums){
            obtainedSum=obtainedSum+it;
        }
        
        //Return the missing element
        
        return (expectedSum-obtainedSum);
    }
};