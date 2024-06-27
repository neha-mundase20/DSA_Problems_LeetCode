class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        set<double>averages;
        
        if(nums.size()==0){
            return 0.0;
        }
        
        while(nums.size()>1){
            int minElement=*min_element(nums.begin(),nums.end());
            int maxElement=*max_element(nums.begin(),nums.end());
            
            averages.insert((double)(minElement+maxElement)/(double)2);
            
            nums.erase(find(nums.begin(),nums.end(),minElement));
            nums.erase(find(nums.begin(),nums.end(),maxElement));
        }
        
        return averages.size();
    }
};