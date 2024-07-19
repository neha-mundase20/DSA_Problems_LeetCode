class Solution {
public:

    bool isGardenFlowered(int m, int k, const vector<int>& bloomDay, int waitDays) {
        int bouquets=0;
        int flowers=0;

        for (int day:bloomDay) {
            if (day<=waitDays) {
                flowers++;
                if (flowers==k) {
                    bouquets++;
                    flowers=0;
                    if(bouquets==m) {
                        return true;
                    }
                }
            } else{
                flowers=0;
            }
        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<(long long)m*k){
            //m*k is required number of flowers to prepare the bouquet
            return -1;
        }

        int waitDays=0;

        //Minimum number of waiting days
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        //Maximum number of waiting days
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int mid=0;

        while(low<=high){
            mid=low+((high-low)/2);

            if(isGardenFlowered(m,k,bloomDay,mid)==true){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};