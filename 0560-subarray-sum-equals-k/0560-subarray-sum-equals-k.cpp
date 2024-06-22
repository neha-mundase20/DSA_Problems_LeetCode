class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>frequency;
        int currentSum=0,subArrayCount=0;
        
        frequency[0]=1; /*To handle the cases where the currentSum is exact 'k' i.e. currentSum=3 & k=3 then no need to check if we obtained (currentSum-k) previously*/
        
        
        for(auto it:nums){
            currentSum=currentSum+it;
            
            /*If we obtained currentSum then checking that did we obtained (currentSum-k)
            previously so that an entire subarray could be formed*/
            
            if(frequency.find(currentSum-k)!=frequency.end()){
                subArrayCount=subArrayCount+frequency[currentSum-k];
            }
            
            frequency[currentSum]++;
        }
        
        return subArrayCount;
    }
};