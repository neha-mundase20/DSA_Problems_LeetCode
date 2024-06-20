class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>solution;
        
        if(intervals.empty()){
            //If intervals is empty return nothing
            return {};
        }
        
        sort(intervals.begin(),intervals.end());    //sort intervals
        
        solution.push_back(intervals[0]);   //start with first interval
        
        for(int i=1;i<intervals.size();i++){
            vector<int>& lastInterval=solution.back();    
            //fetch the last interval from solution
            if(intervals[i][0]<=lastInterval[1]){
                //if next interval overlaps with it then update the lastInterval
                lastInterval[1]=max(lastInterval[1],intervals[i][1]);
            }
            else{
                //if next intervals doesn't overlaps with the last interval in solution
                //push this interval in solution
                solution.push_back(intervals[i]);
            }
        }
        return solution;
    }
};