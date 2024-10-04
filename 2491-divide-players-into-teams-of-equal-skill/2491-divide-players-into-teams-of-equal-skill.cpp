class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int totalSum=0;

        for(auto it:skill){
            totalSum=totalSum+it;
        }

        int totalgroups=skill.size()/2;

        int sumofeachgrp=totalSum/totalgroups;

        unordered_map<int,int> mp;
        vector<vector<int>>result;

        for(auto it:skill){
            mp[it]++;
        }

        for(auto it:skill){
            if(mp[it]>0){   //BOTH THE ELEMENTS ARE PRESENT IN MAP
                if(mp[sumofeachgrp-it]>0){  
                    result.push_back({it,(sumofeachgrp-it)});
                    mp[(sumofeachgrp-it)]--;
                    mp[it]--;
                }
                else{
                    return -1;
                }
            }
        }

        long long solution=0;

        if(totalgroups==result.size()){
            for(int i=0;i<result.size();i++){
                solution=solution+result[i][0]*result[i][1];
            }
            return solution;
        }
        return -1;
    }
};