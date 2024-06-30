class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        //Better Solution
        
        /*set<vector<int>>solution;
        
        for(int i=0;i<nums.size();i++){
            set<int>hashmap;
            for(int j=i=1;j<nums.size();j++){
                int k=-(nums[i]+nums[j]);   //nums[i] + nums[j] + nums[k] == 0
                //Check if k exists in hashmap(consists of all elements in between i & j)
                if(hashmap.find(k)!=hashmap.end()){
                    vector<int>temp={nums[i],nums[j],k};
                    sort(temp.begin(),temp.end());
                    solution.insert(temp);
                }
                    hashmap.insert(nums[j]);
            }
        }
        vector<vector<int>>answer(solution.begin(),solution.end());
        return answer;*/
        
        //Time Complexity : O(n2)log n
        
        //Optimal Solution
        //Two-pointer approach
        
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1,k=n-1;
            
            while(j<k){ //j & k haven't crossed each other
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;    //so that the value decreases to reach sum as 0
                }
                else if(sum<0){
                    j++;    //so that the value increases to reach sum as 0
                }
                else{   //sum equals to 0, and this is a valid triplet
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]){  //coz the same value has already occured
                        j++;
                    }
                    while(j<k && nums[k]==nums[k+1]){  //coz the same value has already occured
                        k--;
                    }
                }
                
            }
        }
        return ans;
    }
};
