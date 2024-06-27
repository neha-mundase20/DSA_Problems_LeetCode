class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        vector<double>averages;
        /*int minElement=INT_MAX,maxElement=INT_MIN;
        
        for(int i=0;i<(nums.size())/2;i++){
            for(int j=0;j<nums.size();j++){
                minElement=min(minElement,nums[i]);
                maxElement=max(maxElement,nums[i]);
            }
            
            nums.erase(find(nums.begin(),nums.end(),minElement));
            nums.erase(find(nums.begin(),nums.end(),maxElement));
            
            averages.push_back((double)(minElement+maxElement)/(double)2);
        }
        
        double answer=INT_MAX;
        for(int i=0;i<averages.size();i++){
            answer=min(answer,averages[i]);
        }
        
        return answer;*/
        
        if(nums.size()==0){
            return 0.0;
        }
        
        while(nums.size()>1){
            int minElement=*min_element(nums.begin(),nums.end());
            int maxElement=*max_element(nums.begin(),nums.end());
            
            averages.push_back((double)(minElement+maxElement)/(double)2);
            
            nums.erase(find(nums.begin(),nums.end(),minElement));
            nums.erase(find(nums.begin(),nums.end(),maxElement));
        }
        
        return *min_element(averages.begin(),averages.end());
        
        
    }
};