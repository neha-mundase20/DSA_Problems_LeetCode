class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        set<int>st; //It will store unique elements in the sorted order
        
        for(int i=0;i<nums.size();i++){
                st.insert(nums[i]); //storing elements in the set
        }
        
        int i=0;
        for(auto it:st){
            nums[i]=it;
            i++;
        }
        
        return st.size();
    }
};